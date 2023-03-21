#include <stdio.h>
#include <string.h>

typedef unsigned char 			   uint8;
typedef unsigned short int         uint16;
typedef unsigned int               uint32;
typedef unsigned long long         uint64;
typedef signed char                sint8;
typedef signed short int           sint16;
typedef signed int                 sint32;

uint8 CountOnes(uint32);

int main() {


		uint8 volatile functionRturn = shiftfunc (0x0);
		printf("%d\n",functionRturn);


    return 0;
}

uint8 CountOnes(uint32 u32InputNumber)
{
	uint32 binaryCheck = 0;
	uint8 count = 0;
	for (int i = 0 ; i <32 ; i++)
	{
		binaryCheck = (u32InputNumber & (((uint32)0x00000001) << i));

		if (binaryCheck)
			count++;
		else
			continue;
	}

	return count;
}
