/*doesn't work */

#include <stdio.h>
#include <math.h>

int main(void) {
    double D, y, x, highestMinx = 0, IdealD = 0;
	int boolean;
	
	for (D = 1; D <= 150; D++) {
	
	    if (floor(sqrt(D)) == sqrt(D)) { //check to see if D is a square number
		    printf("\nThis number is being skipped: %lf", D);
			D++;
		}
		y = 1; //reset y to 1 for each different value of D
		boolean = 0;
		x = sqrt(1 + D*y*y); //calculate x with the diophantine equation
		while (boolean == 0) { 
		    /* if statement checks to see if the value of x is a whole number. If not, it inceases y and calculates again */
		    if (floor(x) != x) {
			    y++;
		        x = sqrt(1 + D*y*y);
				//printf("\nx = %lf", x);
		    } else {
			    boolean = 1;
				printf("\nD = %lf and y = %lf", D, y);
		    }
		}
		if (x > highestMinx) {
		    highestMinx = x;
		    IdealD = D;
			printf("\nThe D value that produces the highest minimum solution of X is %.1lf with an x value of %.1lf", IdealD, highestMinx);
		}
		
		
		
		
	}
}