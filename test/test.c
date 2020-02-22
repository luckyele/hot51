#include <reg51.h>

#define uchar unsigned char

void delay(unsigned int delta);

void main() {
	uchar m[8] = {0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01,0x00};
	uchar i = 0;
	
	while(1){
		P0 = m[i++ % 8];
//		LED = 0;
		delay(1);
//		LED = 1
		P0 = 0xff;
		delay(1);
	}
}

void delay(unsigned int delta)
{
	unsigned int i,j;
	for(i = 0; i < delta; i++)
		for(j = 0; j < 1827; j++)
		;
}

