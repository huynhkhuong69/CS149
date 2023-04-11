#include "ItemToPurchase.h"

//Define a function 
void MakeItemBlank(struct ItemToPurchase* item) {
    // copy the string and initializing the variables.
    strcpy(item->itemName, "none");
    item->itemPrice = 0;
    item->itemQuantity = 0;
}

void PrintItemCost(struct ItemToPurchase* item) {
    // display the result on console.
    printf("%s %d @ $%d = $%d\n", item->itemName, item->itemQuantity, item->itemPrice, item->itemQuantity * item->itemPrice);
}