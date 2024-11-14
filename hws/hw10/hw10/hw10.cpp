/*
Author: Wendy Carvalho
Date: 12/6/2023
Purpose: This program creates permutations of a list of strings (input by user, separated by spaces) and checks for duplicates and removes them. It then prints out the permutations.
Sources of Help: cplusplus.com
Time Spent: 50min
*/


#include <iostream>
#include <algorithm>
#include <sstream>
#include <list>
#include <string>

using namespace std;

template <class T>
list<string> generate_permutations(list<T> &iList);

template <class T>
void print_permutations(const list<T> &iList);

int main(int argc, char *argv[])
{
    list<string> inputList;
    string aLine, aString;
    
    // read in strings from stdin
    cout << "Enter strings, separated by a space: ";
    getline(cin, aLine); //read a line from keyboard
    istringstream iss(aLine); //convert aLine to an istringstream obj
    
    //parse each string
    while(iss >> aString) {
        inputList.push_back(aString);
    }
    
    auto permutations = generate_permutations(inputList);
    
    // print permutations to stdout
    print_permutations(permutations);
    return 0;
}

template <class T>
list<string> generate_permutations(list<T> &iList){
    list<string> permutationsList;
    string permutation;
    
    typename list<T>::iterator f = iList.begin();
    typename list<T>::iterator l = iList.end();

    //check for duplicates in iList
    iList.sort();                       // cplusplus.com/reference/algorithm/sort/
    iList.unique();                     // cplusplus.com/reference/algorithm/unique/
    
    do {
        permutation = "";
        for (auto it = iList.begin(); it != iList.end(); ++it)
        {
            permutation += *it + " ";
        }
        permutationsList.push_back(permutation);
    } while (next_permutation(f, l));   // cplusplus.com/reference/algorithm/next_permutation/
    
    permutationsList.sort();
    return permutationsList;
}

template <class T>
void print_permutations(const list<T> &iList){
    
    int i = 1;
    cout << "Permutations are:\n";
    for (auto &each:iList){
        cout << i << ".\t" << each << endl;
        i++;
    }
}

/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein.
All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.
Date: 12/6/2023
Name: Wendy Carvalho
*/
