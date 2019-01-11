#ifndef _USART_H_
#define _USART_H_
//#include "STC12C5A.h"
#include <stdio.h>
char buf[20];
char buf_index=0;
char serve_val=90;
//UART1 初始化
void Uart1Init(void)    //115200bps 11.0592MHz
{
    PCON &= 0x7F;       //波特率不倍速
    SCON    = 0x50;     //8位数据位，可变波特率
    AUXR |= 0x04;       //1T模式
    BRT     = 0xFD;     //设置独立波特率重装值
    AUXR |=0X01;        //串口1选择独立发生器为波特率发生器
    AUXR |=0X10;        //启动独立波特率发生器
    
		EA=1;
	ES = 1;                 //使能串口1中断
//	REN=1; 
}

//UART1 发送串口数据
void UART1_SendData(char dat)
{
    ES=0;           //关中断
    SBUF=dat;           
    while(TI!=1);   //等待发送成功
    TI=0;           //清楚发送中断标志
    ES=1;           //开启中断
}

//UART1 发送一个字符串
void UART1_SendString(char *s)
{
    while(*s)//监测字符串结束符
    {
        UART1_SendData(*s++);//发送当前字符
    }
}

//重写 putchar函数
char putchar(char c)
{
    UART1_SendData(c);
    return c;
}
void buf_0(void)
{
	char i;
	for(i=0;i<20;i++)
	{
		buf[i]='\0';
	}
}
void serial(void) interrupt 4
{
	int temp;
	RI=0;
	printf("ok\n");
	//temp=SBUF;
	//SBUF=temp;
	//printf("%d",temp);
	
//	int temp;
//	RI=0;
//	buf[buf_index]=SBUF;
//	buf_index++;
//	printf("%c,%c",buf_index+48,buf[buf_index-1]);
//	if(buf[0]==98)
//	{
//			if(buf[buf_index-1]=='e')
//			{
//				//获取舵机夹角
//				if(buf[1]=='g')
//				{
//					if(buf[2]==48&&buf[3]==48&&buf[4]==49)
//					{
//						printf("bs113e");
//						buf_index=0;
//						buf_0();
//					}
//				}
//				else if(buf[1]=='s')
//				{
//					temp=(buf[2]-48)*100+(buf[3]-48)*10+(buf[4]-48);
//					
//					set_pwm(0,temp);
//					buf_index=0;
//					buf_0();
//				}
//			}
//		}
//	else 
//	{
//		buf_index=0;
//	}
}

#endif


