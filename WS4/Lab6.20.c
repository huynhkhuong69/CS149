/**
 * Description: 6.20 LAB: One lap around a standard high-school running track is exactly 0.25 miles. Define a function named LapsToMiles that takes a double as a parameter, representing the number of laps, and returns a double that represents the number of miles. Then, write a main program that takes a number of laps as an input, calls function LapsToMiles() to calculate the number of miles, and outputs the number of miles.
 * Author names: Khuong Huynh
 * Author emails: khuong.huynh@sjsu.edu
 * Creation date: 02/27/23
 **/
#include <stdio.h>

/* Define a function call */
/* Calculate miles by multiply userLaps with 0.25 */
double LapsToMiles(double userLaps) {
    return userLaps * 0.25;
}

//main
int main(void) {
    double laps;

    //Prompt user enter number of laps 
    //Read the input and call the LapsToMiles func and print out miles
    printf("Enter number of laps: ");
    scanf("%lf", &laps);
    printf("%.2lf\n", LapsToMiles(laps));

    return 0;
}
