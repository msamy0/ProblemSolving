#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getTheDiffrentElementUsingXOR(int *arr1, int *arr2, int n1, int n2)
{
    //1^2^3^4^5^1^2^3^4^5^6
    //1^1^2^2^3^3^4^4^5^5^6
    //0  ^0  ^0  ^0  ^0  ^6
    //0^6 = 6
    int i = 0;

#define INT_MAX 2147483647
    int result = 0;

    for (i = 0; i < n1; i++)
    {
        result ^= arr1[i];
    }
    for (i = 0; i < n2; i++)
    {
        result ^= arr2[i];
    }
    return result;
}


int getTheDiffrentElementUsingSubstraction(int *arr1, int *arr2, int n1, int n2)
{
    int i = 0;

    // int 2^31
    //long 2^63
    long  result = 0;
    for (i = 0; i < n2; i++)
    {
        result += arr2[i];
    }
    for (i = 0; i < n1; i++)
    {
        result -= arr1[i];
    }
    return result;
}


int main()
{
    int arr1[5] = {-1,0,0,-4,-5};
    int arr2[6] = {-1,0,0,-4,-5,INT_MAX};

    int result = getTheDiffrentElementUsingXOR(arr1, arr2, 5, 6);
    printf("The diffrent element is %d\n", result);
    result = getTheDiffrentElementUsingSubstraction(arr1, arr2, 5, 6);
    printf("The diffrent element is %d\n", result);
    int i = 0;
    scanf( "%d" , &i);
    return 0;
}