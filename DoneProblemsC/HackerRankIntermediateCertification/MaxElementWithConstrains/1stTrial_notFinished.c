#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ABS(a) (((a)>0)?(a):(-a))
typedef struct{
  int is_valid;
  int count;
  int first_element;
  int last_element;
  long sum;
}Array_st;
int maxElement(int n, int maxSum, int k) {
  int reminder = maxSum % n;
  int result  = (maxSum-reminder) / n;
  Array_st right;
  Array_st left;
  volatile Array_st *largestSide;
  volatile Array_st  *smallestSide;
  //initialize right side array with corresponding values according to the index of interst "k", if is_valid = 0 then the "k" is the last element in the array
  right.count = (n-k)-1;
  if (right.count > 0){
    right.is_valid = 1;
    right.first_element = result - 1;
    right.last_element = (result - right.count);
    right.sum = right.count*(right.first_element + right.last_element) / 2 ;
  }
  else{
    right.is_valid = 0;
    right.sum = 0;
  }
  //initialize left side array with corresponding values according to the index of interst "k", if is_valid = 0 then the "k" is the first element in the array
  left.count = k;
  if (left.count > 0){
    left.is_valid = 1;
    left.first_element = (result - left.count);
    left.last_element = result - 1;
    left.sum = left.count*(left.first_element + left.last_element) / 2 ;
  }
  else{
    left.is_valid = 0;
    left.sum = 0;
  }

  //init reminder value to be the remaining value after subtracting the sum of the whole array from the maxSum
  reminder = maxSum - (result + right.sum + left.sum) ;

  if (right.count >= left.count){
    largestSide = &right;
    smallestSide = &left;
  }
  else {
    largestSide = &left;
    smallestSide = &right;
  }

  //value to achive sorted left and right arrays with number greater than zero
  int increasing_value = 0;

  if ((result-1) < largestSide->count){
    increasing_value = largestSide->count - (result-1);
    result += increasing_value;
    reminder -= increasing_value * n;
  }
  while(reminder >= n){
    result++;
    reminder -= n;
  }

  //if reminder negative
  if(reminder < 0 ){

    //init first and last element values for both arrays
    if (left.is_valid){
      left.last_element += increasing_value;
      left.first_element += increasing_value;
    }
    if (right.is_valid){
      right.last_element += increasing_value;
      right.first_element += increasing_value;
    }
    
    while(reminder < 0){

      if(smallestSide->is_valid){
        if( (smallestSide->first_element - ABS(reminder)-1 ) >= 1 ){
          result--;
          break;
        }
        else {
          result --;
          smallestSide-> last_element --;
          smallestSide-> first_element = 1;
          reminder += smallestSide->count;
        }
      }
      if((largestSide->count) >= ABS(reminder) ){
        result --;
        break;
      }
      else{
        result --;
        largestSide->last_element --;
        reminder += largestSide->count;
        largestSide->count --;
      }
    }
  }
  return result;
}

int main() {

  int number_of_test_cases  = 15;
  FILE *fpIN;
  fpIN = fopen("input.txt", "r");

  FILE *fpOUT;
  fpOUT = fopen("output.txt", "r");

  int correct_count = 0;
  int counter = 0;

  for (int i = 0; i < number_of_test_cases; i++){
    printf("Test case %d:    ", counter);
    //get input from file

    int n, maxSum, k;
    fscanf(fpIN, "%d %d %d", &n, &maxSum, &k);
    
    //call function
    int result = maxElementwork(n, maxSum, k);
    //print result
    printf("%d          ", result);

    int expected_result;
    fscanf(fpOUT, "%d", &expected_result);
    
    //print expected result
    printf("%d", expected_result);
    //check if the result is correct
    if (result == expected_result){
      printf("    Correct\n");
      correct_count++;
    }
    else{
      printf("   Wrong\n");
    }

    printf("\n");
    counter++;
  }
  printf("Correct count = %d from %d\n", correct_count, number_of_test_cases);

  fclose(fpIN);
  fclose(fpOUT);
  int r= 0;
  scanf("%d", &r);  
  return 0;

}  