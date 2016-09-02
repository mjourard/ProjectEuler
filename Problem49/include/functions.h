#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

#ifndef BOOL_H
#define BOOL_H
typedef int bool;
enum {false, true};
#endif

#ifndef STRUCT_NAME
#define STRUCT_NAME
struct Prime {

  int num;
  struct Prime * next;

};



/*fix this typedef so that it refers properly to your struct*/
typedef struct Prime Prime;

typedef Prime * ListHeadPtr;
#endif

/* returns a true if a number is prime, false otherwise */
bool primeCheck(int n);


/* this will generate a linked list of primes starting at the lowest number and 
   ending before or at the highNum, depending on if highNum is a prime */
ListHeadPtr generatePrimeList(int lowNum, int highNum);


/* returns true if a number is a permutation, false otherwise */
bool permuteCheck(int a, int b);

/* takes an integer and the number of digits in that integer and returns an array of it */
int * itoA(int number, int digits);


/* returns the number of digits in the passed number */
int digCount(int n);

/* searchs the list for the number, returns true if found, false otherwise */
/* just goes down from the top of the list, very inefficient */
bool listSearch(ListHeadPtr a, int n);
