#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 100001
int countDistinctElements(int freq[], int freqSize) {
    int count = 0;
    for (int i = 0; i < freqSize; i++) {
        if (freq[i] > 0) {
            count++;
        }
    }
    return count;
}
int findLongestSubarrayWithAtMostTwoDistinctNumbers(int nums[], int numsSize) {
    int left = 0, maxLength = 0;
    int freq[MAX_SIZE] = {0};
    for (int right = 0; right < numsSize; right++) {
        freq[nums[right]]++;
        while (countDistinctElements(freq, MAX_SIZE) > 2 && left < right) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                freq[nums[left]] = -1;
            }
            left++;
        }
        if (countDistinctElements(freq, MAX_SIZE) == 1) {
            maxLength = maxLength > right - left + 1 ? maxLength : right - left + 1;
        }
        else if (countDistinctElements(freq, MAX_SIZE) == 2) {
            int distinctNums[2];
            int distinctNumsIdx = 0;
            for (int i = 0; i < MAX_SIZE; i++) {
                if (freq[i] > 0) {
                    distinctNums[distinctNumsIdx++] = i;
                }
            }
            if (abs(distinctNums[0] - distinctNums[1]) <= 1) {
                maxLength = maxLength > right - left + 1 ? maxLength : right - left + 1;
            }
        }
    }
    return maxLength;
}

int main()
{
    int arr_count = 10;
    int *arr = (int*)malloc(arr_count * sizeof(int));
    arr[0]  = 3;
    arr[1]  = 1;
    arr[2]  = 5;
    arr[3]  = 2;
    arr[4]  = 2;
    arr[5]  = 5;   
    arr[6]  = 3;
    arr[7]  = 9;
    arr[8]  = 8;
    arr[9]  = 9;



    int result = findLongestSubarrayWithAtMostTwoDistinctNumbers(arr, arr_count);
    printf("%d\n", result);

    int x =0;
    scanf("%d", &x);
    return 0;
}

