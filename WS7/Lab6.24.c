/**
 * Description: 2.25 LAB: Swapping Variable
 * Define a function named SwapValues that takes four integers as parameters and swaps the first with the second, and the third with the fourth values. 
 * Then write a main program that reads four integers from input, 
 * calls function SwapValues() to swap the values, 
 * and prints the swapped values on a single line separated with spaces.
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Creation date: 03/20/23
 **/

#include <stdio.h>

/* Define your function here */ 
void SwapValues(int* userVal1, int* userVall2,  int* userVal3, int* userVal4){
    
    //Declare temp to store integer
    //Set first integer value in temp
    int temp = *userVal1;
    //Set second integer in integer 1
    *userVal1 = *userVall2;
    //Set integer 2 in temp
    *userVall2 = temp;
    
    //Swap integer 3 and 4
    temp = *userVal3;
    *userVal3 = *userVal4;
    *userVal4 = temp;
}

int main(void) {

    //Declare num1, num2, num3, num3
    int num1, num2, num3, num4;
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    //Call function SwapValues
    SwapValues(&num1, &num2, &num3, &num4);
    //Print he swap integers
    printf("%d %d %d %d\n", num1, num2, num3, num4);
    return 0;
}