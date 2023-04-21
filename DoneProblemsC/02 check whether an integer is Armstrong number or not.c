#include <stdio.h>
#include <math.h>

typedef unsigned char 			   uint8;
typedef unsigned short int         uint16;
typedef unsigned int               uint32;
typedef unsigned long long         uint64;
typedef signed char                sint8;
typedef signed short int           sint16;
typedef signed int                 sint32;

int main(void)
{
	uint32 userInput =1634; // user input
	uint32 InputFixedSaver = userInput; // save user input unchanged as we will chanig it during calculaions
	uint64 sumOfDigitsToPowerN =0; //sum of power of each digit to n (n = number of digits)
	uint32 arr[10];//store digits retrieved
	uint8 digitsCounter = 0;//count how much digits are they
	
	
	//loop to get individiual digits and their count
	while (userInput !=0)
	{
		arr[digitsCounter] = (userInput % 10);
		userInput = userInput/10;
		digitsCounter++;
	}

	//loop to calculate sum of digits to power n (where n is number of digits in the userInput number)
	for (int LocalCounterA = digitsCounter-1; LocalCounterA >=0 ; LocalCounterA--)
	{
		double digitPowered = pow( (double)arr[LocalCounterA] , (double) digitsCounter);
		sumOfDigitsToPowerN += digitPowered;
	}

	//check whether 
	if (sumOfDigitsToPowerN == InputFixedSaver)
		printf ("Yes it is Armstrong Number \n");
	else
		printf ("No is is not Armstrong number \n");

	return 0;
}
