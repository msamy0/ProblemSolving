/* Fibonaci*/
#include <stdio.h>

int main() {

    int x =0;
    scanf("%d", &x);

    int result1 = 0;
    int result2 = 1;
    int temp=0;

    for (int i = x+1; i >0 ; i--)
    {
     printf("%d \n", result1);
     temp = result2;
     result2 = result1 + result2;
     result1 = temp;

    }


    return 0;
}






