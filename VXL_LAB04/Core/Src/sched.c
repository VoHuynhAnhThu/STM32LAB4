/*
 * sched.c
 *
 *  Created on: Oct 30, 2021
 *      Author: DELL
 */
#include "sched.h"
#include "main.h"

unsigned char ERROR_CODE;
task_struct SCH_tasks_G[SCH_MAX_TASKS];  // Mảng các tác vụ

void SCH_Init(void) {
	// Initialization
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; ++i) {
		SCH_Delete_Task(i);
	}

	//Con code: Trang 15/23 pdf
	ERROR_CODE = 0;
}

// Định nghĩa hàm SCH_Update
void SCH_Update(void) {
    unsigned char Index;
    // Lưu ý: Tính toán là *TICKS* (không phải milliseconds)
    for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
        // Kiểm tra xem có tác vụ nào tại vị trí này không
        if (SCH_tasks_G[Index].taskId) {
            if (SCH_tasks_G[Index].delay == 0) {
                // Tác vụ đã đến lúc thực thi
                SCH_tasks_G[Index].run_me += 1;
                if (SCH_tasks_G[Index].period) {
                    // Lên lịch các tác vụ định kỳ để chạy lại
                    SCH_tasks_G[Index].delay = SCH_tasks_G[Index].period;
                }
            } else {
                // Tác vụ chưa đến lúc chạy, giảm trễ
                SCH_tasks_G[Index].delay -= 1;
            }
        }
    }
}

unsigned char SCH_Add_Task(void (*funcPtr)(void), unsigned int delay, unsigned int period) {
	unsigned char idx = 0;
	// Find empty slot in the array
	// Trong pdf ghi la .funcPtr != 0 ? https://stackoverflow.com/questions/3825668/checking-for-null-pointer-in-c-c
	while ((taskArr[idx].funcPtr != NULL) && (idx < SCH_MAX_TASKS))
		++idx;

	// Have we reached the end of the l i s t ?
	if (idx == SCH_MAX_TASKS) {
		// Task l i s t i s f u l l
		// Set the global error variable
		ERROR_CODE = ERROR_SCH_TOO_MANY_TASKS;
		// Also return what cause error
		return SCH_MAX_TASKS;
	} else {
		// initialize new task
		taskArr[idx].funcPtr = funcPtr;
		taskArr[idx].delay = delay;
		taskArr[idx].period = period;
		taskArr[idx].run_me = 0;
		// return position of task ( to allow later deletion )
		return idx;
	}
}

void SCH_UpdateDueTime(void) {
	// Initialization
	unsigned char idx;
	for (idx = 0; idx < SCH_MAX_TASKS; ++idx) {
		// If there is a task at this location
		if(taskArr[idx].funcPtr) {
			// And if the task is due to run
			if(taskArr[idx].delay == 0) {
				++taskArr[idx].run_me;

				// Chua hieu function nay
				if(taskArr[idx].period)
					taskArr[idx].delay = taskArr[idx].period;
			} else {
				// Else the task is not due to run => Delay--
				--taskArr[idx].delay;
			}
		}
	}
}

void SCH_Dispatch_Task(void) {
	for (unsigned char idx = 0; idx < SCH_MAX_TASKS; ++idx) {
		if (taskArr[idx].run_me > 0) {
			taskArr[idx].funcPtr(); // Dispatches (runs) the task
			--taskArr[idx].run_me; // Reset the flag

			// − i f thi s i s a ’one shot ’ task , remove i t from the array
			// y nghia cua bien period?
			if (taskArr[idx].period == 0)
				SCH_Delete_Task(idx);
		}
	}

	SCH_Report_Status();
	SCH_Sleep();
}

unsigned char SCH_Delete_Task(const tByte TASK_IDX) {
	if (taskArr[TASK_IDX].funcPtr == NULL) {
		ERROR_CODE = ERROR_SCH_CANNOT_DELETE_TASK;
		return RETURN_CODE_ERROR_DELETE;
	} else {
		taskArr[TASK_IDX].funcPtr = 0x0000;
		taskArr[TASK_IDX].delay = 0;
		taskArr[TASK_IDX].period = 0;
		taskArr[TASK_IDX].run_me = 0;
		return RETURN_CODE_SUCCESS_DELETE;
	}
}

void SCH_Sleep(void) {
	// TODO: Doc manual cua MCU de viet
}

unsigned char lastError = 0;
unsigned int errorTimer_tick = 0;
void SCH_Report_Status(void) {
#ifdef SCH_ALLOW_REPORT_ERROR // define in main.h for example
	// Check for new error
	if (ERROR_CODE != lastError) {
		// Assume Led active-low
		// define in main.h for example
		Led_Error_Port = 255 - ERROR_CODE;

		lastError = ERROR_CODE;

		// giong kieu tranh alert lien tuc
		errorTimer_tick = (ERROR_CODE != 0) ? 60000 : 0; // unit: ticks
	} else {
		if (errorTimer_tick == 0)
			ERROR_CODE = 0; // reset
		else
			--errorTimer_tick;
	}
#endif
}
