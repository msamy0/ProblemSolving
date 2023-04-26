#include <stdio.h>
#include <stdlib.h>
long* findSum(int numbers_count, int* numbers, int queries_rows, int queries_columns, int** queries, int* result_count) {
    
    long * ResArray = (long*)malloc(queries_rows * (sizeof (long)));
    for(int i = 0 ; i < queries_rows ; i++)
        ResArray[i] = 0;
    
    long * flagArr = (long*)malloc(numbers_count * (sizeof (long)));
    for(int i = 0 ; i < numbers_count ; i++)
        flagArr[i] = 0;
    
    long* prefix_sum = (long*) malloc((numbers_count + 1) * sizeof(long));
    prefix_sum[0] = 0;
    for (int i = 0; i < numbers_count; i++) {
        if (numbers[i]== 0)
            {
                flagArr[i] = 1;
            }
        prefix_sum[i + 1] = prefix_sum[i] + numbers[i];
    }
        for (int i = 0 ; i <queries_rows  ; i++)
        {

        }
        for (int i = 0 ; i <queries_rows  ; i++)
        {  
            int startIndex = (queries[i][0] -1);
            int endIndex = (queries[i][1] -1);
            long sum = prefix_sum[endIndex + 1] - prefix_sum[startIndex];
        
            sum += queries[i][2] * flagArr[i];  

            ResArray[i] +=  sum;       
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
    
    /*
    queries
    2 2 20
    2 5 100
    3 4 100

    */
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