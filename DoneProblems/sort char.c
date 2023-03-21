/* liner sort*/
#include <stdio.h>
#include <string.h>
int main() {
    char input[10]= {'r','e','t','g','c','u','l','o','r','e'};

    for (int i = 0 ; i<10 ; i++)
    {
    	for (int j = i+1 ; j < 10 ; j++)
    	{
			if ((int)input[i] > (int)input[j] )
			{
				input[i] = input[i] ^ input[j];
				input[j] = input[i] ^ input[j];
				input[i] = input[i] ^ input[j];
			}
    	}

    }
    return 0;
}






