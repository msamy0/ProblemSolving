//@msamygawad
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*
algorithm is gonna be as following:
- sort the input array, will know why later...
- dividing each element by divisor until it reaches zero, knowing that each value resulted from the divison will have two arrtibutes :
    0- how many times did I reached this value before
    1- how many steps I walked through to reach this value
- do this for all input array element. while doing this, check the current value arrtribute [0], and compare it against threshold,
  so that if it equales or greater than the threshold, get its corresponding attribute [1], which represents the current count of steps
  spent to reach this value.
  Note: that attributes [0][1] are accumelating values, because the keys may be reached by diffrent elments of the array
- Why sorting? -> SEE EXAMPLE BELOW as explained earlier, the values of how many times I reached a value is stored and accumelated in attribute[0]
                  so you have to loop through elements from in ascending order, because you will recorde how many steps (operations)
                  spent to reach this element and consider this number of operations as minimum if they are less the the previous minimum
                  but if there is a greater number that leads a smaller number, then we will reach common values between them in more steps and this
                  will be recorded as the minimum, then on reaching the same value that satisfies the threshold condition on the next element
                  it will exhaus more operation. have alook on the following example
                  Not Sorted -> [6,3,8,4] - threshold = 3, divisor = 2  ===> result globalMinOperations= 6
                                 3 1 4 2
                                 1 0 2 1
                                 0   1 6
                                     0
                             --> in non sorted array I took 6 operation to reach value (1) in the first 3 indexes, and 6 will be recorded as the minimum count of operation
                                 that equalizes the array to the required threshold of 3. procceeding with the code will reach value (1) again after two more steps,
                                 so current achived operations will be 8 and it will be neglected as I have achived less value which is 6.

                  Sorted -----> [3,4,6,8] - threshold = 3, divisor = 2 ===> result globalMinOperations= 5
                                 1 2 3 4
                                 0 1 1 2
                                   0 0 1
                                       0
                             --> Now, due to having sorted array I will reach the same value in less operations as I am starting will less elements first and procceed
                                 to greater values. and so on .
*/

#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
int minOperations(int arr_count, int* arr, int threshold, int d)
{
    //return value of minimum operations, will be initialized to max integer value
    //this will consider the first time to reach threshold as the starting minimum of operations as it will be for sure less that INT_MAX
    int globalMinOperations = INT_MAX;

    //insertionSort for input array
    int j = 0;
    int temp = 0;
    for (int i = 1; i < arr_count; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
        arr[j + 1] = arr[j];
        j--;
        }
        arr[j + 1] = temp;
    }
    
    //Create the dictionary in which i will record values reached and their attributes (specifications)
    // { (0)[threshold,Operations], (1)[threshold,Operations], (2)[threshold,Operations], .......etc , (LargestElementValue)[threshold,Operations]}
    //ofcoures the dictionary will cover each integer value below the maximum value in the array
    // allocation implement dictionary size to be  maxNum+1 because maxNum will be represented in the dictionary as index, and indexing starts from zero :D
    int maxNum = arr[arr_count-1];
    int **dictionary = (int **)malloc( (maxNum+1) * sizeof(int *) ) ; 
    for (int i=0; i<maxNum+1; i++) 
         dictionary[i] = (int *)calloc(2 , sizeof(int));

    //loop through each element in the input array
    for (int i = 0; i < arr_count; i++)
    {
        int localMinOperations = 0;
        int currentValue = arr[i];
        while (1)
        {   
            dictionary[currentValue][0] += 1; // current threshold for index currentValue, note that we use += to accumelate local threshold on previous values for this specific index
            dictionary[currentValue][1] += localMinOperations; // current steps to reach this index value, note that we use += to accumelate...etc
            
            //if any index value reached the required threshold, then compare its (reaching operations) with current global 
            if (dictionary[currentValue][0] >= threshold)
                globalMinOperations = MAX(globalMinOperations, dictionary[currentValue][1]);    

            if (currentValue == 0)
                break;
                
            currentValue /= d;
            localMinOperations += 1;
        }
    }
    return globalMinOperations;
}

int main()
{
  int arr[] = {6,3,8,4};
  int arr_count = sizeof(arr)/sizeof(arr[0]);
  int threshold = 3;
  int d = 2;
  int globalMinOperations = minOperations(arr_count, arr, threshold, d);
  printf("%d\n", globalMinOperations);

  int r = 0;
  scanf("%d", &r);
  return 0;
}