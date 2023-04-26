#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* findSubstring(char* s, int k) {
    // create the result string that will return value to the caller
    char* result_str = (char*) malloc ( (k+1)*sizeof(char) );
    //evaluate the input string length
    int str_len = strlen(s);

    //create a hash table to store 1 in the vowel indexes    
    int hash_table[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,0,0,0};
    // for example index of char 'r' in ASCII is 114 and index of char 'a' is 97 , so to index hash table statring form 0
    // we need to subtract 97 from 114 to get 17 which is the index of 'r' in hash table, and so on for all other characters
    hash_table['a'-'a'] = 1;
    hash_table['e'-'a'] = 1;
    hash_table['i'-'a'] = 1;
    hash_table['o'-'a'] = 1;
    hash_table['u'-'a'] = 1;

    /*
    //------------------------ Fail with HackerRank but works with VsCode and LeetCode------------------------//
    //create an array to store the accumulated count of vowels in the input string
    //it will have one more index that the original length of the input string as the first index will be accumelate zero count of vawels (nothing before it)
    int* vowelsAccCount = (int*)malloc((str_len+1)*sizeof(int));
    vowelsAccCount[0] = 0;
    for (int i = 0; i < str_len; i++) {
        //[0,1,2,3,4,5,6,7,8,9,10,11] --> index
        //[k,r,e,t,o,u,a,r,n,i,e]  --> input string
        //[0,0,0,1,1,2,3,4,4,4,5,6] --> vowelsAccCount
        //so each elemnt in the array will hold the accumelated count of prevous index plus 1, if the current element chatacter is a vowel
        //s[i] -> will return the current character, hash_table[s[i]-'a'] will return 1 if the current character is a vowel and 0 if not
        vowelsAccCount[i+1] = vowelsAccCount[i] + hash_table[s[i]-'a'];
    }
    */
    //------------------------ Works with HackerRank and VsCode and LeetCode ------------------------//
    
    //same concept as HashTable, but using direct if comparision
    int* vowelsAccCount = (int*)malloc((str_len+1)*sizeof(int));
    vowelsAccCount[0] = 0;
    for (int i = 0; i < str_len; i++) {
        if (s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'a' ||s[i] == 'u')
            vowelsAccCount[i+1] = vowelsAccCount[i] + 1;
        else {
            vowelsAccCount[i+1] = vowelsAccCount[i];
        }
    }
    

    //at each character calculate if I will achive higher vowels accumelation by shifting the window to the right
    //if yes, then shift the window to the right
    //if no, then keep the window and move to the next character while recording in AccShifts how many shifts I have skipped
    //srartIdx and endIdx will be the start and end index of the window looking on the string array
    //if you found that shifting thw windows will result in more vawels accumelation, then shift the window by AccShifts value and reset AccShifts to zero
    //note that, I make my decision based on vowelsAccCount array that I have pre calculated, so I don't need to recalculate it again
    int currentMaxVowels = 0;
    int AccShifts = 0;
    int statrIdx = 0;
    int endIdx = k-1;

    currentMaxVowels = vowelsAccCount[k] - vowelsAccCount[0] ;  
    for (int i = k ; i < str_len; i++) {
        AccShifts++;
        if (currentMaxVowels < (vowelsAccCount[i+1] - (vowelsAccCount[statrIdx+AccShifts]))){
            currentMaxVowels = vowelsAccCount[i+1] - (vowelsAccCount[statrIdx+AccShifts]);
            statrIdx += AccShifts;
            endIdx += AccShifts;
            AccShifts =0;
        }       
    }

    //return the result string
    if (currentMaxVowels > 0){
        for (int i = 0 ; i < k; i++) { 
            result_str[i] = s[i+statrIdx];
        }
        result_str[k] = '\0';
        return result_str;
    }
    else{
        static char notFound[] = "Not found!";
        return notFound;
    }
}


int main()
{
    //code here
    char* s = "azerdii";
    int k = 5;
    char* result = findSubstring(s,k);
    printf("%s",result);

    int i = 0;
    scanf( "%d" , &i);
    return 0;
}