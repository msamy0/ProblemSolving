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
    int * result_array = malloc(query_count * sizeof(int));
    for (int i = 0 ; i < query_count ; i ++)
        result_array[i] = 0; 
    
    //create hash table for each word in dictionary
    int **DictionaryHashTable = malloc(dictionary_count * sizeof(int*));
    for (int i = 0 ; i < dictionary_count ; i ++)
        DictionaryHashTable[i] = calloc(26 , sizeof(int));
    
    //fill hash table for each word in dictionary
    for (int i = 0 ; i < dictionary_count ; i ++)
    {   
        //for each letter in word in dictionary mark in front of its corresponding number in hash table
        //note that we ++ the value of the letter in the hash table to save also number of occurences in each word
        for (int j = 0 ; j < strlen(dictionary[i]) ; j++)
        {
            DictionaryHashTable[i][dictionary[i][j] - 'a']++;
        }
    }

    //for each query word check if it is anagram of any word in dictionary
    for (int i = 0 ; i < query_count ; i ++)
    {
        //get length of query word
        int stringLen = strlen(query[i]); 
        int counterOfMatches = 0;

        //check query word against each word in dictionary using dictionary hash table
        for(int j = 0; j < dictionary_count; j++) 
        {  
            //only loop check letters matching if length of query word is equal to length of dictionary word
            if ( strlen(dictionary[j]) == stringLen)
            {
                //check if each letter in query word is in currer dictionary word hash table
                int flag=1;
                int tempHash[26] = {0};
                for (int l = 0 ; l < 26 ; l++)
                    tempHash[l] = DictionaryHashTable[j][l];

                for (int k = 0; k < stringLen; k++)
                {
                    //if letter is not in dictionary word hash table then break and check next word in dictionary
                    //break is coupled with flag equal to 0, which in turn will not increment counterOfMatches
                    //else if flag is kept 1 then counterOfMatches will be incremented
                    if (tempHash[query[i][k] - 'a'] == 0)
                    {
                        flag=0;
                        break;
                    }
                    else
                    {
                        tempHash[query[i][k] - 'a']--;
                    }
                }
                if (flag == 1)
                    counterOfMatches++;
            }
        }
        //save result of query word in result array
        result_array[i] = counterOfMatches;

    //loop to the next query word and repeat the process
    }

    //return result array count and result array
    *result_count = query_count;
    return result_array;
}
int main()
{
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

    int query_count = 1;
    char ** query = (char**) malloc(query_count * sizeof(char*));
    for (int i = 0 ; i < query_count ; i ++)
        query[i] = (char*) malloc(wordsLen * sizeof(char));
    query[0] = "tttttttttt";


    
    int* result_count = malloc(sizeof(int));
    int* result = stringAnagram(dictionary_count, dictionary, query_count, query, result_count);
    for (int i = 0 ; i < query_count ; i ++)
    {
        printf("%s  ", query[i]);
        printf("%d \n", result[i]);
    }
        

    int r=0;
    scanf("%d", &r);
   
       return 0;
}