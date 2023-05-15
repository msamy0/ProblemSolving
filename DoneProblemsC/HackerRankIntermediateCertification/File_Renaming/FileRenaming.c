//@msamygawad
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>


#define M 1000000007
int renameFile(char *newName, char *oldName){
    int oldNameLen = strlen(oldName);
    int newNameLen = strlen (newName); 
    long* subStringOccArr = (long*)calloc(oldNameLen +1 , sizeof(long));
    long* globalOccArr    = (long*)calloc(oldNameLen +1 , sizeof(long));    
    for (int i = 0 ; i < oldNameLen +1 ; i++)
        globalOccArr[i] = 1;
    for(int i = 1 ; i < newNameLen+1 ; i++)
    {
        for(int k = 0 ; k < oldNameLen+1 ; k++)
            subStringOccArr[k] = 0;
        for (int j = i ; j < oldNameLen+1 ; j++)
        {
            subStringOccArr[j] = subStringOccArr[j-1];
            if(newName[i-1] == oldName[j-1])
                subStringOccArr[j] += globalOccArr[j];
        }
        for (int k = 0 ; k < oldNameLen+1 ; k++)
            globalOccArr[k] = subStringOccArr[k];
    }
    return globalOccArr[oldNameLen] % M;

}
int main()
{
  // test cases for renameFile
  char *newName = "aba";
  char *oldName = "ababa";
  printf("%d\n", renameFile(newName, oldName));


  int r = 0;
  scanf("%d", &r);
  return 0;
}