#include <stdio.h>
#include <stdlib.h>

#ifndef BOOL_H
#define BOOL_H
typedef int bool;
enum {false, true};
#endif

bool permuteCheck(int a, int b);
int * itoA(int number, int digits);
int digCount(int n);


/* this function will check if a number is a permutation of another number */
bool permuteCheck(int a, int b) {
  int aDigC, bDigC;
  int * aryA, * aryB;
  int i, j;
  bool retVal;

  /* see if the number of digits are equal */
  aDigC = digCount(a);
  bDigC = digCount(b);

  if (aDigC != bDigC) {
    return false;
  }

  /* send the digits to an array for easier checking */
  aryA = itoA(a, aDigC);
  aryB = itoA(b, bDigC);
  
  /* check if all digits in A are found in B */
  
  for (i = 0; i < aDigC; i++) {
    retVal = false;
    for (j = 0; j < bDigC; j++) {
      /* printf("aryA[%d] = %d, aryB[%d] = %d\n", i, aryA[i], j, aryB[j]);*/
      if (aryA[i] == aryB[j]) {
        retVal = true;
        aryB[j] = 10;
        break;
      } /* end if */
    }  /* end for j */
  
    /* if at this point retVal still equals false, 
       then return false after freeing memory */
    if (retVal == false) {
      free(aryA);
      free(aryB);
      return false;
    }
  
  } /* end for i */

  /* return the truth value and free the memory and stuffs */
  free(aryA);
  free(aryB);
  return retVal;
}


/* takes an int and the # of digits and converts to an array */
int * itoA(int number, int digits) {
  int * array, i;
  array = malloc(sizeof(int) * digits);
  
  i = 1;
  while (number != 0) {
    array[digits - i] = number % 10;
    number /= 10;
    i++;
  }
 
  return array;
}


/* returns the number of digits in the passed number */
int digCount(int n) {
  int counter;
  
  counter = 0;
  while (n != 0) {
    n /= 10;
    counter++;
  }
  
  return counter;
}


int main(void) {
  int n;
  bool truth;
  truth = false;
  n = 100;
  while (truth == false) {
    printf("%d\n", n);
    if (permuteCheck(n, n*2) == true) {
      if (permuteCheck(n, n*3) == true) {
        if (permuteCheck(n, n*4) == true) {
          if (permuteCheck(n, n*5) == true) {
            if (permuteCheck(n, n*6) == true) {
              printf("the answer is %d\n", n);
              truth = true;
	    }
	  }
	}
      }
    }
    n++;
  }
  return 0;
} 

