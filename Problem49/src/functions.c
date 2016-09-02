#include "functions.h"

/* returns true if the number is prime, false otherwise */
bool primeCheck(int n) {
  int a, b;
  if (n == 1) {
    return false;
  } else if (n % 2 == 0) {
    return (n == 2);
  } else if (n % 3 == 0) {
    return (n == 3);
  } else if (n % 5 == 0) {
    return (n == 5);
  } else if (n % 7 == 0) {
    return (n == 7);
  } else {
    a = 5;
    b = 7;
    while (a < n) {
      if (n == a || n == b) {
        return true;
      } else if (n % a == 0 || n % b == 0) {
        return false;
      }
      a += 6;
      b += 6;
    } /* end of while */
    return true;
  }
} /* end of primeCheck function */


/* this will generate a linked list of primes starting at the lowest number and 
   ending before or at the highNum, depending on if highNum is a prime */
ListHeadPtr generatePrimeList(int lowNum, int highNum) {
  ListHeadPtr start;
  Prime * holder;
  int temp;
  temp = lowNum;
  
  /* find the lowest prime number */
  while (primeCheck(temp) == false) {
    temp++;
  }
 
  start = NULL;
  
  
  /* populate the list */
  while (temp <= highNum) {
    if (primeCheck(temp) == true) {
      holder = createPrime(temp);
      start = addToBack(start, holder);
    }
    temp += 2;
  }

  return start;
			      
}

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


/* searchs the list for the number, returns true if found, false otherwise */
/* just goes down from the top of the list, very inefficient */
bool listSearch(ListHeadPtr a, int n) {
  while (a != NULL && a->num <= n) {
    if (n == a->num) {
      return true;
    }
    a = a->next;
  }
  return false;
}
