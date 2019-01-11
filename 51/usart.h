#ifndef _USART_H_
#define _USART_H_
//#include "STC12C5A.h"
#include <stdio.h>
char buf[20];
char buf_index=0;
char serve_val=90;
//UART1 ��ʼ��
void Uart1Init(void)    //115200bps 11.0592MHz
{
    PCON &= 0x7F;       //�����ʲ�����
    SCON    = 0x50;     //8λ����λ���ɱ䲨����
    AUXR |= 0x04;       //1Tģʽ
    BRT     = 0xFD;     //���ö�����������װֵ
    AUXR |=0X01;        //����1ѡ�����������Ϊ�����ʷ�����
    AUXR |=0X10;        //�������������ʷ�����
    
		EA=1;
	ES = 1;                 //ʹ�ܴ���1�ж�
//	REN=1; 
}

//UART1 ���ʹ�������
void UART1_SendData(char dat)
{
    ES=0;           //���ж�
    SBUF=dat;           
    while(TI!=1);   //�ȴ����ͳɹ�
    TI=0;           //��������жϱ�־
    ES=1;           //�����ж�
}

//UART1 ����һ���ַ���
void UART1_SendString(char *s)
{
    while(*s)//����ַ���������
    {
        UART1_SendData(*s++);//���͵�ǰ�ַ�
    }
}

//��д putchar����
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
//				//��ȡ����н�
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


