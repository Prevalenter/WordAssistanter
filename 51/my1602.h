#ifndef _MY1602_H_
#define _MY1602_H_
#include "delay.h"
sbit lcd_en=P2^6;
sbit lcd_rs=P2^5;
//sbit lcd_en=P3^4;
//sbit lcd_rs=P3^5;
//sbit dula=P2^6;
//sbit wela=P2^7;
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
void SetCurPosition(unsigned char x, unsigned char y){
	if(x==0){
		x=0x80;
	}
	else{
		x=0x80+0x40;
	}
	write_com(x+y);
}
void write_in_position(unsigned char x,unsigned char y,unsigned char date){
	lcd_en=0;
	SetCurPosition(x,y);
	write_data(date);
}
//the init of lcd1602
void lcd_init(void)
{
//	dula=0;
//	wela=0;
	lcd_en=0;
	write_com(0x38);
	write_com(0x0c);//no
	write_com(0x06);//set the mode 
	write_com(0x01);//clear 1602
}
#endif