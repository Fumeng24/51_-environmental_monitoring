#ifndef KEY_H
#define KEY_H 			   
#include <REGX52.H>
#include "oled.h"

sbit key_run = P0^0;
sbit key_shift = P0^1;
sbit key_beep = P0^2;
sbit key_up = P0^3;
sbit key_down = P0^4;

unsigned int KEY_Scan(void);
#endif
