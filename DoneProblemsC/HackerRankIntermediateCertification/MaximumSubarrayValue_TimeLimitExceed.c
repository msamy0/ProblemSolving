#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//Time Limit Exceed


#define ABS(x) ((x) < 0 ? -(x) : (x))
long maxSubarrayValue(int arr_count, int *arr) {

long* prefix_sum_even = (long*) calloc((arr_count+1) , sizeof(long));
long* prefix_sum_odd = (long*) calloc((arr_count+1) , sizeof(long));

for (int i =1 ; i < arr_count+1 ; i++){
    if (i%2 == 0){
        prefix_sum_even[i] = arr[i-1];
    }      
    else if (i%2 != 0){
        prefix_sum_odd[i] = arr[i-1];
    }
    prefix_sum_even[i] += prefix_sum_even[i-1];
    prefix_sum_odd[i] += prefix_sum_odd[i-1];
}

long sum =0;
long max_sum = 0;
for (int i =arr_count ; i >=0 ; i--){
    for (int j =i ; j >=0 ; j--){
        sum = ABS( (prefix_sum_even[i]- prefix_sum_even[j])-(prefix_sum_odd[i]- prefix_sum_odd[j]) );
        if(sum > max_sum)
            max_sum = sum;
    } 
}
return max_sum * max_sum;
}

int main() {
/*
Test Cases:
int arr_count = 40;
int arr[40] = {910,-240,338,-689,892,-518,663,447,796,716,-830,-465,835,426,88,-49,-810,-159,326,-345,-925,97,-371,496,921,693,526,785,-218,-939,119,935,-994,510,716,513,-18,-202,943};

int arr_count = 94;
int arr[95] = {654,-940,629,592,529,618,403,-497,-538,-996,496,-499,80,768,714,-346,-477,883,-527,-116,-362,-462,389,818,-470,-124,-523,650,-651,-58,-854,-85,947,974,-789,651,-369,-88,154,-660,-412,-516,-395,-424,-80,743,-603,371,153,393,450,276,-209,-25,-704,673,-926,621,-636,787,-214,-84,-584,551,427,759,355,-120,675,-690,176,244,205,471,434,667,511,723,628,-846,-896,560,-661,-252,-53,-432,-8,-792,681,496,914,-208,-420,-331};
*/
int arr_count = 6;
int arr[6] = {5,-1,2,3,4,-5}; 
long max = maxSubarrayValue(arr_count, arr);
printf("%ld", max);
int r=0;
scanf("%d", &r);
return 0;
}