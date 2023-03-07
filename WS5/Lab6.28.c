/**
 * Description: 1.15 LAB: Write a program that removes all non-alphabetic characters from the given input. 
 * Assume the input string will not exceed 50 characters.
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Creation date: 02/06/23
 **/
#include <stdio.h>

//Function remove all the non-alphabets characters
void RemoveNonAlpha(char userString[], char userStringAlphaOnly[])
{
    int i, j;
    
    //iterate through the input string
    for (i = 0; userString[i] != '\0'; i++)
    {   
        //Check ASCII to check for Alphabets
        while (!( (userString[i] >= 'a' && userString[i] <= 'z') || (userString[i] >= 'A' && userString[i] <= 'Z') || userString[i] == '\0') )
        {   
            //Check for string input but not NULL value
            for (j = i; userString[j] != '\0'; j++)
            {
                userString[j] = userString[j + 1];
            }
            userString[j] = '\0';
        }
        userStringAlphaOnly[i] = userString[i];
    }
}

#include <stdio.h>
int main() {

    //Declare variables
   char userString[50], userStringAlphaOnly[50];

   //Read the input from user
   printf("Enter string with special character: ");
   gets( userString);

   //Call RemoveAlphaOnly
   RemoveNonAlpha(userString, &userStringAlphaOnly);

   //Print out the string with non-alphabets
    printf("Non-Alphabets string: ");
    puts(userStringAlphaOnly);
    return 0;
}
