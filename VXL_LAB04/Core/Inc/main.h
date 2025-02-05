/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#define Led_Test_System_Pin GPIO_PIN_1
#define Led_Test_System_GPIO_Port GPIOA
#define Led_Test_Timer_Pin GPIO_PIN_2
#define Led_Test_Timer_GPIO_Port GPIOA
#define Dot_Pin GPIO_PIN_4
#define Dot_GPIO_Port GPIOA
#define Led_5_Pin GPIO_PIN_5
#define Led_5_GPIO_Port GPIOA
#define En0_Pin GPIO_PIN_6
#define En0_GPIO_Port GPIOA
#define En1_Pin GPIO_PIN_7
#define En1_GPIO_Port GPIOA
#define Led7_a_Pin GPIO_PIN_0
#define Led7_a_GPIO_Port GPIOB
#define Led7_b_Pin GPIO_PIN_1
#define Led7_b_GPIO_Port GPIOB
#define Led7_c_Pin GPIO_PIN_2
#define Led7_c_GPIO_Port GPIOB
#define En2_Pin GPIO_PIN_8
#define En2_GPIO_Port GPIOA
#define En3_Pin GPIO_PIN_9
#define En3_GPIO_Port GPIOA
#define Led7_d_Pin GPIO_PIN_3
#define Led7_d_GPIO_Port GPIOB
#define Led7_e_Pin GPIO_PIN_4
#define Led7_e_GPIO_Port GPIOB
#define Led7_f_Pin GPIO_PIN_5
#define Led7_f_GPIO_Port GPIOB
#define Led7_g_Pin GPIO_PIN_6
#define Led7_g_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
