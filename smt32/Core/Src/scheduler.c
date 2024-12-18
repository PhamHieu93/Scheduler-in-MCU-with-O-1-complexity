/*
 * scheduler.c
 *
 *  Created on: Nov 4, 2024
 *      Author: 84868
 */


#include "scheduler.h"
#include "main.h"
#include "normal_run.h"

int time_count = 0;
int current_index = 0;
sTask SCH_tasks_G[SCH_MAX_TASKS];
sTask* head = NULL;
int timestamp = 0;
int delete_signal = 0;
int delete_index = -1;

void SCH_Init(void)
{
	while (current_index != 0)
	{
		SCH_Delete_Task(0);
	}
	current_index = 0;
	time_count = 0;
}

void SCH_Update(void) //Function like timer run
{
	if(head != NULL)
	{
		if(head->pTask)
		{
			if(head->Delay <= 0)
			{
				head->RunMe = 1;
				if(head->Period) head->Delay = head->Period;
				else
				{
					delete_signal = 1;
					delete_index = head->TaskID;
				}
				//else SCH_Delete_Task(head->TaskID);
			}
			else head->Delay = head->Delay - 1;
		}
	}
}

uint8_t SCH_Add_Task(void (* pFunction)(), unsigned int DELAY, unsigned int PERIOD)
{
	if (current_index >= SCH_MAX_TASKS) return -1;

	sTask* newTask = (sTask*)malloc(sizeof(sTask));
	if(newTask == NULL) return -1;

		newTask->pTask = pFunction;
	    newTask->Delay = DELAY;
	    newTask->Period = PERIOD;
	    newTask->TaskID = current_index;
	    newTask->next = NULL;

	if (head == NULL || head->Delay > DELAY)
	{
		newTask->next = head;
		head = newTask;
	}
	else
	{
		sTask* current= head;
		while(current->next != NULL && current->next->Delay <= DELAY)
		{
			current = current->next;
		}
		newTask->next = current->next;
		current->next = newTask;
	}
	current_index++;
	return newTask->TaskID;
}
void SCH_Dispatch_Tasks(void)
{
	if(head != NULL && head->RunMe)
	{
		head->pTask();
		head->RunMe = 0;

		// Decrease the delay of other task
		sTask* current = head;
		current = current->next;
		while(current != NULL)
		{
				if(current->Delay > 0)
				{
					current->Delay = current->Delay - time_count;
					if (current->Delay < 0) current->Delay = 0;
				}
				current = current->next;
		}

		// Reset time_count
		time_count = 0;

		// Remove the head node
		sTask* temp = head;
		head = head->next;

		//Change the place base on DELAY
		if(head == NULL || temp->Delay <= head->Delay) // compare with the first node
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			sTask* current_other = head; //compare with the second ->
			while(current_other->next != NULL && current_other->next->Delay <= temp->Delay)
			{
				current_other = current_other->next;
			}
			temp->next = current_other->next;
			current_other->next = temp;
		}
		//printf("Task with ID: %d reinserted with Delay: %d\n", temp->TaskID, temp->Delay);

		// Delete when period = 0
		if(delete_signal)
		{
			SCH_Delete_Task(delete_index);
			delete_signal = 0;
			delete_index = -1;
		}
	}
}

uint8_t SCH_Delete_Task(const uint8_t id)
{
	// If no task in array or taskID invalid, return -1
	sTask* current = head;
	sTask* previous = NULL;
	while(current != NULL)
	{
		if(current->TaskID == id)
		{
			if(previous == NULL) head = current->next; // delete node in head
			else previous->next = current->next; // move the node to the current-> next and delete current node
			free(current);
			return 0; // success
		}
		previous = current;
		current = current->next;
	}
	return -1; // fail
}
