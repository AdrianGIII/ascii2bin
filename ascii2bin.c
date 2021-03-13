/********************************/
/* Program Name: Checksum Ver. C*/
/* Author: Adrian Gonzalez III  */
/* Date: 2-12-21                */
/********************************/
//gcc -o ascii2bin ascii2bin.c -lm
//cat 54356.txt | ascii2bin

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#define byte unsigned char

int main (int argc, char *argv[], char ** envp) 
{
    int offset = 48;
    int number = 0;
    int retval = 0;
    int digit = 0;
    int ascii_value = 0;
    
    retval = read(STDIN_FILENO, &ascii_value, 1);
    
    int total = 0;
    int expHelp = 0;
    int count = 0;
    int exp = 1;
    int total2 = 0;
	
    while (retval == 1){
	ascii_value -= offset;
	fprintf(stdout, "ascii = %d  ", ascii_value);
	
	    
	
        if (ascii_value == 0 || ascii_value == 1){
            total2 += ascii_value * exp;
	    expHelp = 2 * exp;
	    exp = expHelp;
        } else {
            fprintf(stderr, "Error Detected! NOT A BINARY NUM \n");
            return 1;
        }
	    
	fprintf(stdout, "exponent = %d  ", exp);
	    
        count ++;
	fprintf(stdout, "count = %d  ", count);
	    
        if (count > 7) {
            count = 0;
	    exp = 1;
	    // replace with get ascii value  here
	    
        }
	
       fprintf(stdout, "Total 2 = %d \n", total2);

        retval = read(0, &ascii_value, 1);
    }
    fprintf(stdout, "Total 2 = %d \n", total2);
    
    
    return 0;
}
