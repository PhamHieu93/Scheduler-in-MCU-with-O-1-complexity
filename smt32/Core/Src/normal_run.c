/*
 * normal_run.c
 *
 *  Created on: Oct 22, 2024
 *      Author: 84868
 */

#include "main.h"
#include "normal_run.h"
#include "scheduler.h"
#include "stm32f1xx_hal.h"

char data[50];
void red_1()
{
	HAL_GPIO_WritePin(GPIOB, RED_0_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, GREEN_0_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, YELLOW_0_Pin, 1);
	HAL_UART_Transmit(&huart2, (uint8_t *)data, sprintf(data, "red1 run at  %d\r\n",timestamp),1000);
}
void green_1()
{
	HAL_GPIO_WritePin(GPIOB, GREEN_0_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, RED_0_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, YELLOW_0_Pin, 1);
	HAL_UART_Transmit(&huart2, (uint8_t *)data, sprintf(data, "green1 run at  %d\r\n",timestamp),1000);

}
void yellow_1()
{
	HAL_GPIO_WritePin(GPIOB, YELLOW_0_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, GREEN_0_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, RED_0_Pin, 1);
	HAL_UART_Transmit(&huart2, (uint8_t *)data, sprintf(data, "yellow1 run at  %d\r\n",timestamp),1000);
}

void red_2()
{
	HAL_GPIO_WritePin(GPIOB, GREEN_1_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, YELLOW_1_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, RED_1_Pin, 0);
	HAL_UART_Transmit(&huart2, (uint8_t *)data, sprintf(data, "red2 run at  %d\r\n",timestamp),1000);

}
void green_2()
{
	HAL_GPIO_WritePin(GPIOB, GREEN_1_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, RED_1_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, YELLOW_1_Pin, 1);
	HAL_UART_Transmit(&huart2, (uint8_t *)data, sprintf(data, "green2 run at  %d\r\n",timestamp),1000);

}
void yellow_2()
{
	HAL_GPIO_WritePin(GPIOB, GREEN_1_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, YELLOW_1_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, RED_1_Pin, 1);
	HAL_UART_Transmit(&huart2, (uint8_t *)data, sprintf(data, "yellow2 run at  %d\r\n",timestamp),1000);
}
void dot_blinky()
{
	HAL_GPIO_TogglePin(LED_BLINK_GPIO_Port, LED_BLINK_Pin);
	HAL_UART_Transmit(&huart2, (uint8_t *)data, sprintf(data, "dotblink run at  %d\r\n",timestamp),1000);
}

