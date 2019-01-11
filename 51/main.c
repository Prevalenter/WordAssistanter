#include "reg52.h"
#include "my1602.h"
#include "delay.h"
#include "key.h"
#include "stdio.h"
//#include "usart.h"
unsigned char code table[]="1234567890";
void main()
{
	int num=0;
	init();
	write_com(0x80);
	write_data('!');
	while(1){
		num=keyscan();
		if(num!='!'){
			init();
			write_data(num);
			//num++;
			delay(5000);
		}			
	}
}
