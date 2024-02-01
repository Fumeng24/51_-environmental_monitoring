#include <REGX52.H>
#include "dht11.h"
#include "oled.h"
#include "bmp.h"
#include "DS1302.h"
#include "display.h"
sbit BEEP = P2 ^ 7;
sbit key_menu = P0^5;
sfr ISP_DOWNS=0Xe7;
sbit ISP_SW=P3^0;
char menu = 0;//标志变量
unsigned char time_data[6]={0};//读取DS1302当前时间缓存矩阵
unsigned char bell_data[3]={12,0,0};//闹铃设置界面
unsigned char wenshi_du_data[2]={70,40};//闹铃设置界面
unsigned char bell_flag=0;//闹铃功能开关
unsigned char du_flag=0;//闹铃功能开关
unsigned char bell_onoff=0;//闹铃开关
unsigned char set_run=0;//按键run状态标识符
unsigned char set_bell=0;//按键bell状态标识符
unsigned char set_shift=0;//调时位置标识符
unsigned char set_shift_bell=0;//bell调时位置标识符
unsigned char set_shift_du=0;//du调时位置标识符

void show_time(unsigned char show_data[6])
{

	OLED_ShowChar(24, 0, show_data[0]/10+'0',16);//年	
	OLED_ShowChar(32, 0, show_data[0]%10+'0',16);
	
	OLED_ShowChar(56, 0, show_data[1]/10+'0',16);//月
	OLED_ShowChar(64, 0, show_data[1]%10+'0',16);
	
	OLED_ShowChar(88, 0, show_data[2]/10+'0',16);//日
	OLED_ShowChar(96, 0, show_data[2]%10+'0',16);
	
	OLED_ShowChar(20, 3, show_data[3]/10+'0',16);//时
	OLED_ShowChar(28, 3, show_data[3]%10+'0',16);
		
	OLED_ShowChar(40, 3, ':');
		
	OLED_ShowChar(56, 3, show_data[4]/10+'0',16);//分
	OLED_ShowChar(64, 3, show_data[4]%10+'0',16);
				
	OLED_ShowChar(76, 3, ':');
		
	OLED_ShowChar(92, 3, show_data[5]/10+'0',16);//秒
	OLED_ShowChar(100, 3, show_data[5]%10+'0',16);	
	dht_11_receive();//接收数据 

	OLED_ShowNum(14,6,TH,3,16);//显示温度
	OLED_ShowNum(70,6,RH,3,16);//显示湿度
}


void Time_Date()
{
	/*按键逻辑*/
	switch(KEY_Scan())
	{
		case 1: //按下run键
		set_run=1;
		//读取当前时间并显示
		DS1302_Readtime();
		show_time(time_data);
		while(set_run)
		{
			//对应设置位闪烁
			display(time_data[5-set_shift],0,set_shift);
			display(time_data[5-set_shift],1,set_shift);

			switch(KEY_Scan())
			{
				case 1: DS1302_SetTime(time_data);set_run = 0; break;//第二次按下run键保存时间并退出设置
				case 2: if(set_shift++>4)set_shift=0;break;//移位
				case 3: break;
				case 4: time_data[5-set_shift]++;break;//up
				case 5: time_data[5-set_shift]--;break;//down
				default : break;
			}
		}break;
		case 2:	bell_onoff=0;BEEP=1; break;//关闭闹铃
		case 3: if(set_bell++>2)set_bell=0;//按下闹铃设置键
		//读取当前设定时间并显示
		display_hour(bell_data[0],1);
		display_min(bell_data[1],1);
		display_sec(bell_data[2],1);
		display_tmp(wenshi_du_data[1],1);
		display_shidu(wenshi_du_data[0],1);
		while(set_bell==1)
		{
			//对应设置位闪烁
			display(bell_data[2-set_shift_bell],0,set_shift_bell);
			display(bell_data[2-set_shift_bell],1,set_shift_bell);
			switch(KEY_Scan())
			{
				case 1: bell_flag=!bell_flag;show_bell(bell_flag);break;//开启或关闭闹钟使能
				case 2: if(set_shift_bell++>1)set_shift_bell=0;break;//移动调整位置
				case 3: if(set_bell++>2)set_bell=0;break;//切换时间设置
				case 4: bell_data[2-set_shift_bell]++;break;//up
				case 5: bell_data[2-set_shift_bell]--;break;//down
				default : break;
			}
		}
		while(set_bell==2)
		{
			//对应设置位闪烁
			display2(wenshi_du_data[1-set_shift_du],0,set_shift_du);
			display2(wenshi_du_data[1-set_shift_du],1,set_shift_du);
			switch(KEY_Scan())
			{
				case 1: du_flag=!du_flag;show_du(du_flag);break;//开启或关闭闹钟使能
				case 2: if(set_shift_du++>0)set_shift_du=0;break;//移动调整位置
				case 3: set_bell=0;break;//退出时间设置
				case 4: wenshi_du_data[1-set_shift_du]++;break;//up
				case 5: wenshi_du_data[1-set_shift_du]--;break;//down
				default : break;
			}
		}
		break;
		case 4: break;
		case 5: break;
		default : break;
	};

	DS1302_Readtime();
	show_time(time_data);

	if(bell_data[0]==time_data[3] && bell_data[1]==time_data[4] && bell_data[2]==time_data[5])//触发闹铃
	{
		bell_onoff=1;
	}
	if(TH>=wenshi_du_data[1] || RH>=wenshi_du_data[0])//触发闹铃
	{
		bell_onoff=1;
	}
	if(bell_flag && bell_onoff)
	{
		BEEP=!BEEP;
	}
	if(du_flag && bell_onoff)
	{
		BEEP=!BEEP;
	}
}

void Timer0_Isr(void) interrupt 1
{
		TH0 = (65536-1000)/256;
		TL0 = (65536-1000)%256;

		if(!ISP_SW)ISP_DOWNS=0x60;
}

void Timer0_Init(void)
{
	TMOD = 0x01;
	TH0 = (65536-1000)/256;
	TL0 = (65536-1000)%256;
	ET0 = 1;
	TR0 = 1;
	EA = 1;
}
int main(void)
{
	delay_ms(50);
	Timer0_Init();
	OLED_Init();
	OLED_Clear();
	ds1302_init();
	while(1)
	{
		if(key_menu == 0)//down键按下
		{	
			while(key_menu==0);//等待按键松开
			delay_ms(5);//延时消抖
			OLED_Clear();
			menu++;
			if(menu>2)menu=0;
		}

		if(menu==0)
		{
			OLED_ShowChar(8, 0, 2+'0',16);//年	
			OLED_ShowChar(16, 0, 0+'0',16);
			OLED_ShowCHinese(40,0,0);//年
			OLED_ShowCHinese(72,0,1);//月
			OLED_ShowCHinese(104,0,2);//日
			
			OLED_ShowCHinese(0,6,3);//温
			OLED_ShowChar(40,6, '+',16);
			
			OLED_ShowCHinese(56,6,4);//湿
			OLED_ShowChar(94, 6, '%',16);
			Time_Date();
		}
		if(menu==1)
		{
			OLED_DrawBMP(0,0,128,8,BMP1);  //图片显示(图片显示慎用，生成的字表较大，会占用较多空间，FLASH空间8K以下慎用)
		}
	}
}
