/*
 * normal_run.h
 *
 *  Created on: Oct 22, 2024
 *      Author: 84868
 */

#ifndef INC_NORMAL_RUN_H_
#define INC_NORMAL_RUN_H_



#endif /* INC_NORMAL_RUN_H_ */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "stm32f1xx_hal.h"
extern UART_HandleTypeDef huart2;
extern char data[50];


void normal_run_1();
void normal_run_2();
void red_1();
void green_1();
void yellow_1();
void red_2();
void green_2();
void yellow_2();
void dot_blinky();
