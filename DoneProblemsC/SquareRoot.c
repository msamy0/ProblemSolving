#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double squareRootNewotenMethod(double x){
    double root = x / 3.0;
    double last;
    do {
        last = root;
        root = (root + (x / root)) / 2.0;
    } while (root != last);
    return root;
}
double squareRootBinaryMethod(int x){
    double low = 0.0;
    double high = x;
    double mid = 0.0;
    double result = 0.0;
    double precision = 0.0000001;
    while (high - low > precision) {
        mid = (low + high) / 2;
        result = mid * mid;
        if (result > x)
            high = mid;
        else if (result < x)
            low = mid;
        else
            return mid;
    }
    return mid;
}
int main()
{
double x = 64.0;
double result = squareRootNewotenMethod(x);
printf("The square root of %f is %f\n", x, result);
result = squareRootBinaryMethod(x);
printf("The square root of %f is %f\n", x, result);
    int i = 0;
    scanf( "%d" , &i);
    return 0;
}