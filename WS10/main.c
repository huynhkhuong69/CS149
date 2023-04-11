#include "ItemToPurchase.h"
#include <string.h>
#include <stdio.h>

int main()
{   
    //Declare the first and second function
    struct ItemToPurchase f_item;
    struct ItemToPurchase s_item;
    int sum = 0;

    MakeItemBlank(&f_item);
    MakeItemBlank(&s_item);

    // prompt the user to enter the details of first item.
    printf("Item 1\n");
    printf("Enter the item name:\n");
    scanf("%[^\n]", f_item.itemName);
    printf("Enter the item price: \n");
    scanf("%d", &f_item.itemPrice);
    printf("Enter the item quantity: \n");
    scanf("%d", &f_item.itemQuantity);

    char c = getchar();
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }

      // prompt the user to enter the details of second item.
    printf("\nItem 2\n");
    printf("Enter the item name:\n");
    scanf("%[^\n]", s_item.itemName);
    printf("Enter the item price: \n");
    scanf("%d", &s_item.itemPrice);
    printf("Enter the item quantity: \n");
    scanf("%d", &s_item.itemQuantity);

    //print total cost of first item and second item
    printf("\nTOTAL COST\n");
    PrintItemCost(&f_item);
    PrintItemCost(&s_item);
    sum = f_item.itemPrice * f_item.itemQuantity + s_item.itemPrice * s_item.itemQuantity;
    printf("\nTotal: $%d\n", sum);

    return 0;
}