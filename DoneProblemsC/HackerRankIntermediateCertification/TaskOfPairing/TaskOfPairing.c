@msamygawad
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

long taskOfPairing(int freq_count, long *freq)
{
  int oddFlag = 0;
  long globalPairesCnt = 0;
  for (int i = 0; i < freq_count; i++)
  {
    if (freq[i] != 0)
    {
      globalPairesCnt += freq[i] / 2;
      if (freq[i] % 2 != 0 && oddFlag == 1) //if odd and having reminder of 1
      {
        globalPairesCnt++;
        oddFlag = 0;
      }
      else if (freq[i] % 2 != 0) //else if it is odd and no reminder stored
      {
        oddFlag = 1;
      }
    }
    else // if curren freq equals zero, then it doesn't matter if i have reminder or not. i will set it to zero any way
    {
      oddFlag = 0;
    }
  }
  return globalPairesCnt;
}

int main()
{
  //test cases for taskOfPairing
  #define freq_count 9
  long freq[freq_count] = {10, 20, 20, 10, 10, 30, 50, 10, 20};
  long res = taskOfPairing(freq_count, freq);
  printf("res = %ld\n", res);
  int r = 0;
  scanf("%d", &r);
  return 0;
}