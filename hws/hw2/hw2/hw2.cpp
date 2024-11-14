/*
Author: Wendy Carvalho
Date: 09/18/2023
COMP.2010 HW 02 F23 - Dr. Lin
Purpose: This program reads input from a file, finds every occurence of the word "dislike" in the text, replaces it with "love", and outputs the new text into a new file.
Sources of Help: cplusplus.com, stackoverflow.com
Time Spent: 1 hour
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    ifstream inStream;
    ofstream outStream;
    
    string word = "dislike";
    string word2 = "love";
    string temp;
    
    //open file to read from
    inStream.open("input.txt");
    //open file to write to
    outStream.open("output.txt");

    //taking every file from inStream (input.txt) and outputing to a temporary string temp
    while(inStream >> temp)
       {
           // if word ("dislike") is  found then replace with word2 ("love")
           if(temp == word)//if your word found then replace
           {
               temp = word2;
           }
           temp += " ";
           //output everything to outStream(output.txt)
           outStream << temp;
       }
    
    //close input file
    inStream.close();
    //close output file
    outStream.close();
    
    return 0;
}

/*
 
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein. All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.
 
Date: 09/18/2023
Name: Wendy Carvalho
*/
