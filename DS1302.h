#include <REGX52.H>
#include <intrins.h>
#ifndef __DS1302_H
#define __DS1302_H

#define uchar unsigned char
#define uint  unsigned int
extern uchar time_data[6];//??????

//DS1302引脚定义
//sbit RST=P3^7;
//sbit IO=P3^6;
//sbit SCK=P3^5;
sbit RST=P2^0;
sbit IO=P2^1;
sbit SCK=P2^2;
//DS1302地址定义
#define ds1302_sec_add			0x80		//秒数据地址
#define ds1302_min_add			0x82		//分数据地址
#define ds1302_hr_add			0x84		//时数据地址
#define ds1302_date_add			0x86		//日数据地址
#define ds1302_month_add		0x88		//月数据地址
#define ds1302_day_add			0x8a		//星期数据地址
#define ds1302_year_add			0x8c		//年数据地址
#define ds1302_control_add		0x8e		//控制数据地址
#define ds1302_charger_add		0x90 					 
#define ds1302_clkburst_add		0xbe
#define Time_24_Hour    0x00    //24小时制
#define Time_Start     0x00    //开始走时
//DS1302寄存器操作指令定义时间地址
#define ds1302_sec_addr   0x80       //秒
#define ds1302_min_addr   0x82       //分
#define ds1302_hour_addr  0x84       //时
#define ds1302_day_addr   0x86       //日
#define ds1302_month_addr 0x88       //月
#define ds1302_year_addr  0x8c       //年
//初始时间定义
void DS1302_delay(uchar dd);
//void DS1302_init(uchar *time);
void ds1302_write_byte(uchar addr, uchar d) ;
uchar ds1302_read_byte(uchar addr);
void DS1302_SetTime(uchar *ad);
void DS1302_Readtime(void);
#endif  
	 



