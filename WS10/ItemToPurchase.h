#ifndef ItemToPurchase_H
#define ItemToPurchase_H

#include <string.h>
#include <stdio.h>

struct ItemToPurchase {
    //Declares variables
    char itemName[30];
    int itemPrice;
    int itemQuantity;
};

//Declare functions
void MakeItemBlank(struct ItemToPurchase* item);
void PrintItemCost(struct ItemToPurchase* item);

#endif