
#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
/*
in thins example the required output is to just calculate the maximum amount you can get out of the upper left quarter of the matrix
if you attempt to use USE_FLIPPING = 1 you will get the same answer but also will flip the matrix rows and columns to get the maximum 
values in the top left quarter of the matrix then sum them up.
*/

/*
    row_size = column_size = even number = 2n
    maximize topleft quarter of the matrix
*/
#define X_item 0
#define Y_item 1
#define USE_FLIPPING 0
typedef enum {ROW, COLUMN} itemType_t;
void reverseArray(int **arr,int size, int itemIndex, itemType_t itemType)
{
    
    if (itemType == ROW)
    {
        for (int i = 0 ; i < size/2 ; i++)
        {
            int temp = arr[itemIndex][i];
            arr[itemIndex][i] = arr[itemIndex][size-1 - i];
            arr[itemIndex][size-1 - i] = temp;
        } 
    }
    else if (itemType == COLUMN)
    {
        for (int i = 0 ; i < size/2 ; i++)
        {
            int temp = arr[i][itemIndex];
            arr[i][itemIndex] = arr[size-1 - i][itemIndex];
            arr[size-1 - i][itemIndex] = temp;
        } 
    }

}

int flippingMatrix( int row_size , int column_size, int** matrix )
{
    int quarterLen = row_size/2; // = column_size/2
    int max_Sum_beforeRearrange=0;
    int max_Sum_afterRearrange=0;
    for (int i = 0 ; i < quarterLen ; i++)
    {
        for (int j = 0 ; j < quarterLen ; j++)
        {
           
            int i_x = row_size-1 -i;
            int j_x = column_size-1 - j;

            int max1[2];
                if (matrix[i][j] > matrix[i][j_x])
                    {max1[X_item] = i;max1[Y_item]=j;}
                else
                    {max1[X_item] = i;max1[Y_item]=j_x;}

            int max2[2];
                if (matrix[i_x][j] > matrix[i_x][j_x])
                    {max2[X_item] = i_x;max2[Y_item]=j;}
                else
                    {max2[X_item] = i_x;max2[Y_item]=j_x;}

            int maximumXY[2];
                if( matrix[max1[X_item]][max1[Y_item]] > matrix[max2[X_item]][max2[Y_item]])
                    {maximumXY[X_item] = max1[X_item] ; maximumXY[Y_item] = max1[Y_item];}
                else
                    {maximumXY[X_item] = max2[X_item] ; maximumXY[Y_item] = max2[Y_item];}
            /* Row of max number = maximum[0]   Col of max number = maximum[1] */

            max_Sum_beforeRearrange += matrix[maximumXY[X_item]][maximumXY[Y_item]];

            #if USE_FLIPPING
            /******************** Start of row and columns reversion ********************************************/
            /****************************************************************************************************/
            /* Check whether flipping needed ? */
            if (i == maximumXY[X_item] && j == maximumXY[Y_item])
                continue;
            
            // 0- bring max number to the top right index 
            if(maximumXY[Y_item] == j) // if max number is in the left bottom of the matrix
                {
                    reverseArray(matrix,row_size, maximumXY[X_item], ROW);
                    reverseArray(matrix,column_size, column_size-1 - maximumXY[Y_item], COLUMN);
                }
            else if ( maximumXY[X_item] !=i && maximumXY[Y_item] != j) // if max number is in the right bottom of the matrix
                {
                    reverseArray(matrix,column_size,maximumXY[Y_item], COLUMN);
                }

            // 1- reverse row of element in interest
            reverseArray(matrix,row_size,i, ROW);
            
            // 2- reverse columns of left top quarter
            for(int r =0 ; r < column_size/2 ; r++)
                reverseArray(matrix,column_size,r, COLUMN);
            
            // 3- reverse the mirrorRow of row of interset in top left quarter
            reverseArray(matrix,row_size,row_size-1 - i, ROW);

            //4- reverse columns of left top quarter again
            for(int r =0 ; r < column_size/2 ; r++)
                reverseArray(matrix,column_size,r, COLUMN);

            //5- reverse mirrorColumn of column in interest at top right quarter
            reverseArray(matrix,column_size,column_size-1 - j, COLUMN);

            //6- reverse row of interest in to left quarter
            reverseArray(matrix,row_size,i, ROW);

            #endif
        }
    }
    
    #if USE_FLIPPING
        for (int i = 0 ; i <quarterLen ; i++ )
        {
            for (int j = 0 ; j <quarterLen ; j++ )
            {
            max_Sum_afterRearrange += matrix[i][j]; 
            }
        }
        return max_Sum_afterRearrange;
    #else
        return max_Sum_beforeRearrange;
    #endif
    
}


int main (void)
{
    double time_spent = 0.0;
    clock_t begin = clock();
    int n = 4;
    int **arr = (int**)malloc(n*sizeof(int*));
    for (int i = 0 ; i < n ; i++)
    {
        arr[i] = (int*)malloc(n*sizeof(int));
    }

    arr[0][0] = 112;
    arr[0][1] = 42;
    arr[0][2] = 83;
    arr[0][3] = 119;
    arr[1][0] = 56;
    arr[1][1] = 125;
    arr[1][2] = 56;
    arr[1][3] = 49;
    arr[2][0] = 15;
    arr[2][1] = 78;
    arr[2][2] = 101;
    arr[2][3] = 43;
    arr[3][0] = 62;
    arr[3][1] = 98;
    arr[3][2] = 114;
    arr[3][3] = 108;

/*
1   2   3   4   5   6
7   8   9   10  11  12
13  14  15  16  17  18
19  20  21  22  23  24
25  26  27  28  29  30
31  32  33  34  35  36
*/

    int sum = flippingMatrix(arr,n,n);
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("sum = %d\n",sum);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n",time_spent);

}
