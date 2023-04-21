
#include <stdio.h>

int main() {

    int amount =0;
    //int note500=0 , note100=0 , note50=0 , note20=0 , note10=0 , note5=0 , note2=0 ,note1 =0;
    int notearr[8] = {0,0,0,0,0,0,0,0};

    scanf("%d", &amount);

    if (amount >= 500)
    {
     notearr[0] = (int)(amount / 500);
     amount = amount - (notearr[0] * 500);
    }
    if (amount >= 100)
    {
     notearr[1] = (int)(amount / 100);
     amount = amount - (notearr[1] * 100);
    }
    if (amount >= 50)
    {
     notearr[2] = (int)(amount / 50);
     amount = amount - (notearr[2] * 50);
    }
    if (amount >= 20)
    {
     notearr[3] = (int)(amount / 20);
     amount = amount - (notearr[3] * 20);
    }
    if (amount >= 10)
    {
     notearr[4] = (int)(amount / 10);
     amount = amount - (notearr[4] * 10);
    }
    if (amount >= 5)
    {
     notearr[5] = (int)(amount / 5);
     amount = amount - (notearr[5] * 5);
    }
    if (amount >= 2)
    {
     notearr[6] = (int)(amount / 2);
     amount = amount - (notearr[6] * 2);
    }
    if (amount >= 1)
    {
     notearr[7] = (int)(amount / 1);
     amount = amount - (notearr[7] * 1);
    }

    printf("500 = %d \n", notearr[0]);
    printf("100 = %d \n", notearr[1]);
    printf("50 = %d \n", notearr[2]);
    printf("20 = %d \n", notearr[3]);
    printf("10 = %d \n", notearr[4]);
    printf("5 = %d \n", notearr[5]);
    printf("2 = %d \n", notearr[6]);
    printf("1 = %d \n", notearr[7]);

    return 0;
}
/*


 * */

