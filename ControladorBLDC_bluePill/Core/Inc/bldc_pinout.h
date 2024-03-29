/**
 * @file bldc_pinout.h
 * @brief Header file for BLDC motor controller pinout definitions.
 *
 * This file contains the definitions of the GPIO pins used by the BLDC motor controller.
 * It provides a hardware abstraction layer that makes the controller code portable
 * across different hardware platforms.
 */

#ifndef BLDC_PINOUT_H
#define BLDC_PINOUT_H


/***************************************
 * Hardware abstraction layer selection
 ***************************************/

    #define STM32_HAL

/*************************************** 
 * Funtionality configurartions
 ***************************************/

    #define DEBUG_MSG
    //#define BACKWARDS

/***************************************
 * Pinout definition 
 ***************************************/


#ifdef STM32_HAL

/**-----------------------------------
 * STM32 HAL platform pin definitions.
 -----------------------------------**/

    #define HALL_A_PIN      GPIO_PIN_4      /**< Hall sensor A pin */
    #define HALL_B_PIN      GPIO_PIN_3      /**< Hall sensor B pin */
    #define HALL_C_PIN      GPIO_PIN_15     /**< Hall sensor C pin */

    #define H_A_PIN     GPIO_PIN_9          /**< High side transistor pin for phase A */
    #define H_B_PIN     GPIO_PIN_1          /**< High side transistor pin for phase B */
    #define H_C_PIN     GPIO_PIN_7          /**< High side transistor pin for phase C */

    #define L_A_PIN     GPIO_PIN_8          /**< Low side transistor pin for phase A */
    #define L_B_PIN     GPIO_PIN_10         /**< Low side transistor pin for phase B */
    #define L_C_PIN     GPIO_PIN_0          /**< Low side transistor pin for phase C */


    #define THROTTLE_PIN    GPIO_PIN_3      /**< Throttle input pin */
    #define VOLTAGE_PIN     GPIO_PIN_6     	/**< Voltage measurement pin */

	//#define CURRENT_PIN     GPIO_PIN_12     /**< Current measurement pin */

	#define CURRENT_1_PIN	GPIO_PIN_2
	#define CURRENT_2_PIN	GPIO_PIN_1
	#define CURRENT_3_PIN	GPIO_PIN_0

    #define LED_PIN     GPIO_PIN_5          /**< LED pin */

    #define     STM_HALL_A_PORT     GPIOB
    #define     STM_HALL_B_PORT     GPIOB
    #define     STM_HALL_C_PORT     GPIOA

    #define     STM_H_A_PORT    GPIOA
    #define     STM_H_B_PORT    GPIOB
    #define     STM_H_C_PORT    GPIOA

    #define     STM_L_A_PORT    GPIOA
    #define     STM_L_B_PORT    GPIOA
    #define     STM_L_C_PORT    GPIOB

    #define     STM_THROTTLE_PORT   GPIOA
    #define     STM_VOLTAGE_PORT    GPIOA

	//#define     STM_CURRENT_PORT    GPIOB

	#define 	STM_CURRENT_1_PIN	GPIOA
	#define 	STM_CURRENT_2_PIN	GPIOA
	#define 	STM_CURRENT_3_PIN	GPIOA

    #define 	LED_PORT    GPIOC

    #define     STM_THROTTLE_HANDLER    	&hadc1
    #define     STM_VOLTAGE_HANDLER     	&hadc1
    #define     STM_CURRENT_1_HANDLER     	&hadc1
	#define     STM_CURRENT_2_HANDLER     	&hadc1
	#define     STM_CURRENT_3_HANDLER     	&hadc1

    #define     STM_PWM_A_HANDLER   	&htim1
	#define     STM_PWM_B_HANDLER_L   	&htim1
	#define     STM_PWM_B_HANDLER_H   	&htim3
    #define     STM_PWM_C_HANDLER   	&htim3

    #define     STM_UART_HANDLER    &huart1

#elif RASPBERRY_PICO

/**-----------------------------------
 * Raspberry Pi Pico platform pin definitions.
 -----------------------------------**/

    #define HALL_A_PIN      13              /**< Hall sensor A pin */
    #define HALL_B_PIN      14              /**< Hall sensor B pin */
    #define HALL_C_PIN      15              /**< Hall sensor C pin */

    #define H_A_PIN     16                  /**< High side transistor pin for phase A */
    #define H_B_PIN     18                  /**< High side transistor pin for phase B */
    #define H_C_PIN     20                  /**< High side transistor pin for phase C */

    #define L_A_PIN     17                  /**< Low side transistor pin for phase A */
    #define L_B_PIN     19                  /**< Low side transistor pin for phase B */
    #define L_C_PIN     21                  /**< Low side transistor pin for phase C */

    #define THROTTLE_PIN    28              /**< Throttle input pin */

    #define VOLTAGE_PIN     27              /**< Voltage measurement pin */
    #define CURRENT_PIN     26              /**< Current measurement pin */

    #define PICO_PWM_A_HANDLER      0       /**< Number of slice for timer A */
    #define PICO_PWM_B_HANDLER      1       /**< Number of slice for timer B */
    #define PICO_PWM_C_HANDLER      2       /**< Number of slice for timer C */

    #define LED_PIN     13                  /**< LED pin */

#elif ARDUINO

/**-----------------------------------
 * Arduino platform pin definitions.
 -----------------------------------**/

#elif ESP32

/**-----------------------------------
 * Esp32 on Arduino IDE platform pin definitions.
 -----------------------------------**/

#endif


#endif //BLDC_PINOUT_H
