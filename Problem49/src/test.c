#include <stdio.h>
#include <stdlib.h>

int primeCheck(int n) {
  int a, b;
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else if (n % 2 == 0) {
    return 0;
  } else if (n == 3) {
    return 1;
  } else if (n % 3 == 0) {
    return 0;
  } else if (n == 5) {
    return 1;
  } else if (n % 5 == 0) {
    return 0;
  } else if (n == 7) {
    return 1;
  } else if (n % 7 == 0) {
    return 0;
  } else {
    a = 5;
    b = 7;
    while (a < n) {
      if (n == a || n == b) {
        return 1;
      } else if (n % a == 0 || n % b == 0) {
        return 0;
      }
      a += 6;
      b += 6;
    } /* end of while */
    return 1;
  }
} /* end of primeCheck function */

int main(void) {
  int i;
  for (i = 1; i <= 100; i++) {
    if (primeCheck(i) == 1) {
      printf("prime: %d\n", i);
    } else {
      /*printf("%d\n", i);*/
    }
  }
  return 0;
} 
