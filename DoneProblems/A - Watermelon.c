#include <stdio.h>
#include <math.h>
int main(void) {		
	int input = 5;
  scanf("%d",&input); 
  int inputsqr = sqrt(input);
  int counter =2L;
  int flag =0;

  // while (counter <= input)
  // {
  //   if (input % counter == 0 )
  //   {
  //     if ((input / counter) % 2 == 0)
  //     {flag++;break;}
  //   }
  //     counter+=2;
  // }

  if (input % 2 == 0 && input > 2 )
    printf("YES");

    else
     printf("NO");


    return 0;
}

