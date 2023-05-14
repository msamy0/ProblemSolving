//@msamygawad
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Code  algorithm:
- assume all elements equal 1, and the window have one element which is k
- if the sum of the elements less than maxSum, then proceed to the following
- increase the window elements by one, window contains k element only now, then recalcualte the globalSum, if it pass proceed
- widen the window to the right and the left if you are in the array limit of right and left, then add 1 for each element in the window on the globalSum
- keep doing this, widen the window to the left and right and add one for each element in the window to the globalSum
- break the loop on exceedin maximum sum, then the curren k element is considered the one that follows the biggies could achieve k element
- then return = k-1

example: 
n = 4 , maxSum = 20 , k = 2

 0   1   2   3
 -------------
 1   1   1   1   +0 (sum = 4) initial case
        |_|---> Window = 1
 1   1   2   1   +1 (sum = 5) first itteration in the loop
 
    |_________|---> Window = 3
 1   2   3   2   +3 (sum = 8) second itteration in the loop

|_____________|---> Window = 4
 2   3   4   3   +4 (sum = 12) second itteration in the loop

|_____________|---> Window = 4
 3   4   5   4   +4 (sum = 16) second itteration in the loop

|_____________|---> Window = 4
 4   5  (6)  5   +4 (sum = 20) second itteration in the loop - STOP here

|_____________|---> Window = 4
 5   6   7   6   +4 (sum = 24) second itteration in the loop - (24 > maxSum)

--> result = 6 
*/
int maxElement(int n, int maxSum, int k)
{
  int rightIdx = k;
  int rightIdxLimit = n-1;

  int leftIdx = k;
  int leftIdxLimit = 0;

  int k_idxMaxVal = 1;
  int globalSum = n;

  while (globalSum <= maxSum){
    globalSum += rightIdx - leftIdx + 1;
    if (rightIdx < rightIdxLimit){
        rightIdx++;
    }
    if (leftIdx > leftIdxLimit){
        leftIdx--;
    }
    k_idxMaxVal++;
  }

  return k_idxMaxVal-1;
}

int main()
{

  int number_of_test_cases = 15;
  FILE *fpIN;
  fpIN = fopen("input.txt", "r");

  FILE *fpOUT;
  fpOUT = fopen("output.txt", "r");

  int correct_count = 0;
  int counter = 0;

  for (int i = 0; i < number_of_test_cases; i++)
  {
    printf("Test case %d:    ", counter);
    // get input from file

    int n, maxSum, k;
    fscanf(fpIN, "%d %d %d", &n, &maxSum, &k);

    // call function
    int result = maxElement(n, maxSum, k);
    // print result
    printf("%d          ", result);

    int expected_result;
    fscanf(fpOUT, "%d", &expected_result);

    // print expected result
    printf("%d", expected_result);
    // check if the result is correct
    if (result == expected_result)
    {
      printf("    Correct\n");
      correct_count++;
    }
    else
    {
      printf("   Wrong\n");
    }

    printf("\n");
    counter++;
  }
  printf("Correct count = %d from %d\n", correct_count, number_of_test_cases);

  fclose(fpIN);
  fclose(fpOUT);
  int r = 0;
  scanf("%d", &r);
  return 0;
}