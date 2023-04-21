#include <stdio.h>
#include <string.h>

typedef unsigned char 				uint8;
typedef unsigned short int         uint16;
typedef unsigned int               uint32;
typedef unsigned long long         uint64;
typedef signed char                sint8;
typedef signed short int           sint16;
typedef signed int                 sint32;

uint8 shiftfunc(uint32, int,uint32*);

int main() {

		uint32 pu32Output = 0;
		uint32 binaryCheck = 0;
		uint8 volatile functionRturn = shiftfunc (0b00000000000000000000000000000111, 33, &pu32Output);
		printf("%X\n",pu32Output);
		printf("%X\n",functionRturn);
		for (int localCounter = 0 ; localCounter <32;localCounter++)
		{
			binaryCheck = (pu32Output & (((uint32)0x80000000) >> localCounter));
			if (binaryCheck)
			printf("%d",1);
			else
			printf("%d",0);

		}

    return 0;
}

uint8 shiftfunc(uint32 u32InputNumber, int u8NumberOfShifts ,uint32* pu32Output)
{
	if (u8NumberOfShifts > 32)
	{
		*pu32Output = u32InputNumber;
		return 0xFF;

	}
	else
	{
		uint32 temp=0;
		for (int i =0; i < u8NumberOfShifts ; i++ )
		{
			temp = (u32InputNumber <<31 );
			u32InputNumber >>= 1;
			u32InputNumber = u32InputNumber | temp;
		}

		*pu32Output = u32InputNumber;
		return 0;
	}

}
