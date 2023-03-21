/*

 * */
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char              uint8;
typedef unsigned short int         uint16;
typedef unsigned int               uint32;
typedef unsigned long long         uint64;
typedef signed char                sint8;
typedef signed short int           sint16;
typedef signed int                 sint32;

/*optimized*/
int main()
{
	unsigned int  number = 74523469;
	uint8 flag = 0;
	if (number == 0 || number == 1)
	{
		flag = 1;
	}

	else if (number % 2 == 0)
	{
		for (unsigned int i = 2 ; i <=number/2 ; i+=2)
		{
			if (number % i == 0)
			{
				flag = 1; //not prime
				break;
			}
		}
	}

	//Upto here it will workif we just considered the last  condition to be only else (not checking odd or even)
	else
	{
		for (unsigned int i = 3 ; i <=number/3 ; i+=2)
		{
			if (number % i == 0)
			{
				flag = 1; //not prime
				break;
			}
		}
	}
	printf("%s" , flag == 1 ? "Not Prime" : "Prime");


}


/*not optimized*/
//int main()
//{
//	unsigned int  number = 74523469;
//	uint8 flag = 0;
//	if (number == 0 || number == 1)
//	{
//		flag = 1;
//	}
//
//	else
//	{
//		for (unsigned int i = 2 ; i <=number/2 ; i+=2)
//		{
//			if (number % i == 0)
//			{
//				flag = 1; //not prime
//				break;
//			}
//		}
//	}
//	printf("%s" , flag == 1 ? "Not Prime" : "Prime");
//
//
//}

