#include "stm32f10x.h"                  // Device header

/*--------------------------------------------
PB6   1_1
PB7   1_2
PB8   1_3
PB9   1_4
---------------------------------------------*/

void PWM1_Init(void)
{
	//开启时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);     			  //使能定时器4
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);      				//AFIO复用功能时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  ,ENABLE);  
	
	//GPIOA1引脚
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;	       //TIM4_CH1/CH2/CH3/CH4
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	//时基单元
	TIM_InternalClockConfig(TIM4);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 2000-1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72-1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure);

	
	//CCR捕获比较器
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;		//CCR
	
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	
	//使能
	TIM_Cmd(TIM4, ENABLE);
}



//void PWM_SetCompare1_1(uint16_t Compare)
//{
//	TIM_SetCompare1(TIM4, Compare);
//}
//void PWM_SetCompare1_2(uint16_t Compare)
//{
//	TIM_SetCompare2(TIM4, Compare);
//}
//void PWM_SetCompare1_3(uint16_t Compare)
//{
//	TIM_SetCompare3(TIM4, Compare);
//}
//void PWM_SetCompare1_4(uint16_t Compare)
//{
//	TIM_SetCompare4(TIM4, Compare);
//}

