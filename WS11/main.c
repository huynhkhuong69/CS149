/**
 * Description: 8.14 LAB: Contacts
 (1) Complete main.c to define the struct ContactNode with the following data members:

        char contactName[]
        char contactPhoneNumber[]
        ContactNode* nextNodePtr
 (2) Add the following functions:

        InitializeContactNode() with parameters for name followed by phone number
        GetName() - Accessor 
        GetPhoneNumber() - Accessor 
        InsertAfter() 
        GetNext() - Accessor 
        PrintContactNode()
 (2) Define main() to read the name and phone number for three contacts and output each contact. Create three ContactNodes and use the nodes to build a linked list.

     Note: End the last input line with a newline.

 (3) Output the linked list using a loop to output contacts one at a time. 
     
     Ex:
        CONTACT LIST
        Name: Roxanne Hughes
        Phone number: 443-555-2864

        Name: Juan Alberto Jr.
        Phone number: 410-555-9385

        Name: Rachel Phillips
        Phone number: 310-555-6610
**/

#include <stdio.h>
#include"ContactNode.c"

// Driver code
int main()
{
    struct ContactNode* start;
    struct ContactNode* t;
    int i;
    char Name[50],phoneNo[50];

    // for loop to take user inputs
    for(i=1;i<=3;i++)
    {
        printf("\nPerson %d\n",i);
        printf("Enter name:\n");
        gets(Name);

        printf("Enter phone number:\n");
        gets(phoneNo);

        //Check if it equal 1 then create contact node, assigned t to start node
        //Otherwise, insert contact node then print out
        if(i==1)
        {
            start=CreateContactNode(t,Name,phoneNo);
            t=start;
        }
        else
            t=InsertContactAfter(t,Name,phoneNo);

        printf("You Entered: %s, %s\n",t->ContactName,t->ContactPhone);
    }
    // print the contact list
    printf("\nCONTACT LIST");

    // print out the list by traversing each node from start to end
    t=start;
    while(t)
    {
        PrintContactNode(t);
        t=GetNextContact(t);
    }
}