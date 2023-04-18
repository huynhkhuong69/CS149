#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ContactNode.h"

struct ContactNode* CreateContactNode(struct ContactNode* p, char name[], char phone[]){

    if((p=(struct ContactNode*)malloc(sizeof(struct ContactNode)))==NULL)
    {
        printf("Error - Could not allocate memory. Exiting...\n");
        exit(0);
    }

    strcpy(p->ContactName,name);
    strcpy(p->ContactPhone,phone);
    p->nextNodePtr=NULL;
    return(p);
}

struct ContactNode* InsertContactAfter(struct ContactNode* p,char name[], char phone[]){
    struct ContactNode* temp;

    // if list is empty
    if(p==NULL)
    {
        p=CreateContactNode(temp,name,phone);

        // create and return the first node in the list
        return(p);
    }
    else
    {
        temp=CreateContactNode(temp,name,phone);

        // create a new node and link it to the previous node in the list
        p->nextNodePtr=temp;
    }
        return(temp);
}

// return Location Pointed by nextNodePtr
struct ContactNode* GetNextContact(struct ContactNode* p){
    return p->nextNodePtr;
}

// print a node
void PrintContactNode(struct ContactNode* p) {

    printf("\nName: %s\n",p->ContactName);
    printf("Phone Number: %s\n",p->ContactPhone);
}