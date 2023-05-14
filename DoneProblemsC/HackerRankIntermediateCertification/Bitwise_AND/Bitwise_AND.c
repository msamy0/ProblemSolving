//@msamygawad
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
the algorithm is like following
1- create a dictionary of size 4095 + 1 (max element in array + one for indexing)
2- loop over the array and count the number of each element in the dictionary. indexes of dictionary array is represent the
   elements values of the input arr. By thhis way we record the frequency of each element in the array
3- loop over the dictionary and check if the element is 0 or not. if it is 0 then continue to the next element
4- if the element is not 0 then loop over the dictionary again and check if the element is 0 or not. if it is 0 then continue to the next element
5- if the element is not 0 then check if the bitwise and of the two elements is power of 2 or not. if it is power of 2 then add the number of pairs
   to the counter. if the two elements are equal then add the sum of sorted array of the number of elements - 1 to the counter. if the two elements
   are not equal then add the multiplication of the two elements to the counter.
6- return the counter

Example:
arr =       [1, 2, 1, 2, 4, 8, 4, 8]

indexing---> 0  1  2  3  4  5  6  7  8 
freqDict =  [0, 2, 2, 0, 2, 0, 0, 0, 2]

elemnts to loop over are  1, 2, 4, 8
                          2  2  2  2

*/

// function to check if the number is power of 2 or not
bool power2(int n)
{
  return (n != 0) && ((n & (n - 1)) == 0);
}

// summtion of sorted array that least element is 1 and max element is n
long sumOfSortedArray(int n)
{
  return ((long)n * (n + 1)) / 2;
}

// function to count the number of pairs
long countPairs(int arr_count, int *arr)
{
  int freqDictSize = (4095) + 1;
  int *freqDict = (int *)calloc((freqDictSize), sizeof(int));

  for (int i = 0; i < arr_count; i++)
    freqDict[arr[i]]++;

  long counterOfPairs = 0;

  for (int i = 0; i < freqDictSize; i++)
  {
    if (freqDict[i] == 0)
      continue;

    for(int j = i; j < freqDictSize; j++)
    {
      if (freqDict[j] == 0)
        continue;

      if (power2(i & j) == 1)
      {
        if (i == j)
          counterOfPairs += sumOfSortedArray (freqDict[i] - 1);

        else
          counterOfPairs += freqDict[i] * freqDict[j] ;
      }
    }
  }
  return counterOfPairs;
}

int main()
{
// test case of countPairs fucntion
#define arr_count 8
int arr[arr_count] = {1, 2, 1, 2, 4, 8, 4, 8};
long result = countPairs(arr_count, arr);
printf("%ld\n", result);
int r = 0;
scanf("%d", &r);
return 0;
}