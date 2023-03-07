/**
 * Description: 1.19 LAB: Warm up: Basic output with variables
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Creation date: 02/03/23
 **/

#include <stdio.h>
int main() {

    /*
    Enter integer:
    4
    You entered: 4
    4 squared is 16 
    And 4 cubed is 64!!
    Enter another integer:
    5
    4 + 5 is 9
    4 * 5 is 20
    */

    int input1;
    int input2;
    //user input
    printf("Enter integer: \n");
    scanf("%d", &input1);

    //user enter
    printf("You entered: %d\n", input1);
    //square input
    printf("%d squared is %d\n", input1, (input1* input2));
    //cubed
    printf("And %d cubed is %d\n", input1, (input1 * input1 * input1));

    //second input
    printf("Enter another integer: \n");
    scanf("%d", &input2);
    
    //add input1 & input2
    printf("%d + %d is %d\n", input1, input2, input1 + input2);
    //multiple input1 & input2
    printf("%d * %d is %d\n", input1, input2, input1 + input2);
    
    return 0;
}
