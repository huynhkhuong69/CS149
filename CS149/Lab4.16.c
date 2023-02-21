/**
 * Description: 4.14 LAB: Write a program that takes in a positive integer as input, and outputs a string of 1's and 0's representing the integer in reverse binary
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Creation date: 02/19/23
 **/

#include <stdio.h>
int main(void) {

   //Declare variables
    int userInput , max = -1, count = 0;
    double average, total = 0;

    //loop through userInput until negative number enter
    while(1)
    {
        scanf("%d", &userInput);
        //if the userInput is less than 0 or negative 
        //then we calculate average
        // and we print out average and max
        // then we stop the loop
        if (userInput < 0) {
            average = total / count;
            printf("%d %0.2lf\n", max, average);
            break;
        }
        // if the input is positive integers we calculate the total
        // and update the max and count
        else {
            count +=1;
            total += userInput;
            if (userInput > max) 
                max = userInput;
        }
    }
    return 0;
}