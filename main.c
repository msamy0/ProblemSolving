//find the most frequent memeber in a given array of integers
// if there are more than one most frequent members, return the smallest one
// if there is no most frequent member, return any thing
#include <stdio.h>
#ifdef _WIN32
    #define WINPAUSE system("pause")
#endif
int findFrequent(int arr[], int n)
{
    int max_count =0;
    int index_of_max_count = -1;

    for (int i = 0 ; i < n ; ++i)
    {
        if (arr[i] == index_of_max_count)
            continue;
        
        int count = 0;
        for (int j = 0 ; j < n ; ++j)
        {
            if (arr[i] == arr [j])
            {
                count++;
            }
        }

        if ((count > max_count) || ((count == max_count) && (arr[i] < index_of_max_count)) )
        {
            max_count = count;
            index_of_max_count = arr[i];
        }


    }
    return index_of_max_count;

}
int main ()
{
    printf("Hello World");
    getchar();
    return 0;
}
