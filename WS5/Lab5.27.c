
#include <stdio.h>
#include <string.h>

#define totalText 50

int main () {
    //Declare a variable char that take in an input with length of 50
    char text[totalText]; //max 50 chars

    //infinite loop run until break statement
    while(1) {
        printf("Please enter a lien of text (with max 50 characters), or type 'Done', 'done', 'd': ");

        //read inpput from user including spaces
        //fgets() gets input with maximum of 50 characters and stored it in text
        fgets(text, totalText, stdin);

        //Check if user entered "Done", "done", "d"
        if (strcmp(text, "Done\n") == 0 || strcmp(text, "done\n") == 0 || strcmp(text, "d\n") == 0)
        {
            break; //stop when user entered "Done", "done", "d"
        }

        //reverse the string
        //Declare integer name length 
        //iterate through the lenght of text divide by 2
        //store text index in the temp
        //reserve the text and print out the string
        int length = strlen(text);
        for (int i = 0; i < length / 2; i++) {
            char temp = text[i];
            text[i] = text[length - i - 2];
            text[length - i - 2] = temp;
        }

        printf("%s\n", text);
    }

    return 0;
}