#include <stdio.h>
int main(void) {
	int countoflines = 0;
	scanf("%d", &countoflines);

	char string[countoflines][101];
	char stringlen[countoflines];

	for (int i = 0; i < countoflines; ++i) {
		scanf("%s", string[i]);
		int r = 0;
		stringlen[i] = 0;
		while (string[i][r] != '\0')
		{
			stringlen[i]++;
			r++;
		}
	}

	fflush(NULL);
	for (int i = 0; i < countoflines; ++i)
	{
    if (stringlen[i] > 10)
		  printf("%c%d%c\n", string[i][0] , stringlen[i]-2 , string[i][stringlen[i]-1] );
    else
      printf("%s\n", string[i]);
	}

}