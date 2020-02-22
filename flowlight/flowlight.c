#include <reg51.h>

void delay(unsigned int delta);

void main() 
{
	unsigned char i;
	P2 = 0x00;
	while(1)
	{
		P0 = 0x7f;
		for(i = 0; i < 7; i++) {
			P0 = P0 >> 1;
			delay(15);
		}

		P0 = 0xfe;
		for(i = 0; i < 7; i++) {
			P0 = P0 << 1;
			delay(15);
		}
	}
}

void delay(unsigned int delta)
{
	unsigned int i, j;
	for(i = 0; i < delta; i++)
		for(j = 0; j < 1847; j++);
}
