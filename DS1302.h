#include <REGX52.H>
#include <intrins.h>
#ifndef __DS1302_H
#define __DS1302_H

#define uchar unsigned char
#define uint  unsigned int
extern uchar time_data[6];//??????

//DS1302���Ŷ���
//sbit RST=P3^7;
//sbit IO=P3^6;
//sbit SCK=P3^5;
sbit RST=P2^0;
sbit IO=P2^1;
sbit SCK=P2^2;
//DS1302��ַ����
#define ds1302_sec_add			0x80		//�����ݵ�ַ
#define ds1302_min_add			0x82		//�����ݵ�ַ
#define ds1302_hr_add			0x84		//ʱ���ݵ�ַ
#define ds1302_date_add			0x86		//�����ݵ�ַ
#define ds1302_month_add		0x88		//�����ݵ�ַ
#define ds1302_day_add			0x8a		//�������ݵ�ַ
#define ds1302_year_add			0x8c		//�����ݵ�ַ
#define ds1302_control_add		0x8e		//�������ݵ�ַ
#define ds1302_charger_add		0x90 					 
#define ds1302_clkburst_add		0xbe
#define Time_24_Hour    0x00    //24Сʱ��
#define Time_Start     0x00    //��ʼ��ʱ
//DS1302�Ĵ�������ָ���ʱ���ַ
#define ds1302_sec_addr   0x80       //��
#define ds1302_min_addr   0x82       //��
#define ds1302_hour_addr  0x84       //ʱ
#define ds1302_day_addr   0x86       //��
#define ds1302_month_addr 0x88       //��
#define ds1302_year_addr  0x8c       //��
//��ʼʱ�䶨��
void DS1302_delay(uchar dd);
//void DS1302_init(uchar *time);
void ds1302_write_byte(uchar addr, uchar d) ;
uchar ds1302_read_byte(uchar addr);
void DS1302_SetTime(uchar *ad);
void DS1302_Readtime(void);
#endif  
	 



