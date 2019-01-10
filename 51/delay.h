#ifndef _DELAY_H_
#define _DELAY_H_

void delay(unsigned char z)
{
	unsigned int x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
#endif