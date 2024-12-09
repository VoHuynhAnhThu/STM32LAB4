#include "main.h"

#define TIMER_CYCLE 10; // Notes: Moi khi cai lai TIM2 trong ioc thi phai set cai nay lai
int timer0_counter = 0;
int timer1_counter = 0;
int timer0_flag = 1;
int timer1_flag = 1;

void setTimer0(int duration){
	timer0_counter = duration / TIMER_CYCLE ;
	timer0_flag = 0;
}
int getTimer0_flag(void) {
	return timer0_flag;
}

void setTimer1(int duration){
	timer1_counter = duration / TIMER_CYCLE ;
	timer1_flag = 0;
}
int getTimer1_flag(void) {
	return timer1_flag;
}

void timer_run(void){
	if(timer0_counter > 0){
		timer0_counter--;
		if(timer0_counter == 0) timer0_flag = 1;
	}

	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter == 0) timer1_flag = 1;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {
	if(htim->Instance == TIM2){
		/*
		 * Testing
		 if (HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin) == GPIO_PIN_SET)
			  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
		  else
			  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
		 */
		timer_run();
		SCH_Update();
	}
}
