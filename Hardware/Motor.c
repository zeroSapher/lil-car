#include "stm32f10x.h"
#include "PWM.h"
#include "PWM2.h"

void Motor_Init(void)
{
	PWM_Init();
	PWM2_Init();
}

void Motor_Speed1(int num)
{
	if(num>=0){
		PWM_SetCompare1_1(0);
		PWM_SetCompare1_2(num*200);
	}else{
		PWM_SetCompare1_1((0-num)*200);
		PWM_SetCompare1_2(0);
	}
}
void Motor_Speed2(int num)
{
	if(num>=0){
		PWM_SetCompare1_4(0);
		PWM_SetCompare1_3(num*200);
	}else{
		PWM_SetCompare1_4((0-num)*200);
		PWM_SetCompare1_3(0);
	}
}
void Motor_Speed3(int num)
{
	if(num>=0){
		PWM_SetCompare2_1(0);
		PWM_SetCompare2_2(num*200);
	}else{
		PWM_SetCompare2_1((0-num)*200);
		PWM_SetCompare2_2(0);
	}
}
void Motor_Speed4(int num)
{
	if(num>=0){
		PWM_SetCompare2_4(0);
		PWM_SetCompare2_3(num*200);
	}else{
		PWM_SetCompare2_4((0-num)*200);
		PWM_SetCompare2_3(0);
		
	}
}
void Motor_Contrle(int x,int y)
{
	Motor_Speed1((-y)+x);
	Motor_Speed2((-y)-x);
	Motor_Speed3((-y)-x);
	Motor_Speed4((-y)+x);
}
