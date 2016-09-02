#include "p53func.h"

int * modFact(int a, int b) {
  int * array, i, counter;

  if ((a - b) < 1) { return NULL; }

  array = malloc(sizeof(int)*(a-b));
  
  counter = 0;
  for (i = a; i > b; i--) {
    array[counter] = i;
    counter++;
  }

  return array;
  
} /* end of modFact function */

int primeCheck(int n) {
  int a, b;
  if (n < 2) {
    return 0;
  } else if (n == 2 || n == 3 || n == 5 || n == 7) {
    return 1; 
  } else if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) {
    return 0;
  } else {
    a = 11;
    b = 13;
    while (n < b) {
      if (n % a == 0 || n % b == 0) {
        return 0;
      }
      a += 6;
      b += 6;
    } /* end of while loop */
    return 1;
  }
} /* end of primeCheck function */


/* this function will return an array of prime factors given a number n.
   The array will be 2 dimensional, with the first dimension being the prime 
   factor and the second being the power. */
primeFactors primeFactorize(int n, int * primes) {
  
  int primeCounter, factorCount, i;
  primeFactors pF;

  if (n == 2) {
    pF.factors = malloc(sizeof(pFact));
    pF.factors[0].base = 2;
    pF.factors[0].power = 1;
    pF.count = 1;
    return pF;
  }

  /******
   * this determines a rough estimate as to how many different prime factors are in the number
   * Looking at increasing numbers by multiplying by lowest prime factors, 2 * 3 * 5 = 30
   * This would mean that we would need 3 prime factors for 30, or 1 for every digit plus 1.
   * This rough estimate should save some space when initializing.
   ******/
  i = n;
  factorCount = 1;
  while (i > 0) {
    factorCount++;
    i /= 10;
  }

  pF.factors = malloc( factorCount * sizeof(pFact) );
  pF.count = factorCount;
  for (i = 0; i < factorCount; i++) {
    pF.factors[i].power = 0;
  }
  
  primeCounter = 0;
  factorCount = 0;
  

  while (primeCounter < 25 && n > 1) {

    /* find how many times the current prime number divides into n */
    while ((n % primes[primeCounter]) == 0) {
      n /= primes[primeCounter];
      pF.factors[factorCount].power++;
    }
    
    /* if the current prime divided into n, add it to the returning array */
    if (pF.factors[factorCount].power > 0) {
      pF.factors[factorCount].base = primes[primeCounter];
      factorCount++;
    } 

    /* increase the prime counter */
    primeCounter++;
  }

  pF.count = factorCount;
  pF.factors = realloc(pF.factors, sizeof(pFact) * factorCount);
  return pF;
} /* end of primeFactorize function */


/* 2^3 * 3 * 7 * 13 * 17 * 19 = 22 choose 11 */ 
/* 2*5 * 2^3 * 2*3 * 2^2 * 2 = 2^8 for 11! */
/* 2*11 * 2^2*5 * 2*3^2 * 2^4 * 2*7 * 2^2*3 * 2*5 * 2^3 * 2*3 * 2^2 * 2 = 2^19 for 22! */
/* 22   * 20    * 18    * 16  * 14  * 12    * 10  * 8   * 6   * 4   * 2 */


primeFactors mergePrimeFactors(primeFactors pFactA, primeFactors pFactB) {
  primeFactors merge;
  int roughGuess, i, aCounter, bCounter;

  roughGuess = pFactA.count + pFactB.count;

  merge.factors = malloc(sizeof(pFact) * roughGuess);
  assert(merge.factors);

  aCounter = bCounter = 0;
  for (i = 0; i < roughGuess && aCounter < pFactA.count && bCounter < pFactB.count; i++) {
    if (pFactA.factors[aCounter].base == pFactB.factors[bCounter].base) {
      merge.factors[i].base = pFactA.factors[aCounter].base;
      merge.factors[i].power = pFactA.factors[aCounter].power + pFactB.factors[bCounter].power;
      aCounter++;
      bCounter++;

    } else if (pFactA.factors[aCounter].base > pFactB.factors[bCounter].base) {
      merge.factors[i].base = pFactB.factors[bCounter].base;
      merge.factors[i].power = pFactB.factors[bCounter].power;
      bCounter++;

    } else {
      merge.factors[i].base = pFactA.factors[aCounter].base;
      merge.factors[i].power = pFactA.factors[aCounter].power;
      aCounter++;
    }
  } /* end of looping through both lists */

  /* merge what's left */
  while (aCounter < pFactA.count) {
    merge.factors[i].base = pFactA.factors[aCounter].base;
    merge.factors[i].power = pFactA.factors[aCounter].power;
    aCounter++;
    i++;
  }

  while (bCounter < pFactB.count) {
    merge.factors[i].base = pFactB.factors[bCounter].base;
    merge.factors[i].power = pFactB.factors[bCounter].power;
    bCounter++;
    i++;
  }

  merge.count = i;
  return merge;
} /* end of merging primeFactors */

primeFactors factorialPrimeFactorize(int n, int * primes) {
  primeFactors returnPF, temp, temp2;
  bool returnPFUsed;
  if (n < 2) {
    returnPF.count = -1;
    returnPF.factors = NULL;
    return returnPF;
  }

  returnPF = primeFactorize(n, primes);
  returnPFUsed = true;
  n--;

  while (n > 1) {
    temp = primeFactorize(n, primes);
    if (returnPFUsed == true) {
      temp2 = mergePrimeFactors(returnPF, temp);
      killPrimeFactors(returnPF);
    } else {
      returnPF = mergePrimeFactors(temp2, temp);
      killPrimeFactors(temp2);
    }

    killPrimeFactors(temp);
    returnPFUsed = (!returnPFUsed);
    n--;
  } /* end of getting the prime factors of n! */

  if (returnPFUsed == true) {
    return returnPF;
  } else {
    return temp2;
  }
}



/*************************
Cancelling prime factors
*************************/


/* This function will cancel out the prime factors and bring it to a lowest term. 
   Both prime factors will remain unchanged, and the returned primeFactor will be the reduced one.
*/
primeFactors cancelPFactors(primeFactors firstPrimeFactors, primeFactors secondPrimeFactors) {
  int i, j;
  int sizeOne, sizeTwo;
  primeFactors returnPF;

  sizeOne = firstPrimeFactors.count;
  sizeTwo = secondPrimeFactors.count;


  returnPF.factors = malloc(sizeof(pFact) * sizeOne);
  returnPF.count = sizeOne;
  assert(returnPF.factors);

  j = 0;  

  for (i = 0; i < sizeOne; i++) {

    returnPF.factors[i].base = firstPrimeFactors.factors[i].base;
    returnPF.factors[i].power = firstPrimeFactors.factors[i].power;

    /* get the second primeFactor count up to the current count */
    while ( (j < sizeTwo-1) && (returnPF.factors[i].base > secondPrimeFactors.factors[j].base) ) {
      j++;
    }
  
    /* subtract only if same base */
    if (returnPF.factors[i].base == secondPrimeFactors.factors[j].base) {
      returnPF.factors[i].power -= secondPrimeFactors.factors[j].power;
    }
  } /* end of for loop */  

  return returnPF;

} /* end of cancelPFactors function */


/* 21 = 3*7: 1 */
/*   18 = 3*3*2: 2 */
/*   15 = 3*5: 1 */
/*   12 = 3*4: 1 */

/*   9 = 3*3: 2 */
/*   6 = 3*2: 1 */
/*   3 = 3*1: 1 */

/*   total: 9 */

bool killPrimeFactors(primeFactors toDie) {
  if (toDie.factors == NULL) { return false; }

  free(toDie.factors);
  toDie.factors = NULL;
  toDie.count = -1;
  return true;
}

bool checkAgainstTarget(int target, primeFactors choice) {
  if (choice.factors == NULL) { return false; }

  int product, i, j;
  product = 1;
  i = 0;
  while ( i < choice.count) {
    j = 0;
    while (j < choice.factors[i].power) {
      product *= choice.factors[i].base;
      if (product >= target) {
	return true;
      }
      j++;
    }
    i++;
  } 
  return false;
} /* end of checkAgainstTarget */


