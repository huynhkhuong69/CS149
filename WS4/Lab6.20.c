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
