#ifndef DISPLAY_H
#define DISPLAY_H 			   
#include <REGX52.H>
#include "oled.h"


void display_year(unsigned char a,unsigned char flag);
void display_month(unsigned char a,unsigned char flag);
void display_day(unsigned char a,unsigned char flag);
void display_hour(unsigned char a,unsigned char flag);
void display_min(unsigned char a,unsigned char flag);
void display_sec(unsigned char a,unsigned char flag);
void display_tmp(unsigned char a,unsigned char flag);
void display_shidu(unsigned char a,unsigned char flag);
void display(unsigned char a,unsigned char flag,unsigned char shift);
void display2(unsigned char a,unsigned char flag,unsigned char shift);
#endif
