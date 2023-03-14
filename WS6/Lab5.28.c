/**
 * Description: 5.28 LAB: A palindrome is a word or a phrase that is the same when read both forward and backward. 
 * Examples are: "bob," "sees," or "never odd or even" (ignoring spaces). 
 * Write a program whose input is a word or phrase, and that outputs whether the input is a palindrome. 
 * You may assume that the input string will not exceed 50 characters. 
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Creation date: 03/013/23
 **/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <stdbool.h>
int main(void)
{
    //Declare variable with max input is 50 characters
    char userInput[50];
    //Set palindrome to true to check in the loop
    bool isPalindrome = true;
    //index at the start = 0
    //index at the end equal the length of userInput minus 1
    int left = 0;
    int right = strlen(userInput) - 1;

    //Prompt user input
    printf("Enter a word or phrase: ");
    // Read input string with spaces
    fgets(userInput, 50, stdin); 


    while (left <= right)
    {
        // ignores spaces from the beginning if a space is encountered
        while (isspace(userInput[left]))
        {
            ++left;
        }
        // ignores spaces from the end if a space is encountered
        while (isspace(userInput[right]))
        {
            --right;
        }
        //if input from the left != right return false
        // increase index from left and decrease right
        if (userInput[left] != userInput[right])
        {
            isPalindrome = false;
        }
        ++left;
        --right;
    }
    //Check if it is a palindrome then print it out
    if (isPalindrome)
    {
        printf("palindrome: %s\n", userInput);
    }
    else if (!isPalindrome)
    {
        printf("not a palindrome: %s\n", userInput);
    }
    return 0;
}
