#ifndef _USART_H_
#define _USART_H_
//#include "STC12C5A.h"
#include <stdio.h>
#include "reg52.h"
#include "my1602.h"
char buf[20];
char buf_index=0;

//UART1 ≥ı ºªØ
void Uart1Init(void)    //115200bps 11.0592MHz
{
	
	TMOD=0x20;					
	TH1=0xfd,TL1=0xfd;		
	REN=1;                      
	TR1=1;
	SM0=0;
	SM1=1;
	EA=1;
	ES=1;
//	SCON=0x40;
	TI=1;	
}
void buf_0(void){
	char i;
	for(i=0;i<20;i++)
	{
		buf[i]='\0';
	}
}
void serial(void) interrupt 4{
	int temp;
	temp=SBUF;
	if(RI==1){
		RI=0;
		if(buf[0]!='('){
			buf_index=0;
		}
		buf[buf_index]=temp;
		SBUF=temp;
		write_data(temp);
		printf("%s\n",buf);
		if((buf[buf_index]==')'))
		{
			buf_0();
			SBUF='A';
		}
		

		buf_index++;
	}
	if(TI==1){
		TI=0;
	}
	//printf("99\n");
}

#endif


