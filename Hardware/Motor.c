#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	PWM_Init();
}

void Motor1_SetSpeed(int8_t Speed)
{
	if (Speed >= 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		PWM_SetCompare1(Speed);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		GPIO_SetBits(GPIOA,GPIO_Pin_5);
		PWM_SetCompare1(-Speed);
	}
}

void Motor2_SetSpeed(int8_t Speed)
{
	if (Speed >= 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
		GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		PWM_SetCompare2(Speed);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_6);
		GPIO_SetBits(GPIOA,GPIO_Pin_7);
		PWM_SetCompare2(-Speed);
	}
}

void forward(int8_t Speed1,int8_t Speed2)
{
	Motor1_SetSpeed(Speed1);
	Motor2_SetSpeed(Speed2);
}

void back(int8_t Speed1,int8_t Speed2)
{
	Motor1_SetSpeed(-Speed1);
	Motor2_SetSpeed(-Speed2);
}

void turn_lift(int8_t Speed1,int8_t Speed2)
{
	Motor1_SetSpeed(Speed1);
	Motor2_SetSpeed(-Speed2);
}

void turn_right(int8_t Speed1,int8_t Speed2)
{
	Motor1_SetSpeed(-Speed1);
	Motor2_SetSpeed(Speed2);
}
