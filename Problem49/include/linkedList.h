#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BOOL_H
#define BOOL_H
typedef int bool;
enum {false, true};
#endif

/* this header file outlines all of the required functions for your linked list
   and the struct.  you may, of course, add any functions you wish.  This is the minimum set */

/*define your struct here */

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

/*********************
REQUIRED
Linked List functions
*************************/


/*This function returns true if the list is empty and false in all other cases.  
  The function does not change the list in any way */
bool isEmpty(ListHeadPtr theList);

/*This function adds the node sent in as a parameter to the front of the list that
  is given as a parameter.  The function returns the new head of the list.  */
ListHeadPtr addToFront(ListHeadPtr theList, Prime * toBeAdded);

/*This function removes the first item from the given list,  sets the next pointer of that item to NULL
  and returns a pointer to the new head of the list (the item that was the second item*/
ListHeadPtr removeFromFront(ListHeadPtr theList);

/*This function adds the node sent as a parameter to the back of the list sent in as a parameter.
  It returns a pointer to the head of the list */
ListHeadPtr addToBack(ListHeadPtr  theList, Prime * toBeAdded);

/*This function removes the last item from the list and returns a pointer
  to the head of the list. The function sets the next pointer of the new last 
item to NULL and it sets the next pointer of the removed item to NULL */
ListHeadPtr removeFromBack(ListHeadPtr  theList);

/*This function returns a pointer to the last item in the linked list that is
  given as a parameter.  The function does not change the list in any way */
Prime * getBack(ListHeadPtr theList);

/*this function must print the patron ID for each patron in the list to a string beginning with 
the front of the list. The 
Prime Ids must be printed one per line with a newline immediately following the id.
The function should return the string */
char * printList(ListHeadPtr  theList, int maxDigits);

/*this function should free all the memory for the list, except possibly the head pointer
  which will need to be freed separately */
void destroyPrimeList(ListHeadPtr theList); 


/***********
REQUIRED
Prime functions
************/

/*This list just takes in a prime number and returns a Prime struct*/
Prime * createPrime(int number);

/*This function must returns the prime number for that node */
int getNum(Prime * thePrime);

/*this function should free any memory allocated to the patron and 
should set all of the non-dynamic variables to a default value.  The pointer
to the patron will have to be freed separately */
void destroyPrime(Prime * thePrime);

/* this function returns the number of digits in a function */
int countDigits(int n);
