#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double convStrToDouble (char* stringNumber);

int main(void) {
  FILE* numFile;
  char buffer[50];
  char* base;
  char* power;
  double biggestNumber, curNum, curExpo, logValue;
  int lineNumber, answerLineNumber;
  
  lineNumber = 0;
  biggestNumber = 0;


  numFile = fopen("base_exp.txt", "r");
  if (numFile == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }
  
  while(fgets(buffer, 50, numFile) != NULL) {
   
    /*increment the line number*/
    lineNumber++;

    /* parse the input buffer into the base and power */
    base = strtok(buffer, ",");
    power = strtok(NULL, "\0");

    /*convert them to double variables */
    curNum = atof(base);
    curExpo = atof(power);
   
    /*Calculate if it's the biggest number based on its log values */
    logValue = curExpo * log10(curNum);
    if(logValue > biggestNumber) {
      biggestNumber = logValue;
      answerLineNumber = lineNumber;
      printf("The biggest number is %lf on line %d\n", biggestNumber, lineNumber);
    }  

   
  }

  /*print the answer*/
  printf("The line containing the biggest number is %d\n", answerLineNumber);
  printf("There were %d lines of numbers.\n", lineNumber);

  return 0;
}
