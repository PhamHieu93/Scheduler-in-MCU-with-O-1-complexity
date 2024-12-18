/*
 * scheduler.h
 *
 *  Created on: Nov 4, 2024
 *      Author: 84868
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_



#endif /* INC_SCHEDULER_H_ */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sTask{
	void (*pTask)(void);
	int Delay;
    int Period;
	int RunMe;
	uint8_t TaskID;
	struct sTask* next;
} sTask;


#define SCH_MAX_TASKS 20
#define TIME_CYCLE 10;
extern int current_index;
extern int time_count;
extern int timestamp;
extern int delete_signal;
extern int dlete_index;
void SCH_Init(void);
void SCH_Update(void);
uint8_t SCH_Add_Task(void (* pFunction)(), unsigned int DELAY, unsigned int PERIOD);
uint8_t SCH_Delete_Task(const uint8_t id);
void SCH_Dispatch_Tasks(void);
