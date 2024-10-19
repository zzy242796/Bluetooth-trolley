#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "HC05.h"


int8_t Speed;
uint8_t RxSTA = 1;
char RxData[100] = "None";

int main(void)
{
	Motor_Init();
	OLED_Init();
	HC05_Init();
	OLED_ShowString(1, 1, "RxData:");
	OLED_ShowString(1, 9, RxData);

	
	//OLED_ShowString(1, 1, "Speed");
	
	
	
	while (1)
	{
		clearString(RxData);
		
		HC05_GetData(RxData);
		if (RxSTA == 0)
		{
			OLED_Clear();
			
			OLED_ShowString(1, 1, "RxData:");
			OLED_ShowString(1, 9, RxData);
			
			if(RxData[0]=='E')
			{
				forward(100,100);
			}
			
		    if(RxData[0]=='A')
			{
				back(100,100);
			}
			
		    if(RxData[0]=='G')
			{
				turn_right(80,80);
			}
			
			if(RxData[0]=='C')
			{
				turn_lift(80,80);
			}
			
			if(RxData[0]=='Z')
			{
				forward(0,0);
			}
			
			if(RxData[0]=='D')
			{
				forward(100,40);
			}
			
			if(RxData[0]=='F')
			{
				forward(40,100);
			}
			
			if(RxData[0]=='H')
			{
				back(40,100);
			}
		
			if(RxData[0]=='B')
			{
				back(100,40);
			}
		
			RxSTA = 1;
		}
	}
}
