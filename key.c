#include "key.h"
#include "oled.h"
unsigned int KEY_Scan(void)
{
	if(key_run == 0)//run������
		{	
			while(key_run==0);//�ȴ������ɿ�
			delay_ms(5);//��ʱ����	
			return 1;
		}
	if(key_shift == 0)//shift������
		{	
			while(key_shift==0);//�ȴ������ɿ�
			delay_ms(5);//��ʱ����	
			return 2;
		}
	if(key_beep == 0)//beep������
		{	
			while(key_beep==0);//�ȴ������ɿ�
			delay_ms(5);//��ʱ����	
			return 3;
		}
	if(key_up == 0)//up������
		{	
			while(key_up==0);//�ȴ������ɿ�
			delay_ms(5);//��ʱ����	
			return 4;
		}
	if(key_down == 0)//down������
		{	
			while(key_down==0);//�ȴ������ɿ�
			delay_ms(5);//��ʱ����	
			return 5;
		}

		return 0;
}