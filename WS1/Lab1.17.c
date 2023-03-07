/**
 * Description: 1.17 LAB: Input and formatted output: Right-facing arrow
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Creation date: 02/03/23
 **/
#include <stdio.h>

int main()
{
    //declare the variable
    int baseInt;
    int headInt;
    
    //ask to input the base and head value
    scanf("%d%d",&baseInt, &headInt);
    //make a right arrow using printf
    printf("    %d\n", headInt);
    printf("    %d%d\n", headInt, headInt);
    printf("%d%d%d%d%d%d%d\n", baseInt, baseInt, baseInt, baseInt, headInt, headInt, headInt);
    printf("%d%d%d%d%d%d%d%d\n", baseInt, baseInt, baseInt, baseInt, headInt, headInt, headInt, headInt);
    printf("%d%d%d%d%d%d%d\n", baseInt, baseInt, baseInt, baseInt, headInt, headInt, headInt);
    printf("    %d%d\n", headInt, headInt);
    printf("    %d\n", headInt);
    
    return 0;
}