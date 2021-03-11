/********************************/
/* Program Name: Checksum Ver. C*/
/* Author: Adrian Gonzalez III  */
/* Date: 2-12-21                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include <math.h> 

#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {
    int offset = 0;
    int number = 0;
    int ascii_value = 0;
    int digit = 0;
    int total = 0;
    int valueOfBit = 0;
    int count = 1;
    int total2 = 0;
    
    int retval = read(0, &ascii_value, 1);

    while (retval == 1){

	    // This is where i do all my binary -> dec convertions

        digit = ascii_value - offset;
        fprintf(stdout, "Digit = %d : ascii value = %u \n", digit, ascii_value); 
        //tells me what the hell this thing does, and what ascii value is

        number = (number << 1) + digit;  
        fprintf(stdout, "Number = %d \n", number);
        // what do this do?

        //this will change depending on how many bits read give me. 1 or 8. 


        for (int i = 0; i < 8; i++) { // assummes 8 bits in one read. 
            valueOfBit = (ascii_value / (int) (pow(10, i)+.5)) - 10 * (ascii_value / (int) (pow(10, i + 1)+.5) );
		fprintf(stdout, "valueOfBit = %d ", valueOfBit); 
            if (valueOfBit == 0 || valueOfBit == 1) {
                total += ascii_value * (int) (pow(2, i)+.5); // probaby makes dec value, look over this again
            }
            else {
                fprintf(stderr, "Error Detected! NOT A BINARY NUM\n");
                return 1;
            }
        }

        //assumes 1 bit read 
        //(place before while) 

        if (ascii_value == 0 || ascii_value == 1){
            total2 += ascii_value * (int) (pow(2, count)+.5);
        } else {
            fprintf(stderr, "Error Detected! NOT A BINARY NUM (or not single bit intake)\n");
            //return 1;
        }
        count ++;
        if (count < 9) {
            count = 1;
        }

        

        retval = read(0, &ascii_value, 1);
    }
    fprintf(stdout, "Total = %d \n", total);
    fprintf(stdout, "Total 2 = %d \n", total2);

    number = 64;
    // this is where i convert Decimal to ascii
    printf("%u\n", number);
    return 0;
}
