#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

extern int primes[];

typedef struct {
  int base;
  int power;
} pFact;

typedef struct {
  int count;
  pFact * factors;
} primeFactors;

/* this will return an array of ints from a to b. Eg. a = 23, b = 14
   array will be 23, 22, 21, 20, 19, 18, 17, 16, 15 */
int * modFact(int a, int b); 

/* this function will return a 1 if a number is prime, 0 if not. Will return a 0
   for all numbers lower than 2 */
int primeCheck(int n);


/* this function will return a primeFactors struct where the first element in each 2 element array is the prime number, and the second is the exponent that it is raised to.
   Make sure the passed primes array contains all the primes from 2 until the prime after n. */
primeFactors primeFactorize(int n, int * primes);

primeFactors mergePrimeFactors(primeFactors pFactA, primeFactors pFactB);

primeFactors factorialPrimeFactorize(int n, int * primes);

/* This function will cancel out the prime factors and bring it to a lowest term. 
   Both prime factors will remain unchanged, and the returned primeFactor will be the reduced one.
*/
primeFactors cancelPFactors(primeFactors firstPrimeFactors, primeFactors secondPrimeFactors);

bool killPrimeFactors(primeFactors toDie);

bool checkAgainstTarget(int target, primeFactors choice);
