#include <REGX52.H>
#ifndef __DHT11_H
#define __DHT11_H
sbit io=P0^7;
#define uint unsigned int 
#define uchar unsigned char 
extern unsigned char  data_byte; 
extern unsigned char  RH,RL,TH,TL; 
void delay(uchar ms);
void delay1();
void start();
unsigned char dht_11_receive_byte();
void dht_11_receive();
#endif  
	 



