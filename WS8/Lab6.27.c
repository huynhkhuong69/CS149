/**
 * Description: 6.27 LAB: Count characters- functions
    Write a program whose input is a character and a string, 
    and whose output indicates the number of times the character appears in the string. 
    The output should include the input character and use the plural form, n's, 
    if the number of times the characters appears is not exactly 1. 
    Assume that the string does not contain spaces and will always contain less than 50 characters.
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Creation date: 03/27/23
 **/

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

int main()
{
    //Declare character c and array that hold less than 50 chars
    char c, str[50];
    //Initialize count
    int count = 0, i;

    //scan user input
    scanf("%c", &c);
    scanf("%s", str);

    //Loop through the user input and check if it is match then increases the counter
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
            count++;
    }
    //Check if any character occurrence in a string ,
    //If it is print total number of time it appear in the string including the a character and space between
    //If it is not appear in the string then print 0 and character plus 's for plural form and a space between
    if (count == 1)
        printf("%d %c\n", count, c);
    else

        printf("%d n's\n", count);

    return 0;
}
