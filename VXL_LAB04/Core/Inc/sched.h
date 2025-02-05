#ifndef INC_SCHED_H_
#define INC_SCHED_H_

#include <stdint.h>

typedef uint8_t tByte;

typedef struct {
	// Function pointer, must be a void void function
	void (*funcPtr)(void);
	uint32_t delay; // unit: ticks. Giống kiểu setTimeout
	uint32_t period; // unit: ticks. Giống kiểu setInterval
	uint8_t run_me;
	uint32_t taskId;
} task_struct;

// Configuration
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0
task_struct taskArr[SCH_MAX_TASKS];
#define ERROR_SCH_TOO_MANY_TASKS 1
#define ERROR_SCH_CANNOT_DELETE_TASK 2
#define RETURN_CODE_ERROR_DELETE 3
#define RETURN_CODE_SUCCESS_DELETE 4

// Exporting variable
extern unsigned char ERROR_CODE; // unsigned char = 2^8, for output led

// Exporting Function
void SCH_Init(void);
unsigned char SCH_Add_Task(void (*funcPtr)(void), unsigned int delay, unsigned int period);
void SCH_UpdateDueTime(void);
void SCH_Dispatch_Task(void);
unsigned char SCH_Delete_Task(const tByte TASK_IDX);
void SCH_Sleep(void);
void SCH_Report_Status(void);
void SCH_Update(void);  // Khai báo hàm SCH_Update

#endif /* INC_SCHED_H_ */
