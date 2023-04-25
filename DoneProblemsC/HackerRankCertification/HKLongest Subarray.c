/*

*/

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define USE_EXE_TIME_CALC 0

#define PRINT_SUB_ARRAY 0
#define MAXSIZE 35
typedef struct {
    int currentArr[MAXSIZE];
    int currentLastIdx;
    int LBigArr[MAXSIZE];
    int LBigLastIdx;
} cacheArray_t;
void SaveCurrentMax(cacheArray_t *arr)
{
    for(int i=0; i <= arr->currentLastIdx; i++)
    {
        arr->LBigArr[i]=arr->currentArr[i];
    }
    arr->LBigLastIdx = arr->currentLastIdx;
}

void shiftLeftArr(int *arr, int* lastIdx, int shiftVal)
{   if( shiftVal > lastIdx){
        *lastIdx = -1;
    }
    else{
        for(int i=0; i<= ((*lastIdx)-shiftVal); i++)
        {
            arr[i] = arr[i+shiftVal];
        }
        *lastIdx = *lastIdx -shiftVal;
    }

}
int longestSubarray(int arr_count, int* arr) {
    cacheArray_t subArr;
    subArr.currentLastIdx = -1;
    subArr.LBigLastIdx = -1;

    int allowDir = 0;
    for(int i=0; i<arr_count; i++)
    {
        if (subArr.currentLastIdx > 0) {
            int temp = arr[i] - subArr.currentArr[subArr.currentLastIdx];
            if ( (temp == 0 || abs(temp) == 1) && (allowDir * temp >= 0 ) ) {
                allowDir = (temp == 0) ? allowDir : -temp;
                subArr.currentLastIdx++;
                subArr.currentArr[subArr.currentLastIdx] = arr[i];
            }
            else {
                if (subArr.currentLastIdx > subArr.LBigLastIdx) {
                    SaveCurrentMax(&subArr);
                }
                if (abs(temp) >= 2) {
                    subArr.currentLastIdx = 0;
                    subArr.currentArr[subArr.currentLastIdx] = arr[i];
                    allowDir = 0;  
                }
                else {
                    int countOfShifts = 0;
                    int k = 0;
                    for (k = 0 ; k <= subArr.currentLastIdx ; k++) {
                        if (abs(arr[i] - subArr.currentArr[k]) > 1)
                           countOfShifts = k+1; 
                    }
                    shiftLeftArr(subArr.currentArr, &subArr.currentLastIdx, countOfShifts);
                    subArr.currentLastIdx++;
                    subArr.currentArr[subArr.currentLastIdx] = arr[i];
                    allowDir = (subArr.currentLastIdx >= 0) ? allowDir : 0;      
                }
            }
            continue;
        }
        else if (subArr.currentLastIdx == 0) {
            int temp = arr[i] - subArr.currentArr[subArr.currentLastIdx];
            if ( (temp == 0 || abs(temp) == 1) && (allowDir * temp >= 0 ) ) {
                allowDir = (temp == 0) ? allowDir : -temp;
                subArr.currentLastIdx++;
                subArr.currentArr[subArr.currentLastIdx] = arr[i];
            }
            else {
                if (subArr.currentLastIdx > subArr.LBigLastIdx){
                    SaveCurrentMax(&subArr);
                }
                subArr.currentLastIdx = 0;
                subArr.currentArr[subArr.currentLastIdx] = arr[i];
                allowDir = 0;
            }
            continue;
        }
        else if (subArr.currentLastIdx == -1) {  
            subArr.currentLastIdx++;
            subArr.currentArr[0] = arr[i];
            continue;
        }
    }
    if (subArr.currentLastIdx > subArr.LBigLastIdx){
        SaveCurrentMax(&subArr);
    }
    #if PRINT_SUB_ARRAY == 1
        for(int i=0; i<=subArr.LBigLastIdx; i++)
        {
            printf("%d ", subArr.LBigArr[i]);
        }
        printf("\n");
    #endif
    return subArr.LBigLastIdx+1;

}
int main()
{
    #if USE_EXE_TIME_CALC == 1
        double time_spent = 0.0;
        clock_t begin = clock();
    #endif

    int arr_count = 149;
    /*
    array input
195593459
195593459
195593458
195593457
195593459
195593459
195593458
195593459
195593458
195593459
195593457
195593458
195593458
195593457
195593457
195593457
195593457
195593458
195593457
195593459
195593457
195593457
195593458
195593457
195593457
195593458
195593458
195593457
195593458
195593457
195593457
195593457
195593459
195593459
195593459
195593458
195593458
195593458
195593458
195593458
195593457
195593459
195593459
195593458
195593457
195593459
195593459
195593457
195593459
195593459
195593457
195593457
195593459
195593459
195593457
195593459
195593458
195593458
195593458
195593457
195593458
195593458
195593458
195593458
195593457
195593458
195593459
195593458
195593459
195593458
195593459
195593458
195593458
195593459
195593459
195593458
195593457
195593459
195593459
195593459
195593459
195593457
195593459
195593459
195593459
195593459
195593459
195593457
195593459
195593457
195593458
195593457
195593458
195593458
195593457
195593459
195593457
195593457
195593459
195593457
195593459
195593459
195593458
195593457
195593459
195593458
195593459
195593459
195593458
195593458
195593459
195593458
195593459
195593458
195593457
195593459
195593458
195593457
195593457
195593457
195593458
195593457
195593459
195593457
195593458
195593459
195593458
195593458
195593459
195593457
195593459
195593459
195593459
195593458
195593459
195593458
195593458
195593459
195593458
195593459
195593458
195593457
195593457
195593457
195593459
195593458
195593459
195593458
195593457
    */
    int arr[] = {195593459,195593459,195593458,195593457,195593459,195593459,195593458,195593459,195593458,195593459,195593457,195593458,195593458,195593457,195593457,195593457,195593457,195593458,195593457,195593459,195593457,195593457,195593458,195593457,195593457,195593458,195593458,195593457,195593458,195593457,195593457,195593457,195593459,195593459,195593459,195593458,195593458,195593458,195593458,195593458,195593457,195593459,195593459,195593458,195593457,195593459,195593459,195593457,195593459,195593459,195593457,195593457,195593459,195593459,195593457,195593459,195593458,195593458,195593458,195593457,195593458,195593458,195593458,195593458,195593457,195593458,195593459,195593458,195593459,195593458,195593459,195593458,195593458,195593459,195593459,195593458,195593457,195593459,195593459,195593459,195593459,195593457,195593459,195593459,195593459,195593459,195593459,195593457,195593459,195593457,195593458,195593457,195593458,195593458,195593457,195593459,195593457,195593457,195593459,195593457,195593459,195593459,195593458,195593457,195593459,195593458,195593459,195593459,195593458,195593458,195593459,195593458,195593459,195593458,195593457,195593459,195593458,195593457,195593457,195593457,195593458,195593457,195593459,195593457,195593458,195593459,195593458,195593458,195593459,195593457,195593459,195593459,195593459,195593458,195593459,195593458,195593458,195593459,195593458,195593459,195593458,195593457,195593457,195593457,195593459,195593458,195593459,195593458,195593457};
    printf("result ");
    int result = longestSubarray(arr_count, arr);
    printf("result = %d", result);


    #if USE_EXE_TIME_CALC == 1
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("time spent = %f\n",time_spent);
    #endif
    
    //pause terminal
    int r=0;
    scanf("%d", &r);
   
       return 0;
}