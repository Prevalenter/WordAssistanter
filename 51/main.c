#include "reg52.h"
#include "my1602.h"
#include "delay.h"
unsigned char code table[]="1234567890";
void main()
{
	int num;
	init();
	write_com(0x80);
	for(num=0;num<5;num++)
	{
		write_data(table[num]);
		delay(5);
	}
	while(1);
}
