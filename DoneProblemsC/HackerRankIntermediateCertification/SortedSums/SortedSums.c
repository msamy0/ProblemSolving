//@msamygawad
//Fails in last 4 test cases (time limit exceed)
//To be continued ....
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
Example

arr-->    5   4   6   3   7   8 
ranks-->  1                       localSum = 5
          2   1                   localSum = 5*2 + 4*1
          2   1   3               localSum = 5*2 + 4*1 + 3*3      
          3   2   4   1           localSum = 5*3 + 4*2 + 6*4 + 3*1        
          3   2   4   1   5       localSum = 5*3 + 4*2 + 6*4 + 3*1 + 7*5               
          3   2   4   1   5   6   localSum = 5*3 + 4*2 + 6*4 + 3*1 + 7*5 + 8*6            

take the array form left to right starting from second index and set its rank in rankArr according
to its value related to the previous values. starting its rank at i+1, then move to the left with the element
if it is less than the one in comarison [j], then store [j]'s rank in current minRank if it is less than it then
increase [j] rank by 1, which denoting that it's shifted to the right by 1
do it to the end of the array.
*/

int sortedSum(int a_count, int* a) 
{
    long long globalSum = a[0];
    const long long m_const = 1000000007;

    int* rankArr = (int*)calloc(a_count, sizeof(int));
    rankArr[0] = 1;

    for(int i = 1; i < a_count; i++) 
    {
      int minRank = i+1;
      for (int j = i-1 ; j >= 0 ; j--)
      {
        if (a[i] < a[j])
        {
          if (minRank > rankArr[j]){
            minRank = rankArr[j];     
          }
          rankArr[j]++;
        }
        globalSum += (long long)a[j] * (long long)rankArr[j];
      }
      rankArr[i]= minRank;
      globalSum += ( (long long)a[i] * (long long)rankArr[i] );
    }
    return globalSum % m_const;
}

int main()
{
#define a_count 14
int a[a_count] = {747402, 380408, 605449, 846906, 385224, 31431, 677517, 770001, 389085, 40373, 487560, 886252, 596334, 59083};
printf("%d", sortedSum(a_count, a));
int r = 0;
scanf("%d", &r);
return 0;
}