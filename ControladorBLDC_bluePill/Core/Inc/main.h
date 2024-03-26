
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Isense_3_Pin GPIO_PIN_0
#define Isense_3_GPIO_Port GPIOA
#define Isense_2_Pin GPIO_PIN_1
#define Isense_2_GPIO_Port GPIOA
#define Isense_1_Pin GPIO_PIN_2
#define Isense_1_GPIO_Port GPIOA
#define Thottle_Pin GPIO_PIN_3
#define Thottle_GPIO_Port GPIOA
#define Vsense_Pin GPIO_PIN_6
#define Vsense_GPIO_Port GPIOA
#define C_H_Pin GPIO_PIN_7
#define C_H_GPIO_Port GPIOA
#define C_L_Pin GPIO_PIN_0
#define C_L_GPIO_Port GPIOB
#define B_H_Pin GPIO_PIN_1
#define B_H_GPIO_Port GPIOB
#define A_L_Pin GPIO_PIN_8
#define A_L_GPIO_Port GPIOA
#define A_H_Pin GPIO_PIN_9
#define A_H_GPIO_Port GPIOA
#define B_L_Pin GPIO_PIN_10
#define B_L_GPIO_Port GPIOA
#define Hall_C_Pin GPIO_PIN_15
#define Hall_C_GPIO_Port GPIOA
#define Hall_B_Pin GPIO_PIN_3
#define Hall_B_GPIO_Port GPIOB
#define Hall_A_Pin GPIO_PIN_4
#define Hall_A_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
