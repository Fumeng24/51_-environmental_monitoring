#include "key.h"
#include "oled.h"
unsigned int KEY_Scan(void)
{
	if(key_run == 0)//run键按下
		{	
			while(key_run==0);//等待按键松开
			delay_ms(5);//延时消抖	
			return 1;
		}
	if(key_shift == 0)//shift键按下
		{	
			while(key_shift==0);//等待按键松开
			delay_ms(5);//延时消抖	
			return 2;
		}
	if(key_beep == 0)//beep键按下
		{	
			while(key_beep==0);//等待按键松开
			delay_ms(5);//延时消抖	
			return 3;
		}
	if(key_up == 0)//up键按下
		{	
			while(key_up==0);//等待按键松开
			delay_ms(5);//延时消抖	
			return 4;
		}
	if(key_down == 0)//down键按下
		{	
			while(key_down==0);//等待按键松开
			delay_ms(5);//延时消抖	
			return 5;
		}

		return 0;
}