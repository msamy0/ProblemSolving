#include <math.h>
#include <stdio.h>
// Insertion Sort Function
void SWAP(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;

}
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
void insertionSort(int array[], int n)
{
  int j = 0;
  int temp = 0;
  for (int i = 1; i < n; i++)
  {
    temp = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > temp)
    {
      array[j + 1] = array[j];
      j--;
    }

    array[j + 1] = temp;
  }
}
void bubbleSort(int array[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (array[j] > array[j + 1])
        SWAP(&array[j], &array[j + 1]);
    }
  }
}
void selectionSort(int array[], int n)
{
  int current_min = 0;
  for (int i = 0; i < n-1; i++)
  {
    current_min = i;
    for (int j = i+1; j < n; j++)
    {
      if(array[j] < array[current_min])
        current_min = j;
    }
    SWAP(&array[i],&array[current_min]);
  }
}
void rearrange_array_randomly(int array[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int j = rand() % n;
    SWAP(&array[i], &array[j]);
  }
}

void randomize_array(int array[], int n)
{
  for (int i = 0; i < n; i++)
  {
    array[i] = rand() % 100;
  }
}
// Function to print the elements of an array
void printArray(int array[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", array[i]);
  printf("\n");
}
// Main Function
int main()
{
  int xr;
  int fr;
  if(1)
  {
    fr = 5;
  }
  int array[] = {122, 17, 93, 3, 56, 66, 89, 65, 21, 0, 1, 5, 3};
  int n = sizeof(array) / sizeof(array[0]);

  selectionSort(array, n);
  printArray(array, n);

  rearrange_array_randomly(array, n);
  printArray(array, n);
  bubbleSort(array, n);
  printArray(array, n);

  rearrange_array_randomly(array, n);
  printArray(array, n);
  insertionSort(array, n);
  printArray(array, n);

  return 0;
}