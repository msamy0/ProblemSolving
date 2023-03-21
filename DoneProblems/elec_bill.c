
#include <stdio.h>


int main() {

    float amount =0;
    scanf("%f", &amount);

    float result = 0 ;
    float array1[4] = {50  ,100  ,100 ,250};
    float array2[4] = {0.5 ,0.75 ,1.2 ,1.5};

    for (int aa = 0; aa<4 ; aa++)
    {
		if (amount > array1[aa])
		{
			result = result + (array1[aa] * array2[aa]);
			amount -= array1[aa];
		}
		else
		{
			result = result + (amount *array2[aa] );
			break;
		}
    }
    result = result + (result * 0.2);
    printf("%0.2f \n", result);


    return 0;
}






