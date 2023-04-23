#include <stdio.h>
/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(int arr_count, int* arr) {
    long sum = 0;
    long bestMinSum = 0;
    long bestMaxSum = 0;
    
    for (int i = 0 ; i < arr_count ; i++)
    {
        sum =0;
        for (int j = 0 ; j<arr_count ;j++ )
        {
            if (i == j)
                continue;
            else
            {
                
                sum += arr[j];
            }
        }
        if(i==0)
        {
            bestMaxSum = sum;
            bestMinSum = sum;
        }
        if (sum > bestMaxSum)
            bestMaxSum = sum;
        else if (sum < bestMinSum)
            bestMinSum = sum;
    }
    printf("%ld %ld", bestMinSum, bestMaxSum);
}

int main ()
{
    int arr[6] = {-4, 3, -9, 0, 4, 1};
    plusMinus(6, arr);
    return 0;
}
