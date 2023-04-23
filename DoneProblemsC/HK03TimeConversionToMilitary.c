#include <stdio.h>
/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

char* timeConversion(char* s) {
    static char result[8] = "";
    int hour;
    hour = ( ((( (int)s[0] )-48)*10) + ((((int)s[1])-48)*1) );

    if(s[8] == 'A' && hour == 12)
    {
       hour =0; 
    } 
    else if (s[8] =='P' && hour != 12)
    {
        hour +=12;
    }
    
    result[0] = (char) ( (hour/(int)10)+48);
    result[1] = (char) ((hour%10) + 48);
    result[2] = ':';
    result[3] = s[3];
    result[4] = s[4];
    result[5] = ':';
    result[6] = s[6];
    result[7] = s[7];
    return result;
}

int main ()
{
    char input[11] ="07:05:45PM";
    char* result = timeConversion(input);
    printf("%s\n",result);
    return 0;
}
