/*
Author: Wendy Carvalho
Date: 09/14/2023
Purpose: This program is a number guessing game. It takes the range in between two numbers the user inputs and generates a random number in that range for the player to guess, with limited guesses.
Sources of Help: N/A
Time Spent: 1hr
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int random_number_generator(int min, int max);
int player_guess(int random, int numOfGuesses);
int play_game(void);

int main(int argc, const char * argv[])
{
    bool play_again;
    
    do {
        play_again = play_game();
    } while (play_again == 1);
    
    return 0;
}

int play_game(void)
{
    int min;
    int max;
    int numOfGuesses;
    int random;
    bool play_again;
    
    cout << "*****Welcome to the number guessing game!*****";
    cout << "Enter a postive number. This will be your minimum number: ";
    cin >> min;
    while (min <= 0)
    {
        cout << "Please enter a positive number: ";
        cin >> min;
    }
    
    cout << "Enter a number greater than your minimum number and less than 1,000: ";
    cin >> max;
    while (max < min || max >= 1000)
    {
        cout << "Please enter a number greater than your minimum number and less than 1,000: ";
        cin >> max;
    }
    
    cout << "Enter the number of guesses you'd like to have (has to be less than 10): ";
    cin >> numOfGuesses;
    while (numOfGuesses <= 0 || numOfGuesses >= 10)
    {
        cout << "Please enter a number of guesses between 1 and 9: ";
        cin >> numOfGuesses;
    }
    
    random = random_number_generator(min, max);
    if ((player_guess(random, numOfGuesses)) == 1)
    {
        cout << "Congrats, you win! ";
    }
    else
    {
        cout << "You lose! The number I was thinking of was " << random << "." << endl;
    }
    
    cout << "Would you like to play again? Type (1) for yes, and (0) for no:\n";
    cin >> play_again;
    
    return play_again;
    
}

int random_number_generator(int min, int max)
{
    int range = max - min + 1;
    srand((unsigned) time(NULL));
    int random = min + (rand() % range);
    
    return random;
}

int player_guess(int random, int numOfGuesses)
{
    int guess;
    cout << "Guess the number I'm thinking of. It's in between the numbers you gave me. You have " << numOfGuesses << " guess(es) remaining:\n";
    cin >> guess;
    
    while (numOfGuesses > 0)
    {
        numOfGuesses--;

        if (guess > random)
        {
            cout << "Too high! ";
        }
        else if (guess < random)
        {
            cout << "Too low! ";
        }
        else
        {
            return 1;
        }
        
        if (numOfGuesses > 0)
        {
            cout << "Try again: \n";
            cin >> guess;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

/*
 
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
 
Date: 09/14/2023
Name: Wendy Carvalho
*/
