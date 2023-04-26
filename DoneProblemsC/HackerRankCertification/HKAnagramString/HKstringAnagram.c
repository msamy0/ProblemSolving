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
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC

#define USE_EXE_TIME_CALC 0
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
********* this function is not used in the final solution *********
int compareTwoStrings(int *DictionaryHashTable ,int stringLen, char* query) {
    // Check if each letter in the query word is in the hash table
    for (int i = 0; i < stringLen; i++) {
        if (DictionaryHashTable[query[i] - 'a'] == 0) {
            return 0;
        }
    }
    return 1;
}
*/
int* stringAnagram(int dictionary_count, char** dictionary, int query_count, char** query, int* result_count) {
    
    //create array of numbers to hold result of each query
    int * result_array = calloc(query_count , sizeof(int));

    //create hash table for each word in dictionary
    //Allocate memory for 2D array
    int **DictionaryHashTable = malloc(dictionary_count * sizeof(int*));

    //loop for each row in tha matrix and allocate 26 item for each row and initialize them to 0 using calloc()
    for (int i = 0 ; i < dictionary_count ; i ++)
    {
        //using calloc() to create and initialize all elements to 0
        DictionaryHashTable[i] = calloc(26 , sizeof(int));
        //loop through each letter in the word and increment the corresponding index in the hash table
        //terminate when reach end of word (charcter '\0')
        for (int j = 0 ; dictionary[i][j] != '\0' ; j++)
        {
            DictionaryHashTable[i][dictionary[i][j] - 'a']++;
        }
    //loop to the next word in dictionary and repeat the process    
    }
    

    //for each query word check if it is anagram of any word in dictionary
    for (int i = 0 ; i < query_count ; i ++) {
        //create hash table for current query word to optimize the search process inside the dictionary
        int currentQueryHash[26] = {0};
        for (int l = 0 ; query[i][l] != '\0' ; l++)
            currentQueryHash[ (query[i][l] - 'a') ]++;

        //check query word against each word in dictionary using dictionary hash table
        for(int j = 0; j < dictionary_count; j++) {
            //if two word have different length then they are not anagram
            if ( strlen(dictionary[j]) == strlen(query[i])) {
                //compare two words using hash table
                int flagOfMatching=1;
                //loop in reverse to enhance performance b comparing to zero
                //add more if check condition after the loop for index 0 comparison as the loop will terminate before comparing it
                int k = 25;
                for (k = 25; k != 0; k--) {
                    if (currentQueryHash[k] != DictionaryHashTable[j][k]) {
                        flagOfMatching=0;
                        break;
                    }
                }
                if (currentQueryHash[k] != DictionaryHashTable[j][k]) {
                    flagOfMatching=0;
                }

                //if the flag still 1 then the two words are anagram
                if (flagOfMatching == 1) {
                    result_array[i]++;
                }   
            }
        }
    //loop to the next query word and repeat the process
    }

    //return result array count and result array
    *result_count = query_count;
    return result_array;
}
int main()
{
    #if USE_EXE_TIME_CALC == 1
        double time_spent = 0.0;
        clock_t begin = clock();
    #endif

    int wordsLen = 100;
    int dictionary_count = 10;
    char**dictionary = (char**) malloc(dictionary_count * sizeof(char*));
    for (int i = 0 ; i < dictionary_count ; i ++)
        dictionary[i] = (char*) malloc( wordsLen* sizeof(char));
    dictionary[0] = "hamda";
    dictionary[1] = "soso";
    dictionary[2] = "ssoo";
    dictionary[3] = "wweerr";
    dictionary[4] = "werwer";
    dictionary[5] = "qwertyuiop";
    dictionary[6] = "asdfghjkl";
    dictionary[7] = "zxcvbnm";
    dictionary[8] = "qqqqqqq";
    dictionary[9] = "tttttttttt";

    int query_count = 8;
    char ** query = (char**) malloc(query_count * sizeof(char*));
    for (int i = 0 ; i < query_count ; i ++)
        query[i] = (char*) malloc(wordsLen * sizeof(char));
    query[0] = "tttttttttt";
    query[1] = "qwertyuiop";
    query[2] = "asdfghjkl";
    query[3] = "zxcvbnm";
    query[4] = "qqqqqqq";
    query[5] = "qqqqqqqq";
    query[6] = "ooss";
    query[7] = "mdaha";
   
    int* result_count = malloc(sizeof(int));
    int* result = stringAnagram(dictionary_count, dictionary, query_count, query, result_count);
    for (int i = 0 ; i < query_count ; i ++)
    {
        printf("%s  ", query[i]);
        printf("%d \n", result[i]);
    }

    #if USE_EXE_TIME_CALC == 1
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("time spent = %f\n",time_spent);
    #endif
    
    //pause terminal
    int r=0;
    scanf("%d", &r);
   
       return 0;
}