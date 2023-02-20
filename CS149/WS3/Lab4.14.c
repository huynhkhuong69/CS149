/**
 * Description: 4.14 LAB: Write a program that takes in a positive integer as input, and outputs a string of 1's and 0's representing the integer in reverse binary
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Creation date: 02/19/23
 **/

#include <stdio.h>
int main(void) {
    
    //Declare variable x
    int x;
    //Prompt user to enter a positive ingeter
    printf("Enter a positive integer: ");
    //Read the input
    scanf("%d", &x);

    //Loop through and reverse the order
    while (x > 0) {
        //x modudo (remainder is either 0 or 1)
        printf("%d", x % 2);
        x =  x / 2;
    }

    return 0;
