/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
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
#define RED_0_Pin GPIO_PIN_10
#define RED_0_GPIO_Port GPIOB
#define GREEN_0_Pin GPIO_PIN_11
#define GREEN_0_GPIO_Port GPIOB
#define YELLOW_0_Pin GPIO_PIN_12
#define YELLOW_0_GPIO_Port GPIOB
#define RED_1_Pin GPIO_PIN_13
#define RED_1_GPIO_Port GPIOB
#define GREEN_1_Pin GPIO_PIN_14
#define GREEN_1_GPIO_Port GPIOB
#define YELLOW_1_Pin GPIO_PIN_15
#define YELLOW_1_GPIO_Port GPIOB
#define g_val_2_Pin GPIO_PIN_14
#define g_val_2_GPIO_Port GPIOA
#define LED_BLINK_Pin GPIO_PIN_15
#define LED_BLINK_GPIO_Port GPIOA
#define b_val_1_Pin GPIO_PIN_3
#define b_val_1_GPIO_Port GPIOB
#define c_val_1_Pin GPIO_PIN_4
#define c_val_1_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_7
#define EN0_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_8
#define EN1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
