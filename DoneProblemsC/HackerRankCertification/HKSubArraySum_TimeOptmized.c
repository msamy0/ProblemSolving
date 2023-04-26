#include <stdio.h>
#include <stdlib.h>

/* Created By : Mohamed Samy - @msamy0 */
/* Commented in help of Github@Copilot */


long* findSum(int numbers_count, int* numbers, int queries_rows, int queries_columns, int** queries, int* result_count) {
    //Dynamically create an array of longs to store the results and initialize it to 0 each element using calloc()
    long * ResArray = (long*)calloc(queries_rows , (sizeof (long)));
    //Dynamically create an array of longs to store accumelated zero counts, this array will exceed the size of numbers array by 1
    //as the first element will be 0 and the last element will be the accumelated zero count of the numbers array
    // numbers[] ->      1,0,2,0,0,3,5,0
    // zeroFlagArr[] ->  0,1,1,2,2,3,3,4,4
    long * zeroFlagArr = (long*)calloc(numbers_count+1 , (sizeof (long)));
    //same as the zeroFlagArr but this array will store the accumelated sum of the numbers array
    // numbers[] ->      1,0,2,0,0,3,5,0
    // prefix_sum[] ->   0,1,1,3,3,3,6,11,11
    long* prefix_sum = (long*) malloc((numbers_count + 1) * sizeof(long));
    zeroFlagArr[0] =0;//first element of zeroFlagArr is 0, as nothing before index 0 in numbers[] to consider !
    prefix_sum[0] = 0;//first element of prefix_sum is 0, as nothing before index 0 in numbers[] to sum up !
    //loop through the numbers array and fill the zeroFlagArr and prefix_sum arrays
    //this is done one time only every function call to be used in the queries loop
    for (int i = 0; i < numbers_count; i++) {
        //if currnet numbers[] element == 0, then the next element in the zeroFlagArr will be the previous element + 1
        //note here we exceed i by one for both arrays as we accumelate what is behine in numbers[] array
        if (numbers[i]== 0) {
            zeroFlagArr[i+1] = zeroFlagArr[i] +1;
        }
        //else if it is any other number, then just use the last index value
        else{
            zeroFlagArr[i+1] = zeroFlagArr[i];
        }
        //fill the prefix_sum array with the accumelated sum of the numbers array
        prefix_sum[i + 1] = prefix_sum[i] + numbers[i];
    }
    //loop the queries input 
    for (int i = 0 ; i <queries_rows  ; i++) { 

        int startIndex = (queries[i][0] -1);// -1 because the input is indexing from 1 not 0
        int endIndex = (queries[i][1] -1);// -1 because the input is indexing from 1 not 0

        //index             0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10,11,12
        // numbers[] ->     1 ,2 ,3 ,4 ,5 ,0 ,5 ,0 ,6 ,8 ,0 ,0 ,9
        //                    |<-------[1] to [9]------->|  
        // prefix_sum[] ->  0 ,1 ,3 ,6 ,10,15,15,20,20,26,34,34,34,43
        //              sum+= |<-------[10]-[1]------------>|                         
        // zeroFlagArr[] -> 0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,2 ,2 ,2 ,3 ,4 ,4
        //              sum+= |<----{(2)-(0)} x load------->|
        long sum = prefix_sum[endIndex + 1] - prefix_sum[startIndex];
        sum += ((zeroFlagArr[endIndex+1] - zeroFlagArr[startIndex]) * queries[i][2] );  
        ResArray[i] =  sum;       
    } 
    free(prefix_sum);

    *result_count = queries_rows;
    return ResArray;
}
int main()
{
    int numbers_count = 2;
    int numbers[] = {-5,0};
    int queries_rows = 2;
    int queries_columns = 3;

    int **queries = (int**)malloc(queries_rows * sizeof(int*));
    for (int i = 0; i < queries_rows; i++)
        queries[i] = (int*)malloc(queries_columns * sizeof(int));
    
    queries[0][0] = 2;
    queries[0][1] = 2;
    queries[0][2] = 20;
    queries[1][0] = 1;
    queries[1][1] = 2;
    queries[1][2] = 10;

    int result_count;
    long* result = findSum(numbers_count, numbers, queries_rows, queries_columns, queries, &result_count);
    for (int i = 0; i < result_count; i++) {
        printf("%ld \n", result[i]);
    }
    scanf( "%d" , &result_count);
    return 0;
}