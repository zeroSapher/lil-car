#include "stm32f10x.h"                  // Device header

/*--------------------------------------------
PA6   1_1
PA7   1_2
PB0   1_3
PB1   1_4
---------------------------------------------*/

void PWM2_Init(void)
{
	//����ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);     			  //ʹ�ܶ�ʱ��4
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);      				//AFIO���ù���ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOB  ,ENABLE);  
	
	//���ø�����Ϊ�����������
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_6|GPIO_Pin_7;	       //TIM1_CH1/CH2
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_0|GPIO_Pin_1;	       //TIM3_CH3/CH4
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	//ʱ����Ԫ
	TIM_InternalClockConfig(TIM4);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 2000-1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72-1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);

	
	//CCR����Ƚ���
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;		//CCR
	
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	
	//ʹ��
	TIM_Cmd(TIM3, ENABLE);
}



void PWM_SetCompare1_1(uint16_t Compare)
{
	TIM_SetCompare1(TIM3, Compare);
}
void PWM_SetCompare1_2(uint16_t Compare)
{
	TIM_SetCompare2(TIM3, Compare);
}
void PWM_SetCompare1_3(uint16_t Compare)
{
	TIM_SetCompare3(TIM3, Compare);
}
void PWM_SetCompare1_4(uint16_t Compare)
{
	TIM_SetCompare4(TIM3, Compare);
}

