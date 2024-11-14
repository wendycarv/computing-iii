/*
 Computing III -- COMP.2010 Honor Statement
 The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and training as a practicing computing professional upon graduation. This practice is manifested in the University's Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein. All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.
      
 I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.

 Date: 09/07/2023
 Name: Wendy Carvalho
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

//#define MIN_NUM_DICE 2
const int MIN_NUM_DICE = 2;
//#define MAX_NUM_DICE 5
const int MAX_NUM_DICE = 5;
//#define MAX_DIE_VALUE 6
const int MAX_DIE_VALUE = 6;
using namespace std;


int get_numOfDice(void);
int roll_dice(int numOfDice);
int find_average(int sum, int numOfDice);

int main(int argc, char* argv[])
{
    int numOfDice;
    int counter = 0;
    int* dice;

    int sum;
    double average;
    
    numOfDice = get_numOfDice();
    sum = roll_dice(numOfDice);
    average = find_average(sum, numOfDice);
    
    printf("Sum of dice values: %d\n", sum);
    printf("Average of dice values: %g\n", average);
    
    return 0;

}

int find_average(int sum, int numOfDice)
{
    double average = 0;
    average = (double)sum/numOfDice; //casting
    return average;
}

int roll_dice(int numOfDice)
{
    int counter = 0;
    int* dice;

    int sum = 0;
    double average;
    
    int highest = 6;
    int lowest = 1;
    int range = highest - lowest;
    
    time_t t;
    srand((unsigned int)time(NULL));
    
    dice = (int*)malloc(sizeof(int) * numOfDice);
    if (dice == NULL)
    {
        printf("Unable to allocate memory for array.\n");
        exit (1);
    }

    for (counter = 0; counter < numOfDice; counter++)
    {
        dice[counter] = lowest + rand() % range;
        sum += dice[counter];
        //printf("Value of dice #%d: %d\n", counter + 1, dice[counter]);
        std::cout << "Die value: ";
        std::cout << dice[counter] << std::endl;
    }
    
    return sum;
}

int get_numOfDice(void)
{
    int numOfDice;
    
    printf("Let's roll some dice!\n");
    do {
        //printf("Please enter the number of dice (2-5):\n");
        std::cout << "Please enter the number of dice (2-5):"; //standard name space
        //scanf("%d", &numOfDice);
        std::cin >> numOfDice;
    }
    while (numOfDice < MIN_NUM_DICE || numOfDice > MAX_NUM_DICE);
    
    return numOfDice;
}
