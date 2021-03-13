/********************************/
/* Program Name: Bin2Ascii      */
/* Author: Adrian Gonzalez III  */
/* Date: 2-12-21                */
/********************************/


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
	
    while (retval == 1){
	
	ascii_value -= offset;    
	
        if (ascii_value == 0 || ascii_value == 1){
            digit = ascii_value - offset;
            number = (number << 1) + digit;  
        } else if (ascii_value == -38){
		
	} else {
	    
            fprintf(stderr, "Error Detected! NOT A BINARY NUMBER \n");
            return 1;
        }
	    
	if (number > 4294967295){
            fprintf(stderr, "Error Detected! NUMBER TOO LARGE \n");
            return 1;
	}
	    
	if (ascii_value != -38){
	    retval = read(0, &ascii_value, 1);
	} else {
	    retval = 0;
	}
	
        
    }
    
    
    return 0;
}
