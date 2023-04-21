#include <stdio.h>
#include <math.h>

typedef unsigned char 			   uint8;
typedef unsigned short int         uint16;
typedef unsigned int               uint32;
typedef unsigned long long         uint64;
typedef signed char                sint8;
typedef signed short int           sint16;
typedef signed int                 sint32;

// uint64 reverseIntFunction(uint32 userInput);
// uint64 reverseIntFunction(uint32 userInput)
// {	uint64 result = 0;
// 	uint8 old_digits[10]; //max digits count of uint32
// 	uint64 digitGrade = 10;
// 	uint8 LocalCounterA =0;
// 	for (LocalCounterA = 0 ; LocalCounterA < ( sizeof(old_digits)/sizeof(old_digits[0]) ) ; LocalCounterA++)
// 	{
// 		if (userInput == 0)
// 			break;
// 		else
// 		{
// 			uint32 reminder = (userInput % digitGrade);
// 			old_digits[LocalCounterA] = (reminder/(digitGrade/10));		//get the digit
// 			userInput -= reminder;										//remove it from original
// 			digitGrade *= 10; 											//increment the seeking digit
// 		}
// 	}
// 	digitGrade = 1;
// 	while (LocalCounterA != 0)
// 	{
// 		result += (old_digits[LocalCounterA-1] *digitGrade );
// 		LocalCounterA--;
// 		digitGrade *= 10;
// 	}

	
// 	return result;
// }
// int main(void)
// {
// 	uint32 x =4294967295;
// 	uint64 y = reverseIntFunction(x);
// 	printf ("%llu \n",y);

// 	return 0;
// }

int main(void)
{
	uint32 in =4294967295;
	uint64 out = 0;
	
	while (in !=0)
	{
		out = (in % 10) + (out*10);
		in = in/10;
	}
	printf ("%llu \n",out);

	return 0;
}
