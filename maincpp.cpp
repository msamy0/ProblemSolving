#include <iostream>
using namespace std;

void func(int *a , int *b)
{
    int temp1 = *a;
    int temp2 = 1;
    
  
        for (int i = 0 ; i < *b ; ++i)
        {
            temp2 = temp2 * temp1;
        }

        *a = temp2;
        if (*b == 0)
        {}
        else
        {
        *b = (*a) % (*b) ;
        }
}

int main() {
    int x = 2;
    cout << x << "Hello, World!" << endl;
    int a = 2;
    int b = 3;
    func (&a , &b);
   cout << a << "  " << b << endl;
}