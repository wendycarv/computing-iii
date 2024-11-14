/*
Author: Wendy Carvalho
Date: 09/14/2023
Purpose: This program is a number guessing game. It allows two humans (users) to compete against each other until they guess the random number generated by the program. It also allows a human (user) to play against a computer (that is able to modify its guesses based on the last guess and whether it was too high or too low). Lastly, it also allows two of these more intelligent computers to play against each other.
Sources of Help: BitDegree.org
Time Spent: 1hr30min
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player{
public:
    virtual int getGuess() = 0;
    virtual void setMax(int x){
        max = x;
    };
    virtual void setMin(int x){
        min = x;
    };
private:
    int max;
    int min;
};

class HumanPlayer:public Player{
public:
    int getGuess(){
        cin >> guess;
        return guess;
    }
private:
    int guess;
};

class ComputerPlayer:public Player{
public:
    ComputerPlayer(): max(100), min(0){};
    int getGuess(){
        int range = max - min;
        if (range != 0)
            guess = (rand() % range) + min;
        else
            guess = max;
        cout << guess << endl;
        return guess;
    }
    void setMax(int x){
        max = x;
    }
    void setMin(int x){
        min = x;
    }
private:
    int guess;
    int max;
    int min;
};

bool checkForWin(int guess, int answer);
void play(Player &player1, Player &player2);

int main(int argc, const char * argv[]) {

    HumanPlayer h1, h2;
    ComputerPlayer c1, c2;
    
    srand((unsigned) time(NULL));

    cout << "*****Welcome to the number guessing game!*****" << endl;
    
    cout << "First, two humans shall play against each other." << endl;
    play(h1, h2);
    
    cout << "Next, a humans shall play against a computer." << endl;
    play(h1, c1);
    
    cout << "Lastly, two computers shall play against each other." << endl;
    play(c1, c2);

    return 0;
}

bool checkForWin(int guess, int answer) {
    if (answer == guess)
    {
        cout << "\t\tYou're right! You win!\n\n";
        return true;
    }
    else if (answer < guess)
        cout << "\t\tYour guess is too high." << endl;
    else
        cout << "\t\tYour guess is too low." << endl;
    return false;
}

void play(Player &player1, Player &player2) {
    int answer = 0, guess = 0;
    //int max = 100, min = 0;
    //int range = max - min + 1;
    srand((unsigned) time(NULL));
    answer = rand() % 101;
    //answer = rand() % 100;
    bool win = false;
    while (!win)
    {
        cout << "Player 1's turn to guess: ";
        guess = player1.getGuess();
        win = checkForWin(guess, answer);
        if (win)
            return;
        else
        {
            if (guess < answer)
            {
                player1.setMin(guess + 1);
                player2.setMin(guess + 1);
            }
            else
            {
                player1.setMax(guess - 1);
                player2.setMax(guess - 1);
            }
        }
        cout << "Player 2's turn to guess: ";
        guess = player2.getGuess();
        win = checkForWin(guess, answer);
        if (win)
            return;
        else
        {
            if (guess < answer)
            {
                player1.setMin(guess + 1);
                player2.setMin(guess + 1);
            }
            else
            {
                player1.setMax(guess - 1);
                player2.setMax(guess - 1);
            }
        }
    }
}

/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein.
All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.
 
Date: 11/17/2023
Name: Wendy Carvalho
*/