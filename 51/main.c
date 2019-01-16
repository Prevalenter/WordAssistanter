#include "reg52.h"
#include "my1602.h"
#include "delay.h"
#include "key.h"
#include "stdio.h"
#include "usart.h"
#include "iic.h"
unsigned char code table[]="1234567890";
void main()
{
	unsigned char a;
	lcd_init();
	iic_init();
	delay_iic1(100);
	write_add(0xa0,23,1);
	delay_iic1(100);
	a=read_add(0xa0,23);
	P1=a;
	write_in_position(1,3,a+48);
	while(1);
//	int num=0;
//	lcd_init();
//	iic_init();
//	write_add(0xa0,23,1);
//	write_in_position(1,3,read_add(0xa0,23)+48);
//	while(1){
//		num=keyscan();
//		if(num!='!'){
//			write_in_position(1,3,num);
//		}			
//	}
}
