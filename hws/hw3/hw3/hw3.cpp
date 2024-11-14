/*
Author: Wendy Carvalho
Date: 09/20/2023
Purpose: This program uses a class called Point to set, manipulate, and display coordinates. It takes a user's input for coordinate points, sets them, and manipulates them by rotating them 90º, and moving them left, right, up, and down along the graph.
Sources of Help: class notes
Time Spent: 1 hour and 30 minutes
*/

#include <iostream>
using namespace std;

class Point{
public:
    //default constructor
    Point();
    Point(int initX, int initY);
    void display(void);
    //member functions
    void moveCoords(int &x, int &y, int moveX, int moveY);
    void rotate90(void);
    
    //accessor functions (getters)
    int getCoords(void);
    //mutator functions (setters)
    void moveX (int increment);
    void moveY (int increment);
    
private:
    int x;
    int y;
};

int main(int argc, const char * argv[])
{
    int x1, x2, x3;
    int y1, y2, y3;
    int newValue = 0;
    
    //takes input from user for first coordinate and sets first_point to those values -> (1, 2)
    cout << "Think of 3 coordinate points.\nEnter the x value for the first coordinate: ";
    cin >> x1;
    cout << "Enter the y value for the first coordinate: ";
    cin >> y1;
    Point first_point(x1, y1);
    
    //takes input from user for second coordinate and sets second_point to those values --> (3, 4)
    cout << "Enter the x value for the second coordinate: ";
    cin >> x2;
    cout << "Enter the y value for the second coordinate: ";
    cin >> y2;
    Point second_point(x2, y2);

    //takes input from user for third coordinate and sets third_point to those values --> (5, -4)
    cout << "Enter the x value for the third coordinate: ";
    cin >> x3;
    cout << "Enter the y value for the third coordinate: ";
    cin >> y3;
    Point third_point(x3, y3);

    //display initial points
    cout << "First coordinate: ";
    first_point.display();
    cout << "Second coordinate: ";
    second_point.display();
    cout << "Third coordinate: ";
    third_point.display();
    
    //rotate first point (1, 2) 90 degrees four times and display coordinates after each rotation
    first_point.rotate90();
    cout << "First coordinate after one 90º rotation: ";
    first_point.display();

    first_point.rotate90();
    cout << "First coordinate after two 90º rotations: ";
    first_point.display();
    
    first_point.rotate90();
    cout << "First coordinate after three 90º rotations: ";
    first_point.display();
    
    first_point.rotate90();
    cout << "First coordinate after four 90º rotations: ";
    first_point.display();
    
    //move second point (3, 4) by (1, 1) (1 right, 1 up)
    second_point.moveX(1);
    second_point.moveY(1);
    //display new coordinates for second point
    cout << "Second coordinate after moving 1 right and 1 up: ";
    second_point.display();
    
    //move third point (5, -4) by (-5, 4) (5 left, 4 up)
    third_point.moveX(-5);
    third_point.moveY(4);
    //display new coordinates for third point
    cout << "Third coordinate after moving 5 left and 4 up: ";
    third_point.display();

    return 0;
}

//default constructor
Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int initX, int initY)
{
    x = initX;
    y = initY;
}

void Point::rotate90(void)
{
    if (x >= 0 && y >= 0)
    {
        x = x * (-1);
    }
    else if (x < 0 && y >= 0)
    {
        y = y * (-1);
    }
    else if (x < 0 && y < 0)
    {
        x = x * (-1);
    }
    else if (x >= 0 && y < 0)
    {
        y = y * (-1);
    }
}

void Point::moveX (int increment)
{
    x += increment;
}

void Point::moveY (int increment)
{
    y += increment;
}

void Point::display(void)
{
    cout << "(" << this->x << ", " << this->y << ")" << endl;
}

/*
 Computing III -- COMP.2010 Honor Statement
 The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein.
 All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.
 I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.
 Date: 09/20/2023
 Name: Wendy Carvalho
*/
