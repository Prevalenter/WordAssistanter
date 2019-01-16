#ifndef _KEY_H_
#define _KEY_H_
#include "delay.h"
unsigned char keyscan(void)
{
	//default is 0xff
	P1=0xfe;
	switch(P1){
		case 0xee:return '1';
		case 0xde:return '2';//c
		case 0xbe:return '3';//b
		case 0x7e:return 'A';//a
	}
	P1=0xfd;
	switch(P1){
		case 0xed:return '4';//#
		case 0xdd:return '5';//9
		case 0xbd:return '6';//6
		case 0x7d:return 'B';//3
	}
	P1=0xfb;
	switch(P1){
		case 0xeb:return '7';//0
		case 0xdb:return '8';//8
		case 0xbb:return '9';//5
		case 0x7b:return 'C';//2
	}
	P1=0xf7;
	switch(P1){
		case 0xe7:return '*';//*
		case 0xd7:return '0';//7
		case 0xb7:return '#';//4
		case 0x77:return 'D';//d
	}
	return '!';
}
#endif