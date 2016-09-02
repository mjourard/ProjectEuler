#include <stdio.h>
#include <stdlib.h>

#ifndef BOOL_H
#define BOOL_H
typedef int bool;
enum {false, true};
#endif

int * itoA(int number, int digits);
int digCount(int n);


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

int AtoI(int * array, int digits) {
  int n, i;
  n = 0;
  for (i = 0; i < digits; i++) {
    n += array[i] * pow(10, (digits-i-1));
  }

  return n;
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

/* returns true if the number is prime, false otherwise */
bool primeCheck(int n) {
  int a, b;
  if (n == 1) {
    return false;
  } else if (n == 2) {
    return true;
  } else if (n % 2 == 0) {
    return false;
  } else if (n == 3) {
    return true;
  } else if (n % 3 == 0) {
    return false;
  } else if (n == 5) {
    return true;
  } else if (n % 5 == 0) {
    return false;
  } else if (n == 7) {
    return true;
  } else if (n % 7 == 0) {
    return false;
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


/* returns the number of primes in a family if it is greater than 8 or 0.
   In the array being passed, the digits that will be replaced should 
   equal 10 */
int famCount(int * array, int digits) {
  int i, j, k, * places, number;
  int primeFam, notPrime;
  bool pChk;

  places = malloc(sizeof(int)*(digits-1));
  j = 0;
  
  /* find which places need to be replaced */
  for (i = 0; i < digits; i++) {
    if (array[i] == 10) {
      places[j] = i;
      j++;
    } /* if array[i] is 10 */
  } /* end of for loop */


  /* determine how many numbers in the family are prime */
  primeFam = 0;
  notPrime = 0;
  k = 0;
  while (k < 10 && notPrime < 3) {
    for (i = 0; i <= j; i++) {
      array[places[i]] = k;
    }
    number = AtoI(array, digits);
    pChk = primeCheck(number);
    if (pChk == true) {
      primeFam++;
    } else {
      notPrime++;
    }
    k++;
  }

  if (notPrime == 3) {
    return 0;
  } else {
    return primeFam;
  }
  

} /* end of famCount function */


int main(void) {
  int n, digits, * array;
  int primeFam, notPrime;
  bool pChk;
  
  primeFam = 0;
  n = 56005;
  /* run until find the desired number with a prime family of 8 */
  while (primeFam < 8) {

    /* check if the number is prime */
    pChk = primeCheck(n);
    if (pChk == true) {
    
      
      digits = digCount(n);
      array = itoA(n, digits);
      /* set up the loop that will check all digit combinations until all 
         digits except for the last one have been replaced */
            
    }
    n += 2;
  }
  
  return 0;
} 

