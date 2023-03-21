#include <stdlib.h>
#include <stdio.h>

int inspect_bits(unsigned int number)
{
    // Waiting to be implemented
  int count=0;
  for(int i = 0 ; i<32 ; i++)
  {
    if(number>>1 & 1 )
    {
      count ++;
    }
    else
    {
      count = 0;
    }

    if ( count >=2)
    {
      return 1;
    }
  }
  return 0;
}

#ifndef RunTests
int main ()
{
    printf("%d", inspect_bits(7576));
}
#endif
