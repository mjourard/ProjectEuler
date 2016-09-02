/*************************linkedListfunctions.c****************************
Student Name: Matthew Jourard                        Student Number:  0800740
Date: Monday, April 3, 2013                          Course Name:     CIS2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/
#include "linkedList.h"

#ifndef BOOL_H
#define BOOL_H
typedef int bool;
enum {false, true};
#endif

/*********************
REQUIRED
Linked List functions
*************************/


/*This function returns true if the list is empty and false in all other cases.  
  The function does not change the list in any way */

bool isEmpty(ListHeadPtr theList) {
  
  if (theList == NULL) { 
    return true; 
  } else {
    
    return false;
  }
} /* end of isEmpty function */



/*This function adds the node sent in as a parameter to the front of the list that
  is given as a parameter.  The function returns the new head of the list.  */
ListHeadPtr addToFront(ListHeadPtr theList, Prime * toBeAdded) {
  
 toBeAdded->next = theList;
 return toBeAdded;
} 

/*This function removes the first item from the given list,  sets the next pointer of that item to NULL
  and returns a pointer to the new head of the list (the item that was the second item*/
ListHeadPtr removeFromFront(ListHeadPtr theList) {

  ListHeadPtr newHead;

  newHead = theList->next;
  theList->next = NULL;
  return newHead;
  
} /* end of removeFromFront function */


/*This function returns a pointer to the item that is at the front of the list. 
  It does not change the list in any way */
Prime * getFront(ListHeadPtr theList) {
  return theList;
}

/*This function adds the node sent as a parameter to the back of the list sent in as a parameter.
  It returns a pointer to the head of the list */
ListHeadPtr addToBack(ListHeadPtr  theList, Prime * toBeAdded) {
  
  ListHeadPtr tempHead;
  
  tempHead = theList;
  toBeAdded->next = NULL;
  if (theList == NULL) {
    theList = toBeAdded;
    return theList;
  } else {
    
    while (tempHead->next != NULL) {
      tempHead = tempHead->next;
    }
   
    tempHead->next = toBeAdded;
    
    return theList;
  }
} /* end of addToBack */

/*This function removes the last item from the list and returns a pointer
  to the head of the list. The function sets the next pointer of the new last 
item to NULL and it sets the next pointer of the removed item to NULL */
ListHeadPtr removeFromBack(ListHeadPtr theList) {
  ListHeadPtr tempHead;
  
  tempHead = theList;

  if (theList->next == NULL) {

    printf("error, can't delete from the back of the list if it only has one item in it, call 'remove from front'.\n");
    return tempHead;

  } else {
    
    /*get to the second last list element */
    while (theList->next->next != NULL) {
      theList = theList->next;
    }
  
    /* the next element is now the last in the list. Current element is second last in the list */

    /*free the last item */
    destroyPrime(theList->next);
    /* free(theList->next) */
    theList->next = NULL;
    return tempHead;
  }
} /* end of removeFromBack */

/*This function returns a pointer to the last item in the linked list that is
  given as a parameter.  The function does not change the list in any way */
Prime * getBack(ListHeadPtr theList) {
  
  while (theList->next != NULL) {
    theList = theList->next;
  }
 
  return theList;
} /* end of getBack function */

/*this function must print the patron ID for each patron in the list to a string beginning with 
the front of the list. The 
Prime Ids must be printed one per line with a newline immediately following the id.
The function should return the string */
char * printList(ListHeadPtr  theList, int maxDigits) {
  char * printedList, * primeHolder;
  int listLength, numLength;
  bool emptyCheck;
  
  emptyCheck = isEmpty(theList);
  
  if (emptyCheck == true) {
    return "";
  }
  
  printedList = malloc(sizeof(char));
  printedList[0] = '\0';
  

  while (theList != NULL) {
  
    /* get the number into string form */
    primeHolder = malloc(sizeof(char)*(maxDigits+1));
    sprintf(primeHolder, "%d\n", theList->num);
    numLength = strlen(primeHolder);
    
    /* realloc memory to make the new string fit */
    listLength = strlen(printedList);
    printedList = realloc(printedList, sizeof(char)*(listLength + numLength + 1));
   
    /* put the new prime onto the list */
    printedList = strcat(printedList, primeHolder);
    free(primeHolder);
     
    theList = theList->next;
       
  }
  return printedList; 
} /* end of printList function */

/*this function should free all the memory for the list, except possibly the head pointer
  which will need to be freed separately */
void destroyPrimeList(ListHeadPtr theList) { 
  ListHeadPtr temp;
  Prime * toBeDestroyed; 
     
  if (theList != NULL) {
    temp = theList; 
   
  
    while (temp->next != NULL) {
      toBeDestroyed = temp; 
      temp = temp->next;
      destroyPrime(toBeDestroyed);
      free(toBeDestroyed);
      toBeDestroyed = NULL;
    }

    toBeDestroyed = temp; 
    destroyPrime(toBeDestroyed);
    free(toBeDestroyed);
    toBeDestroyed = NULL;
  }
} /* end of destroyPrime function */


/***********
REQUIRED
Prime functions
************/

/*This list must take in four parameters and return a pointer to 
  a patron struct*/
Prime * createPrime(int number) {
  Prime * newPrime;
  
  newPrime = malloc(sizeof(Prime));
  
  newPrime->num = number;
  newPrime->next = NULL;
  
  return newPrime;
}


/*this function should return a the prime number for that node */
int getNum(Prime * thePrime) {
  if (thePrime != NULL) {   
    return thePrime->num;
  } else {
    return 0;
  }
}

/*this function should free any memory allocated to the patron and 
should set all of the non-dynamic variables to a default value.  The pointer
to the patron will have to be freed separately */
void destroyPrime(Prime * thePrime) {
  
}


/* this function returns the number of digits in a function */
int countDigits(int n) {
  int counter;
  counter = 0;
  
  while (n != 0) {
    counter++;
    n /= 10;
  }
    
  return counter;
} 
