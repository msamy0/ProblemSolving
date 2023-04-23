#include <stdio.h>

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(int arr_count, int* arr) {
    double pos_count = 0;
    double neg_count = 0;
    double zero_count = 0;
    double sum =0;
    for (int i = 0 ; i < arr_count ; i++)
    {
        if (arr[i] > 0)
        {
            pos_count++;  
        }
        else if (arr[i] < 0)
        {
            neg_count++;
        }
        else 
        {
            zero_count++;    
        }
    }
    sum = pos_count + neg_count + zero_count;
    if (sum == 0)
        printf ("0 \n0 \n0\n");
    else
    {
        printf("%.6lf \n", pos_count/sum);
        printf("%.6lf \n", neg_count/sum);
        printf("%.6lf \n", zero_count/sum);
    }
}
int main ()
{
    int arr[6] = {-4, 3, -9, 0, 4, 1};
    plusMinus(6, arr);
    return 0;
}
