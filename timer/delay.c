#include "delay.h"
#include <stdio.h>

void delay(unsigned int delta)
{
	unsigned int i,j;
	for (i = 0; i < delta; i++)
			for (j = 0; j < 1847; j++);
}
