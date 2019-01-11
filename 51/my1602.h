#ifndef _MY1602_H_
#define _MY1602_H_
#include "delay.h"
sbit lcd_en=P3^4;
sbit lcd_rs=P3^5;
sbit dula=P2^6;
sbit wela=P2^7;
//write com
void write_com(unsigned char com)
{
	lcd_rs=0;
	P0=com;
	delay(5);
	lcd_en=1;
	delay(5);
	lcd_en=0;
}
//write the date to 1602
//date is the string you want  write into 1602
void write_data(unsigned char date)
{
	lcd_rs=1;
	P0=date;
	delay(5);
	lcd_en=1;
	delay(5);
	lcd_en=0;
}
//the init of lcd1602
void init(void)
{
	dula=0;
	wela=0;
	lcd_en=0;
	write_com(0x38);
	write_com(0x0c);
	write_com(0x06);
	write_com(0x01);
}
#endif