#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int bool;
enum {false, true};

int AtoI(int * array, int digits) {
  int n, i;
  n = 0;
  for (i = 0; i < digits; i++) {
    n += array[i] * pow(10, (digits-i-1));
  }

  return n;
}

void printArray(int * array, int digits) {
  int i;
  for (i = 0; i < digits; i+++) {
    printf("%d", array[i]);
  }
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

int main(void) {
  int * array, digits;
  int i, j, k, * places, number;
  int primeFam, notPrime;
  bool pChk;

  digits = 5;
  array = malloc(sizeof(int)*5);
  array[0] = 5;
  array[1] = 6;
  array[2] = 10;
  array[3] = 10;
  array[4] = 3;

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
  while (k < 10 && notPrime < 10) {
    for (i = 0; i < j; i++) {
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

  printf("%d of the 10 numbers in 56003 are prime, %d are not\n", primeFam, notPrime);
  return 0;  

} /* end of famCount function */
 
