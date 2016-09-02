#include "p53func.h"

#ifndef PRIMETYPE
#define PRIMETYPE
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
#endif

int main(void) {
  int n, r, target;
  primeFactors nP, rP, nMinR, denom, choice;
 
  bool metTarget;

  int metTargetCount;
 
  target = 1000000;
  metTargetCount = 0;

  nP = primeFactorize(705432, primes);
  killPrimeFactors(nP);

  for (n = 22; n <= 100; n++) { 

    metTarget = false;
    /* get the prime factors for n */
    nP = factorialPrimeFactorize(n, primes);

    /** test to see if n choose n/2 is greater than target **/

    r = n/2;

    /* get the prime factors */
    rP = factorialPrimeFactorize(r, primes);
    nMinR = factorialPrimeFactorize(n-r, primes);

    /* merge to one denominator */
    denom = mergePrimeFactors(rP, nMinR);

    /* cancel them out with original */
    choice = cancelPFactors(nP, denom);

    /* check if it's greater than 1,000,000 */
    metTarget = checkAgainstTarget( target, choice);
    if (metTarget == true) {
      /* increment based on if n was divisible by 2 */
      printf("%d choose %d is greater than %d, incrementing from %d ", 
	     n, r, target, metTargetCount);
      if (n % 2 == 0) {
        metTargetCount++;
      } else {
	metTargetCount += 2;
      }
      printf("to %d\n", metTargetCount);
    }

    /* kill off r, rMinR, denom and choice as they have served their purpose */
    killPrimeFactors(rP);
    killPrimeFactors(nMinR);
    killPrimeFactors(denom);
    killPrimeFactors(choice);

    /* this loop runs until an r is found that doesn't meet the target */
    while (metTarget == true) {
      r--;
      /** recalculate the denominator **/
      /* get the prime factors */
      rP = factorialPrimeFactorize(r, primes);
      nMinR = factorialPrimeFactorize(n-r, primes);

      /* merge to one denominator */
      denom = mergePrimeFactors(rP, nMinR);

      /** find if the new choice meets the target **/
      /* cancel them out with original */
      choice = cancelPFactors(nP, denom);

      /* check if it's greater than 1,000,000 */
      metTarget = checkAgainstTarget( target, choice);
      if (metTarget == true) {
        printf("%d choose %d is greater than %d, incrementing from %d ", 
	     n, r, target, metTargetCount);
	metTargetCount += 2;
        printf("to %d\n", metTargetCount);
      }

      /* kill off r, rMinR, denom and choice */
      killPrimeFactors(rP);
      killPrimeFactors(nMinR);
      killPrimeFactors(denom);
      killPrimeFactors(choice);

    } /* end of checking r */

    /* kill off nPrimeFactors as it is done */
        killPrimeFactors(nP);
    
  } /* end of looping through all the n's */

  printf("The number of values of n choose r for all r <= n <= 100 that are greater than %d are: %d\n", target, metTargetCount);

  return 0;
} 
