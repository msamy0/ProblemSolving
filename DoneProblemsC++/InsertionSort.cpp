#include <iostream>
#include <string>
#include <chrono>

using namespace std;
template <class T>
void swap(T *a, T *b)
{
  T temp = a;
  a = b;
  b = temp;
}

template <class T>
void InsertionSort_Swap( T a[], int size)
{
  for (int i= 1 ; i<size ; i++)
  {
    int j = i-1;
    int k = i;
    while(a[k] < a[j] && j >=0)
    {
        swap(a[k],a[j]);
        j--;
        k--;
    }
  }
}
template <class T>
void InsertionSort_Shift( T a[], int size)
{
  T temp;
  for (int i= 1 ; i<size ; i++)
  {
    temp = a[i];
    int j = i-1;
    while(temp < a[j] && j >=0)
    {
        a[j+1] = a[j];
        j--;
    }
    a[j+1] = temp;
  }
}
int main() {
    string str="";
    int const size = 24;

    /* Test 1*/
    int a[size] = {50,31,21,28,72,41,73,93,68,43,45,78,5,17,97,71,69,61,88,75,99,44,55,9};
    InsertionSort_Swap(a,size);
    for (int i=0; i<size; i++){
      str += to_string(a[i]) + " ";
    }
    cout << str << endl;
    cout << "0-----------------------------------------------------------------------------0" << endl;

    /* Test 2*/
    str="";
    int b[size] = {50,31,21,28,72,41,73,93,68,43,45,78,5,17,97,71,69,61,88,75,99,44,55,9};
    InsertionSort_Shift(b,size);
    for (int i=0; i<size; i++){
      str += to_string(b[i]) + " ";
    }
   cout << str << endl;
    


  return 0;
}