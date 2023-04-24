#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compareTwoStrings(int stringLen, char* query, char* dictionary) {
    // Create a hash table to store the letters in the dictionary word
    int hash[26] = {0};
    for (int i = 0; i < stringLen; i++) {
        hash[dictionary[i] - 'a']++;
    }

    // Check if each letter in the query word is in the hash table
    for (int i = 0; i < stringLen; i++) {
        if (hash[query[i] - 'a'] == 0) {
            return 0;
        }
    }

    return 1;
}

/*
int compareTwoStrings(int stringLen, char *query , char* dictionary)
{
    int matchFlagLetter =0;
    for (int k = 0 ; k < stringLen ; k++) // for each letter in query word
        {
            matchFlagLetter =0;
            for (int r = 0 ; r <stringLen ; r++) // for each letter in dic word
            {
                if (query[k] == dictionary[r]) 
                {
                    matchFlagLetter = 1;
                    break;
                }
            }
            if(matchFlagLetter == 0)
                break;     
        }

        if (matchFlagLetter == 0)
            return 0;
        else 
            return 1;
}
*/

int* stringAnagram(int dictionary_count, char** dictionary, int query_count, char** query, int* result_count) {
    
    int * result_array = malloc(query_count * sizeof(int));
    for (int i = 0 ; i < query_count ; i ++)
        result_array[i] = 0; 
    

    for (int i = 0 ; i < query_count ; i ++) // for each word in query
    {
        int stringLen = strlen(query[i]); // get lenght of word
        int counterOfMatches = 0;
        for(int j = 0; j < dictionary_count; j++) // for each word in dic
        {
            if ( strlen(dictionary[j]) == stringLen) // if matched count of letters
            {
              if (compareTwoStrings(stringLen, query[i], dictionary[j]) == 1)
                {
                    counterOfMatches++;
                }
            }
        }
        result_array[i] = counterOfMatches;
    }
    *result_count = query_count;
    return result_array;
    
}
int main()
{
    char string1 [5] = "abffe";
    char string2 [5] = "efbaf";
    int result = compareTwoStrings(5, string1, string2);
    printf("%d", result);
    int r = 0;
    
    scanf("%d", &r);
   
       return 0;
}