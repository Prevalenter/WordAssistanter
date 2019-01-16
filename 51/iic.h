#include<reg52.h>
#define uchar unsigned char
sbit sda=P2^0;
sbit scl=P2^1;
uchar a;
void delay_iic()
{ ;; }
void start()  //????
{	
	sda=1;
	delay_iic();
	scl=1;
	delay_iic();
	sda=0;
	delay_iic();
}

void stop()   //??
{
	sda=0;
	delay_iic();
	scl=1;
	delay_iic();
	sda=1;
	delay_iic();
}

void respons()  //??
{
	uchar i;
	scl=1;
	delay_iic();
	while((sda==1)&&(i<250))i++;
	scl=0;
	delay_iic();
}

void iic_init()
{
	sda=1;
	delay_iic();
	scl=1;
	delay_iic();
}

void write_byte(uchar date)
{
	uchar i,temp;
	temp=date;


	for(i=0;i<8;i++)
	{
		temp=temp<<1;
		scl=0;
	    delay_iic();
		sda=CY;
		delay_iic();
		scl=1;
		delay_iic();
	//	scl=0;
     //   delay_iic();
	}
	scl=0;
	delay_iic();
	sda=1;
	delay_iic();
}

uchar read_byte()
{
	uchar i,k;
	scl=0;
	delay_iic();
	sda=1;
	delay_iic();
	for(i=0;i<8;i++)
	{
		scl=1;
		delay_iic();	
		k=(k<<1)|sda;
		scl=0;
		delay_iic();	
	}
	return k;
}

void delay_iic1(uchar x)
{
	uchar a,b;
	for(a=x;a>0;a--)
	 for(b=100;b>0;b--);
}

void write_add(uchar reg,uchar address,uchar date)
{
	start();
	write_byte(reg);
	respons();
	write_byte(address);
	respons();
	write_byte(date);
	respons();
	stop();
}

uchar read_add(uchar reg,uchar address)
{
	uchar date;
	start();
	write_byte(reg);
	respons();
	write_byte(address);
	respons();
	start();
	write_byte(reg+1);
	respons();
	date=read_byte();
	stop();
	return date;
}
void iic_test(){
//	uchar date;
	iic_init();
	write_add(0xa0,23,0xab);
	delay_iic1(100);
	P1=read_add(0xa0,23);

}