/**
 * Description: 6.30 LAB: Write a program whose inputs are four integers, and whose outputs are the maximum and the minimum of the four values.
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Creation date: 02/27/23
 **/

#include <stdio.h>

/* Define function MIN/Max */
int MaxNumber(int num1, int num2, int num3, int num4) {
    int max;
    
    //if num1 greater than num2 then max is num1
    //else max is num2
    //if num3 greater than max then max is num3
    //if num4 greater than max then max is num4
    //return max
    if(num1 > num2) {
        max = num1;
    }
    else {
        max = num2;
    }
    if (num3 > max) {
        max = num3;
    }
    if (num4 > max) {
        max = num4;
    }
    return max;
}

int MinNumber(int num1, int num2, int num3, int num4) {
    int min;
    
    //if num1 less than num2 then min is num1
    //else min is num2
    //if num2 less than min then min is min2
    //if num3 less than min then min is num3
    //if num4 less than min then min is num4
    //return min
    if (num1 < num2) {
        min = num1;
    }
    else {
        min = num2;
    }
    if (num2 < min) {
        min = num2;
    }
    if (num3 < min) {
        min = num3;
    }
    if (num4 < min) {
        min = num4;
    }
    return min;
}

int main(void) {
    //Declare variable to store numbers min/max
    int num1, num2, num3, num4;
    printf("Enter 4 integers to print min/max: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
    /* Calling min and max function and store in those variables*/
    int max=MaxNumber(num1,num2,num3,num4);        
    int min=MinNumber(num1,num2,num3,num4);
    printf("Maxinum is %d\n", max);
    printf("Minimum is %d\n", min);
    return 0;
}