#include <reg51.h>
#include "delay.h"

void delay(unsigned int);

void main()
{
	delay(10);
	P0 = 0xfe;
	while(1);
}

