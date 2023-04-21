#include <stdlib.h>
#include <stdio.h>

typedef unsigned char              uint8;
typedef unsigned short int         uint16;
typedef unsigned int               uint32;
typedef unsigned long long         uint64;
typedef signed char                sint8;
typedef signed short int           sint16;
typedef signed int                 sint32;

int main()
{
	uint32 userInputSizeOfSerise = 40;
	uint32 lastValue1 = 0;
	uint32 lastValue2 = 1;
	uint32 lastValue3 = 0;
	printf("0 \n1 \n");
	for (int i = 0;i<userInputSizeOfSerise-1;i++)
	{
		lastValue3  = lastValue1 + lastValue2;
		printf("%d \n",lastValue3);
		lastValue1  = lastValue2;
		lastValue2  = lastValue3;
	}

}

/*
//using recursion 
#include<stdio.h>
int fibonacci(int);
int main(){ 
	int n, i; 
	printf("Enter the number of element you want in series :n"); 
	scanf("%d",&n); 
	printf("fibonacci series is : n");
	for(i=0;i<n;i++) { 
		printf("%d ",fibonacci(i));
	}

}
int fibonacci(int i){ 
	if(i==0) return 0; 
	else if(i==1) return 1; 
	else return (fibonacci(i-1)+fibonacci(i-2));
} 
*/