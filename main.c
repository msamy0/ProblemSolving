//@msamygawad
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

/*
int const print()
{
    printf("AA");
    int r = 0;
    scanf("%d", &r);
    return r;
}
*/

/*
//24
typedef struct {
unsigned int x;
unsigned char y;
struct tPOSITION* NextPosition;
}tPOSITION;
tPOSITION p1 = {3};
tPOSITION p2 = {4,5};
tPOSITION p3 = {5};

p1.NextPosition = &p2;
p2.NextPosition = &p3;
printf("%d, %i, %i\n", p1.y, p2.NextPosition==&p3, (&p3)->x);
*/

/*
    uint32_t x = 2;
    uint32_t* ptr = &x;
    static uint32_t i = x;

    printf("%i, %i, %i\n", *ptr, i, x);
    //compilation error
*/

/*
//it is gonna work as x = (n++,n) is accepted in C syntax just like x = ++n;
void reverse(int i)
{
if (i> 5)
    return;
printf("%d", i);
return reverse((i++,i));
}

int main(void) {
reverse(1);


    int r = 0;
    scanf("%d", &r);
    
    return 0;
}
*/

#include <stdio.h>
void solve() {
    int first = 10, second = 20;
    int third = first + second;
    {
        int third = second - first;
        printf("%d ", third);
    }
    printf("%d", third);
}
int main() {
	#ifdef HELLO
        printf("Hello, World!\n");
    #endif
	return 0;
}