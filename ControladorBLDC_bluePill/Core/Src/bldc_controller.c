#include "bldc_controller.h"

bldc_t bldc = {0};  // Initialize all fields to zero

// Interrupts
volatile uint8_t adc_conv_completed = 1;

bldc_return_state get_halls(unsigned int * hall){
	unsigned int hallCounts[] = {0, 0, 0};

	// Read all the Hall pins repeatedly and tally the results
	for (unsigned int i = 0; i < HALL_OVERSAMPLE; i++) {
		int h_a, h_b, h_c;

		gpio_read(&h_a, BLDC_HALL_A_PORT, BLDC_HALL_A_PIN);
		gpio_read(&h_b, BLDC_HALL_B_PORT, BLDC_HALL_B_PIN);
		gpio_read(&h_c, BLDC_HALL_C_PORT, BLDC_HALL_C_PIN);

		hallCounts[0] += h_a;
		hallCounts[1] += h_b;
		hallCounts[2] += h_c;
	}

	*hall = 0;

	// If votes >= threshold, set the corresponding bit to 1
	if (hallCounts[0] > HALL_OVERSAMPLE / 2)
		*hall |= (1 << 0);
	if (hallCounts[1] > HALL_OVERSAMPLE / 2)
		*hall |= (1 << 1);
	if (hallCounts[2] > HALL_OVERSAMPLE / 2)
		*hall |= (1 << 2);

	return ERROR_OK;
}

bldc_return_state process_halls(){
    for(unsigned int j = 0; j < 200; j++)
    {
	    unsigned int hall;
		get_halls(&hall);
	    write_pd_table(hall, bldc.throttle_pwm);
    }
    bldc.throttle_pwm = 0;
    return ERROR_OK;
}

bldc_return_state writePhases(uint16_t ah, uint16_t bh, uint16_t ch, uint16_t al, uint16_t bl, uint16_t cl){
	set_pwm(ah, bh, ch, al, bl, cl);
	return ERROR_OK;
}

bldc_return_state write_pd_table(unsigned int halls, unsigned int duty){
	if(duty > 255){
		duty = 255;
	}
	if(duty < 40){
		bldc.throttle_pwm = 0;
		duty = 0;
		halls = 8;
	}

	unsigned int complement = 255 - duty - 6;
	
	switch(halls){
		case 1: // Case 001
		writePhases(duty, 0, 0, complement, 0, 255);
		break;
		case 2: // Case 010
		writePhases(0, 0, duty, 0, 255, complement);
		break;
		case 3: // Case 011
		writePhases(duty, 0, 0, complement, 255, 0);
		break;
		case 4: // Case 100
		writePhases(0, duty, 0, 255, complement, 0);
		break;
		case 5: // Case 101
		writePhases(0, duty, 0, 0, complement, 255);
		break;
		case 6: // Case 110
		writePhases(0, 0, duty, 255, 0, complement);
		break;
		default: // Case 000 or error
		writePhases(0, 0, 0, 255, 255, 255);
	}
	return ERROR_OK;
}


bldc_return_state read_throttle(int* data){
	int throttle_adc;
	adc_read(&throttle_adc, BLDC_THROTTLE_HANDLER, BLDC_THROTTLE_PIN);

	throttle_adc = (throttle_adc - THROTTLE_LOW) * 255;
	if(throttle_adc < 0){
		throttle_adc *= -1;
	}

	throttle_adc /= (THROTTLE_HIGH - THROTTLE_LOW);
	bldc.throttle_pwm = throttle_adc;

    if (throttle_adc >= 255) // Bound the output between 0 and 255
        bldc.throttle_pwm = 255;

    if (throttle_adc <= 0)
        bldc.throttle_pwm = 0;

    *data = bldc.throttle_pwm;
    return ERROR_OK;
}

bldc_return_state read_voltage(int* data){
	adc_read(data, BLDC_VOLTAGE_HANDLER, BLDC_VOLTAGE_PIN);
	bldc.voltage_mv = *data * VOLTAGE_SCALING;
	/*Scale and limits*/
	return ERROR_OK;
}

bldc_return_state read_current_1(int* data){
	adc_read(data, BLDC_CURRENT_1_HANDLER, BLDC_CURRENT_1_PIN);
	bldc.current_1_ma = *data * CURRENT_SCALING;
	/*Scale and limits*/
	/*Function to protect over current*/
	return ERROR_OK;
}

bldc_return_state read_current_2(int* data){
	adc_read(data, BLDC_CURRENT_2_HANDLER, BLDC_CURRENT_2_PIN);
	bldc.current_2_ma = *data * CURRENT_SCALING;
	/*Scale and limits*/
	/*Function to protect over current*/
	return ERROR_OK;
}

bldc_return_state read_current_3(int* data){
	adc_read(data, BLDC_CURRENT_3_HANDLER, BLDC_CURRENT_3_PIN);
	bldc.current_3_ma = *data * CURRENT_SCALING;
	/*Scale and limits*/
	return ERROR_OK;
}

void pwm_irq() {
	start_adc_irq();
}

void adc_irq() {
	//HAL_ADC_Stop(BLDC_THROTTLE_HANDLER);
	int throttle = 0, voltage = 0, current_1 = 0, current_2 = 0, current_3 = 0;
	read_throttle(&throttle);
	read_voltage(&voltage);
	read_current_1(&current_1);
	read_current_2(&current_2);
	read_current_3(&current_3);

	unsigned int halls;
	get_halls(&halls);
	write_pd_table(halls, bldc.throttle_pwm);

	start_tim_irq();
}

bldc_return_state gpio_read(int* data, GPIO_TypeDef* port, uint16_t pin) {
	*data = HAL_GPIO_ReadPin(port, pin);
	return ERROR_OK;
}


bldc_return_state adc_read(int* data, ADC_HandleTypeDef* port, uint16_t pin) {
	*data = HAL_ADC_GetValue(port);
	return ERROR_OK;
}

bldc_return_state set_pwm(uint16_t ah, uint16_t bh, uint16_t ch, uint16_t al, uint16_t bl, uint16_t cl){
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(BLDC_PWM_A_HANDLER, TIM_CHANNEL_2, 200);
	__HAL_TIM_SET_COMPARE(BLDC_PWM_A_HANDLER, TIM_CHANNEL_1, 255 - al);
	__HAL_TIM_SET_COMPARE(BLDC_PWM_B_HANDLER_H, TIM_CHANNEL_4, bh);
	__HAL_TIM_SET_COMPARE(BLDC_PWM_B_HANDLER_L, TIM_CHANNEL_3, 255 - bl);
	__HAL_TIM_SET_COMPARE(BLDC_PWM_C_HANDLER, TIM_CHANNEL_2, ch);
	__HAL_TIM_SET_COMPARE(BLDC_PWM_C_HANDLER, TIM_CHANNEL_3, 255 - cl);
	return ERROR_OK;
}

bldc_return_state start_adc_irq(){
	//HAL_ADC_Stop(BLDC_THROTTLE_HANDLER);
	//if(adc_conv_completed == 1){
	if(HAL_ADC_Start_IT(BLDC_THROTTLE_HANDLER) != HAL_OK){
		Error_Handler();
	}
		//adc_conv_completed = 0;
	//}
	return ERROR_OK;
}


bldc_return_state start_tim_irq(){
	//HAL_TIM_PWM_Stop(BLDC_PWM_A_HANDLER, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start_IT(BLDC_PWM_A_HANDLER, TIM_CHANNEL_2);
	return ERROR_OK;
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == BLDC_PWM_A_HANDLER->Instance){
		pwm_irq();
	}
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc){
	if(hadc->Instance == BLDC_THROTTLE_HANDLER->Instance){
		adc_irq();
	}
}
