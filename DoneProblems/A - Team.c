#include <stdio.h>
int main(void)
{
	int count = 0;
	scanf("%d\n",&count);

	char input[10]="0000000000";
	int numberofvalidsol = 0;

	for (int i = 0 ; i < count ;++i)
	{
		gets(input);
		int localcounter=0;
		for (int r = 0 ; r <= 4 ; r+=2)
		{
			if (input[r] == '1')
				localcounter++;
		}

		if (localcounter >=2)
			numberofvalidsol++;
	}

	printf("%d",numberofvalidsol);
}
