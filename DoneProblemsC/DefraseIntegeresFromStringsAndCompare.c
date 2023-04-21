#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

typedef unsigned char 			   uint8;
typedef unsigned short int         uint16;
typedef unsigned int               uint32;
typedef unsigned long long         uint64;
typedef signed char                sint8;
typedef signed short int           sint16;
typedef signed int                 sint32;

char** triangleType(int triangleToy_count, char** inputs, int* result_count);

int main() {


		char** inputs = malloc(4 * sizeof(char*));
		for(int i = 0 ; i < 4 ; i++)
		{
			*(inputs + i) = malloc(14 * sizeof(char));

		}
		*(inputs + 0) = "1400 569 1000";
		*(inputs + 1) = "4 2 3";
		*(inputs + 2) = "199 199 199";
		*(inputs + 3) = "86 86 86";


		char** outputs = malloc(4 * sizeof(char*));
		for(int i = 0 ; i < 4 ; i++)
		{
			*(outputs + i) = malloc(15 * sizeof(char));

		}
		int x = 0;
		outputs = triangleType(4,inputs,&x);

		printf("%s\n",*(outputs + 0));
		printf("%s\n",*(outputs + 1));
		printf("%s\n",*(outputs + 2));
		printf("%s\n",*(outputs + 3));


    return 0;
}
char** triangleType(int triangleToy_count, char** inputs, int* result_count)
{
	*result_count = triangleToy_count;
	char ** resultReturn = malloc(triangleToy_count * sizeof(char*));

	for (int i = 0; i <triangleToy_count ; i++)
	{
		char str[3][5];
		int strCounter=0;
		int charCounter=0;

		char* temp = (*(inputs + i));

		while ( *temp != '\0')
		{
			if ( *temp == ' ' )
			{
				strCounter++;
				charCounter = 0;
				temp++;
				continue;
			}
			else
			{
				str[strCounter][charCounter] = *temp;
				charCounter++;
			}
			temp++;
		}

		int integersArr[3];
		integersArr[0] = atoi(str[0]);
		integersArr[1] = atoi(str[1]);
		integersArr[2] = atoi(str[2]);

		if ((integersArr[0] + integersArr[1] > integersArr[2]) && (integersArr[0] + integersArr[2] > integersArr[1]) && (integersArr[1] + integersArr[2] > integersArr[0]) )
		{
			if ( (integersArr[0] ==integersArr[1]))
			{
				if ((integersArr[0] ==integersArr[2]))
				{
					*(resultReturn + i) = "Equilateral";
				}
				else
				{
					*(resultReturn + i) = "Isosceles";
				}
			}
			else if ((integersArr[0] ==integersArr[2]))
			{
				if ((integersArr[0] ==integersArr[1]))
				{
					*(resultReturn + i) = "Equilateral";
				}
				else
				{
					*(resultReturn + i) = "Isosceles";
				}
			}
			else if ((integersArr[1] ==integersArr[2]))
			{
				if ((integersArr[1] ==integersArr[0]))
				{
					*(resultReturn + i) = "Equilateral";
				}
				else
				{
					*(resultReturn + i) = "Isosceles";
				}
			}

			else
			{
				*(resultReturn + i) = "None of these";
			}

		}
		else
		{
			*(resultReturn + i) = "None of these";
		}
		for (int a = 0; a < 3 ; a++)
		{
			for (int b = 0; b < 5 ; b++)
			{str[a][b] = '\0';}
		}

	}
	return resultReturn;
}
