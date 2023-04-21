#include <stdio.h>
#include <math.h>

int main(void)
{
	unsigned long long n,m,a;
	scanf("%llu %llu %llu",&n,&m,&a);
	double x1 =ceil( ((double)n/(double)a) );
	double x2 =ceil( ((double)m/(double)a) );
	
	printf("%llu", (unsigned long long)x1 * (unsigned long long)x2);


}
