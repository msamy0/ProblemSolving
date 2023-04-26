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

typedef struct {
    char *word;
    int freq;
} wordFreq_t;
struct DLL_Node_t {
    wordFreq_t Data;
    struct DLL_Node_t *next;
    struct DLL_Node_t *prev;
};
char* sortString(char *str) {
    int n = strlen(str);
    char *string = (char*)malloc((n+1)*sizeof(char));
    strcpy(string, str); 
    char temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) {
            if (string[i] > string[j]) {
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }

    return string;
}
void insertNodeBeginning(struct DLL_Node_t **head, wordFreq_t data) {
    struct DLL_Node_t *newNode = malloc(sizeof(struct DLL_Node_t));
    newNode->Data = data;
    if(NULL != *head){
    newNode->next = *head;
    newNode->prev = NULL;
    (*head)->prev = newNode;
    *head = newNode;
    }
    //if list is empty
    else {
    newNode->next = NULL;
    newNode->prev = NULL;
    *head = newNode;
    }
}
int wordExistPlusPlus(struct DLL_Node_t *Node, char *word) {
    while (Node != NULL){
        if (strcmp(Node->Data.word,word) == 0) {
            Node->Data.freq++;
            return 1;
        }
        Node = Node->next;
    }
    return 0;
}
int wordExistRetFreq(struct DLL_Node_t *Node, char *word) {
    while (Node != NULL){
        if (strcmp(Node->Data.word,word) == 0) {
            return Node->Data.freq;
        }
        Node = Node->next;
    }
    return 0;
}
int* stringAnagram(int dictionary_count, char** dictionary, int query_count, char** query, int* result_count) {
    //create array of numbers to hold result of each query
    int * result_array = calloc(query_count , sizeof(int));
    //sort dictionary words
    for (int i = 0; i < dictionary_count; i++) {
       dictionary[i]= sortString(dictionary[i]);
    }
    //sort query words
    for (int i = 0; i < query_count; i++) {
        query[i]= sortString(query[i]);
    }
    //create linked list table for dictionary words to enhance performance
    //each node store distnict word and its frequency in the dictionary
    struct DLL_Node_t *dict= NULL;
    for (int i = 0; i < dictionary_count; i++) {
        //create new node to store word and its frequency
        wordFreq_t wordItem;
        wordItem.word = dictionary[i];
        wordItem.freq = 1;
        //check if word exist in dictionary, if yes then increment its frequency
        if(wordExistPlusPlus(dict,wordItem.word) == 1) {continue;} 
        //if word not exist in dictionary then insert it in the beginning of the linked list
        else {insertNodeBeginning(&dict, wordItem);}     
    }
    //for each query word check if it is anagram of any word in dictionary
    for (int i = 0 ; i < query_count ; i ++) {
        result_array[i] = wordExistRetFreq(dict,query[i]);
    }

    //return result array count and result array
    *result_count = query_count;
    return result_array;
}

int main()
{
    int wordsLen = 50;
    int dictionary_count = 5000;
    char**dictionary = (char**) malloc(dictionary_count * sizeof(char*));
    for (int i = 0 ; i < dictionary_count ; i ++)
        dictionary[i] = (char*) malloc( wordsLen* sizeof(char));
    
    //take input from file
    FILE *fp;
    fp = fopen("AnagramTestCasesDic.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    for (int i = 0 ; i < dictionary_count ; i ++)
    {
        fscanf(fp, "%s", dictionary[i]);
    }
    fclose(fp);

    
    int query_count = 5000;
    char ** query = (char**) malloc(query_count * sizeof(char*));
    for (int i = 0 ; i < query_count ; i ++)
        query[i] = (char*) malloc(wordsLen * sizeof(char));

    //take input from file
    fp = fopen("AnagramTestCasesQuery.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    for (int i = 0 ; i < query_count ; i ++)
    {
        fscanf(fp, "%s", query[i]);
    }
    fclose(fp);

    int ExpectedOut_count = 5000;
    char ** ExpectedOut = (char**) malloc(ExpectedOut_count * sizeof(char*));
    for (int i = 0 ; i < ExpectedOut_count ; i ++)
        ExpectedOut[i] = (char*) malloc(wordsLen * sizeof(char));

    //take input from file
    fp = fopen("AnagramTestCasesOut.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    for (int i = 0 ; i < ExpectedOut_count ; i ++)
    {
        fscanf(fp, "%s", ExpectedOut[i]);
    }
    fclose(fp);
       
    int* result_count = malloc(sizeof(int));
    #if USE_EXE_TIME_CALC == 1
        double time_spent = 0.0;
        clock_t begin = clock();
    #endif

    //Run the function
    int* result = stringAnagram(dictionary_count, dictionary, query_count, query, result_count);
    int flag = 0;
    for (int i = 0 ; i < query_count ; i ++)
    {
        //printf("%s  ", query[i]);
        //printf("%d \n", result[i]);
        if (result[i] != atoi(ExpectedOut[i]))
        {
            flag = i+1;
            break;
        }

    }
    if (flag == 0)
        printf("Test Passed");
    else
        printf("Test Failed at test case query %d", flag);

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