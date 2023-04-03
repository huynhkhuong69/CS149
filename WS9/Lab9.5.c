/**
 * Description: 
    (1) Prompt the user for a string that contains two strings separated by a comma.
    (2) Report an error if the input string does not contain a comma. Continue to prompt until a valid string is entered. Note: If the input contains a comma, then assume that the input also contains two strings.
    (3) Extract the two words from the input string and remove any spaces. Store the strings in two separate variables and output the strings.
    (4) Using a loop, extend the program to handle multiple lines of input. Continue until the user enters q to quit.
 * 
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Creation date: 04/02/23
 **/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    //Declare variables to store the user inputs
    //input1 hold user input string
    char input[100];
    //input1 hold first word
    char input2[50];
    //input2 hold second word
    char input3[50];

    //Infinity loop 
    while(1)
    {   
        //Prompt user for input
        printf("Enter a string:\n");

        //fgets(input, sizeof input, stdin);

        gets(input);
        //Check if user enter q then quit the program
        if(strcmp(input, "q") == 0)
        {
            return 0; //return with no error
        }
    

    //initialize n to string length and i, j, k
    int n = strlen(input);
    int i = 0, j = 0, k = 0;
    
    //Loop through the string to check for comma
    for(i = 0; i < n; i ++) 
    {
        if (input[i] == ',')
        {
            k++;
            break; //get out of the loop
        }
    }
    //Check if no comma in the string, print error
    if (k == 0)
    {
        printf("Error: No comma in string.\n");
        continue; //stop iteration and start new one
    }
    
    // initialize i equal 0
    //Check if there is a comma, print first word and second word follow by a newline
    i = 0;
    while(input[i] != ',')
    {
        input2[i] = input[i];
        i++;
    }
    printf("First word: ");
    puts(input2);
    i++;
    //Check if there is any white space then remove it and store the two strings in separate variables
    while(i < n)
    {
        if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            input2[j] = input[i];
            j++;
        }
        i++;
    }
    printf("Second word: ");
    puts(input2);

    //Loop through string and store Null for first word and second word
    for (i = 0; i < n; i++)
    {
        input2[i]='\0';
        input3[i]='\0';
    }
    //calls force out the output to standard output
    fflush(stdin);

    }//end infinity loop
    return 0;
}
