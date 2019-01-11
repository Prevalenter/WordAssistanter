#ifndef _KEY_H_
#define _KEY_H_
#include "delay.h"
unsigned char keyscan(void)
{
	//default is 0xff
	P1=0xfe;
	switch(P1){
		case 0xee:return 'D';
		case 0xde:return 'C';
		case 0xbe:return 'B';
		case 0x7e:return 'A';
	}
	P1=0xfd;
	switch(P1){
		case 0xed:return '#';
		case 0xdd:return '9';
		case 0xbd:return '6';
		case 0x7d:return '3';
	}
	P1=0xfb;
	switch(P1){
		case 0xeb:return '0';
		case 0xdb:return '8';
		case 0xbb:return '5';
		case 0x7b:return '2';
	}
	P1=0xf7;
	switch(P1){
		case 0xe7:return '*';
		case 0xd7:return '7';
		case 0xb7:return '4';
		case 0x77:return '1';
	}
	return '!';
}
#endif