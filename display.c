#include "display.h"
#include "oled.h"

void display_year(unsigned char a,unsigned char flag)//flag为1 时，显示数据，0时对应清除屏幕
{
	if(flag)
	{
	OLED_ShowChar(24, 0, a/10+'0',16);//年	
	OLED_ShowChar(32, 0, a%10+'0',16);
	}
	else
	{
	//清除年位
	OLED_ClearChar(24, 0);
	}	
}
void display_month(unsigned char a,unsigned char flag)
{
	if(flag)
	{
	OLED_ShowChar(56, 0, a/10+'0',16);//月
	OLED_ShowChar(64, 0, a%10+'0',16);
	}
	else
	{
	//清除月位
	OLED_ClearChar(56, 0);
	}
}
void display_day(unsigned char a,unsigned char flag)
{
	if(flag)
	{
	OLED_ShowChar(88, 0, a/10+'0',16);//日
	OLED_ShowChar(96, 0, a%10+'0',16);
	}
	else
	{
	//清除日位
	OLED_ClearChar(88, 0);
	}
}
void display_hour(unsigned char a,unsigned char flag)
{
	if(flag)
	{
	OLED_ShowChar(20, 3, a/10+'0',16);//时
	OLED_ShowChar(28, 3, a%10+'0',16);
	}
	else
	{
	//清除时位
	OLED_ClearChar(20, 3);
	}
}
void display_min(unsigned char a,unsigned char flag)
{
	if(flag)
	{
	OLED_ShowChar(56, 3, a/10+'0',16);//分
	OLED_ShowChar(64, 3, a%10+'0',16);
	}
	else
	{
	//清除分位
	OLED_ClearChar(56, 3);
	}
}
void display_sec(unsigned char a,unsigned char flag)
{
	if(flag)
	{
	OLED_ShowChar(92, 3, a/10+'0',16);//秒
	OLED_ShowChar(100, 3, a%10+'0',16);
	}
	else
	{
	//清除秒位
	OLED_ClearChar(92, 3);
	}
}

void display_tmp(unsigned char a,unsigned char flag)
{
	if(flag)
	{
	OLED_ShowNum(38,6,a,3,16);//显示温度
	}
	else
	{
	//清除温度位
	OLED_ClearChar(38, 6);
	OLED_ClearChar(46, 6);
	}
}

void display_shidu(unsigned char a,unsigned char flag)
{
	if(flag)
	{
	OLED_ShowNum(104,6,a,3,16);//显示湿度

	}
	else
	{
	//清除湿度位
	OLED_ClearChar(104, 6);
	OLED_ClearChar(112, 6);
	}
}
void display(unsigned char a,unsigned char flag,unsigned char shift)
{
	switch(shift)
	{
	case 0:	display_sec(a,flag); break;
	case 1:	display_min(a,flag);  break;
	case 2:	display_hour(a,flag);  break;
	case 3:	display_day(a,flag);  break;
	case 4:	display_month(a,flag);  break;
	case 5:	display_year(a,flag); break;
	default : break;
	}

}

void display2(unsigned char a,unsigned char flag,unsigned char shift)
{
	switch(shift)
	{
	case 0:	display_tmp(a,flag); break;
	case 1:	display_shidu(a,flag);  break;
	default : break;
	}

}