#include "functions.h"

int main(void) {
  int min, max;
  ListHeadPtr pList;
  char * printPrimes;
 
  min = 1000;
  max = 10000;
 
  pList = generatePrimeList(min, max);
  printPrimes = printList(pList, 5);

  printf("%s", printPrimes);
  
  return 0;
}
