#include <stdio.h>
typedef unsigned char               uint8;
uint8 ControlFan(uint8 Temp);
int main()
{
	uint8 action =0;
	uint8 Temp = 0;
while(1)
{
	scanf("%huu",&Temp);
	action = ControlFan(Temp);
	printf("%d\n",action);
}
 return 0;
}

uint8 ControlFan(uint8 Temp)
{
	static uint8 oldstate=0;
	if (Temp == 50)
	{
		oldstate=1;
		return 1;
	}
	else if (Temp  == 30)
	{
		oldstate=0;
		return 0;
	}
	else if (Temp  > 50)
	{
		oldstate=1;
		return 1;
	}

	else if (Temp  <30 )
	{
		oldstate=0;
		return 0;
	}
	else
	{
		return oldstate;
	}
}













