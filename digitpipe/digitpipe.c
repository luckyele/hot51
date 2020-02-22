#include <reg51.h>

void delay(unsigned int delta);

void main()
{
	/* define digit pipe display patterns.
	 * 0,1,2,3,4,5,6,7
	 * A,B,C,D,E,F
	 * */
	unsigned char c_code[] = {
		0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6f,
		/*		0x77,0x7C,0x39,0x5E,0x79,0x71*/
	};

	unsigned char i = 0;
	while(1)
	{
		P0 = c_code[i++ % 10];
		delay(50);
		
	}
}

void delay(unsigned int delta)
{
	unsigned int i,j;
	for(i = 0; i < delta; i++)
		for(j = 0; j < 1827; j++)
		;
}


