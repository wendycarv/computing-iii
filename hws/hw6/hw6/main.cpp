/*
Author: Wendy Carvalho
Date: 11/01/2023
Purpose: This program opens a file with movie names and their respective ratings, adds this information to a multimap, along with the order they appear in to a vector, and how many ratings for each movie to a normal map. It then uses this data to calculate the average of ratings for each their movie and prints this out in the order in which they originally appeared in the input file.
Sources of Help: GeekforGeeks, notes;
Time Spent: 3 hours
*/

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    string title;
    int rating;
    int i;
    int numOfRatings;
    
    multimap<string, int> movie_rating;
    map<string, unsigned> movies;
    vector<string> movieOrder;
    
    ifstream inStream;
    
    inStream.open("/Users/wendy/Downloads/movies.txt");
       if (inStream.fail())
       {
           cout << "Can't open file" << endl;
           exit(1);
       }
    
    inStream >> numOfRatings;
    
    for (i = 0; i < numOfRatings; i++)
    {
        inStream.ignore(); //ignoring first \n after # of ratings
        getline(inStream, title);
        inStream >> rating;
        
        movie_rating.insert(pair<string, int>(title, rating));
        if (movies.find(title) == movies.end())
        {
            movies[title] = 1;
            movieOrder.push_back(title);
        } else {
            movies[title]++;
        }
    }
       
    inStream.close();

    int currRatingTotal = 0;
    double currAverage = 0;
    
    /*
    for (auto &each:movie_rating)
    {
        if(movies[each.first] > 1)
        {
            auto p = movie_rating.begin();
            currRatingTotal = 0;
            while(p != movie_rating.end())
            {
                if ((*p).first == each.first)
                {
                    currRatingTotal += (*p).second;
                }
                p++;
            }
            currAverage = static_cast<double>(currRatingTotal)/ movies[each.first];
            cout << each.first << ":   " << movies[each.first] << " reviews, average of " << fixed << setprecision(1) << currAverage << " / 5" << endl;
            movies[each.first] = 0;
            
        }
        else if (movies[each.first] == 1)
        {
            currAverage = each.second;
            cout << each.first << ":   " << movies[each.first] << " review, average of " << currAverage << " / 5" << endl;
        }
    }
    */
    
    for (auto &each:movieOrder)
    {
        if(movies[each] > 1)
        {
            auto p = movie_rating.begin();
            currRatingTotal = 0;
            while(p != movie_rating.end())
            {
                if ((*p).first == each)
                {
                    currRatingTotal += (*p).second;
                }
                p++;
            }
            currAverage = static_cast<double>(currRatingTotal)/ movies[each];
            cout << each << ":   " << movies[each] << " reviews, average of " << fixed << setprecision(1) << currAverage << " / 5" << endl;
            movies[each] = 0;
            
        }
        else if (movies[each] == 1)
        {
            auto p = movie_rating.find(each);
            currAverage = (*p).second;
            cout << each << ":   " << movies[each] << " review, average of " << fixed << setprecision(0) << currAverage << " / 5" << endl;
        }
    }
    
    return 0;
}

/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein.
 
All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.
 
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.
 
Date: 11/01/2023
Name: Wendy Carvalho
 
*/
