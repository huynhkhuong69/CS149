/**
 * Description: 5.28 LAB: Define a function named SortArray that takes an array of integers and the number of elements in the array as parameters. 
 * Function SortArray() modifies the array parameter by sorting the elements in descending order (highest to lowest). 
 * Then write a main program that reads a list of integers from input, stores the integers in an array, calls SortArray(), and outputs the sorted array. 
 * The first input integer indicates how many numbers are in the list. 
 * Assume that the list will always contain less than 20 integers.
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Creation date: 03/13/23
 **/

#include <stdio.h>

void SortArray(int sortingList[], int numVals)
{

    //Declare variables
    //Loop through the input then sort from high to low
    //Apply Bubble sort
    int i, j, temp;
    for (i = 0; i < numVals; i++)
    {
        for (j = 0; j < numVals - i - 1; j++)
        {
            if (sortingList[j] < sortingList[j + 1])
            {
                temp = sortingList[j];
                sortingList[j] = sortingList[j + 1];
                sortingList[j + 1] = temp;
            }
        }
    }
}

int main()
{
    //Declare variables that hold max. 20 chars
    //Counter, i
    //scan the input then count
    //loop through scan the array then sorting
    int arr[20];
    int count, i;
    scanf("%d", &count);
    for (i = 0; i < count; i++)
        scanf("%d", &arr[i]);

    SortArray(arr, count);

    for (i = 0; i < count; i++)
        printf("%d,", arr[i]);
    printf("\n");

    return 0;
}