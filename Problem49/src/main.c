#include "functions.h"

int main(int argc, char * argv[]) {
  ListHeadPtr pList, tempA, tempB;
  int min, max;
  int checker;
  
 
  if (argc < 3) {
    printf("Usage: enter the minimum number and maximum number to be used as the range\nExiting\n");
    exit(1);
  }
  
  min = atoi(argv[1]);
  max = atoi(argv[2]);

  printf("min = %d, max = %d\n", min, max);

  pList = generatePrimeList(min, max);
  tempA = pList;
  
  while (tempA->next != NULL) {
    tempB = tempA->next;
    while (tempB != NULL) {
      /* check to see if tempB + (tempB-tempA) is greater than 1000 */
      checker = tempB->num + (tempB->num - tempA->num);
      
  
      if (checker < max) {

	/* check to see if they are permutations */
        if (permuteCheck(tempA->num, tempB->num) == true && permuteCheck(tempA->num, checker) == true) {
      
	  /* check to see if it's in the list */
	  if (listSearch(tempB, checker) == true) {
	    /*print the value, then exit the program */
	    printf("%d, %d and %d\n", tempA->num, tempB->num, checker);
	    printf("Put together, they form %d%d%d\n", tempA->num, tempB->num, checker);
	        
	  } /* if checker is part of the list */
	} /* if tempA and tempB are permutations of each other */ 
      } /* if checker < max */
      
      
      tempB = tempB->next;
    } /* while list 2 is not null */
    tempA = tempA->next;
  } /* while list 1 is not null */ 
  
  return 0;
}
