/*
Author: Wendy Carvalho
Date: 09/30/2023
Purpose: This program does many operations with fractions defined by the user's input that are put into a class object called Rational. It finds the sum, difference, product, quotient, and also compares the two to see if they're equal to each other or greater or less than the other. It
Sources of Help: Class notes
Time Spent: 3 days
*/

#include <iostream>
using namespace std;

class Rational{
public:
    //default constructor
    Rational(): numerator(0), denominator(1){};
    Rational(int wholeNumber);
    Rational(int initNumerator, int initDenominator);
    //mutators
    void setNumerator(int newValue);
    void setDenominator(int newValue);
    //accessors
    int getNumerator(void)const;
    int getDenominator(void)const;
    
    void simplifyFraction(Rational fraction);
    int calculateLCD(int denominatorA, int denominatorB);

    friend ostream& operator <<(ostream &out, const Rational& frac);
    friend istream& operator >>(istream &in, Rational&);
    friend bool operator==(const Rational &fractionA, const Rational &fractionB);
    friend bool operator<=(const Rational &fractionA, const Rational &fractionB);
    friend bool operator>=(const Rational &fractionA, const Rational &fractionB);
    friend bool operator<(const Rational &fractionA, const Rational &fractionB);
    friend bool operator>(const Rational &fractionA, const Rational &fractionB);
    friend const Rational operator+(const Rational &fractionA, const Rational &fractionB);
    friend const Rational operator-(const Rational &fractionA, const Rational &fractionB);
    friend const Rational operator*(const Rational &fractionA, const Rational &fractionB);
    friend const Rational operator/(const Rational &fractionA, const Rational &fractionB);

    //void display(void);
private:
    int numerator;
    int denominator;
    int calculateGCD(int a, int b);
    void normalize(int &a, int &b);
};

//output stream
ostream& operator <<(ostream &out, const Rational& frac);
//input stream
istream& operator >>(istream &in, Rational&);
//overload ==
bool operator==(const Rational &fractionA, const Rational &fractionB);
//overload <=
bool operator<=(const Rational &fractionA, const Rational &fractionB);
//overload >=
bool operator>=(const Rational &fractionA, const Rational &fractionB);
//overload <
bool operator<(const Rational &fractionA, const Rational &fractionB);
//overload >
bool operator>(const Rational &fractionA, const Rational &fractionB);
//overload +
const Rational operator+(const Rational &fractionA, const Rational &fractionB);
//overload -
const Rational operator-(const Rational &fractionA, const Rational &fractionB);
//overload *
const Rational operator*(const Rational &fractionA, const Rational &fractionB);
//overload /
const Rational operator/(const Rational &fractionA, const Rational &fractionB);

int main(int argc, const char * argv[])
{
    Rational default_fraction, numerator_only, r1, r2, sum, difference, product, quotient;
    int wholeNumber;
    bool comparison;
    
    cout << "Default fraction: " << default_fraction << endl;
    
    cout << "Now enter a number. This will be the numerator of a fraction that has a denominator of 1. " << endl;
    cin >> wholeNumber;
    
    numerator_only = Rational(wholeNumber);
    cout << "The fraction is: " << numerator_only << endl;
    
    cout << "Enter a fraction: " << endl;
    cin >> r1;
    
    cout << "r1 is: " << r1 << endl;
    
    cout << "Enter another fraction: " << endl;
    cin >> r2;
    
    cout << "r2 is: " << r2 << endl;
    
    sum = r1 + r2;
    difference = r1 - r2;
    product = r1 * r2;
    quotient = r1 / r2;
    
    //operations
    cout << "The sum of the fractions is: " << sum << endl;
    cout << "The difference of the fractions is: " << difference << endl;
    cout << "The product of the fractions is: " << product << endl;
    cout << "The quotient of the fractions is: " << quotient << endl;
    
    //comparisons
    comparison = r1 > r2;
    if (comparison == true)
        cout << r1 << " > " << r2 << endl;
    //else
        //cout << r1 << " !> " << r2 << endl;
    
    comparison = r1 < r2;
    if (comparison == true)
        cout << r1 << " < " << r2 << endl;
    //else
       //cout << r1 << " !< " << r2 << endl;
    
    comparison = r1 >= r2;
    if (comparison == true)
        cout << r1 << " >= " << r2 << endl;
    //else
        //cout << r1 << " !>= " << r2 << endl;

    comparison = r1 <= r2;
    if (comparison == true)
        cout << r1 << " <= " << r2 << endl;
    //else
        //cout << r1 << " <= " << r2 << endl;
    
    comparison = r1 == r2;
    if (comparison == true)
        cout << r1 << " = " << r2 << endl;
    //else
        //cout << r1 << " != " << r2 << endl;

    return 0;
}

/*
//default constructor that sets fraction to 0/1
Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}
*/

//A default constructor that sets an object Rational numerator to an int wholeNumber given by the username and denominator to 1.
//Parameters: takes an int wholeNumber that will be set as the numerator of a new object Rational.
//Returns: a Rational set to wholeNumber/1.
Rational::Rational(int wholeNumber)
{
    numerator = wholeNumber;
    denominator = 1;
}

//A constructor that can be used to set the member variables of an object Rational to any legitimate values for the numerator and denominator, respectively, after normalization (function normalize is called to simplify it)/
//Parameters: initNumerator and initDenominator, integers that are going to define a new Rational.
//Returns: a Rational with the new numerator and denominator.
Rational::Rational(int initNumerator, int initDenominator)
{
    normalize(initNumerator, initDenominator);
    
    numerator = initNumerator;
    denominator = initDenominator;
}

//A mutator function of the class Rational that changes the called Rational's numerator to newValue and returns nothing.
//Parameters: newValue, which is an int passed in by value, to be set as the new numerator
//Returns: nothing.
void Rational::setNumerator(int newValue)
{
    numerator = newValue;
}

//A mutator function of the class Rational that changes the called Rational's denominator to newValue and returns nothing.
//Parameters: newValue, which is an int passed in by value, to be set as the new denominator
//Returns: nothing
void Rational::setDenominator(int newValue)
{
    denominator = newValue;
}

//An accessor function of the class Rational that simply returns the called Rational's current numerator.
//Parameters: none
//Returns: current numerator of the Rational object
int Rational::getNumerator(void)const
{
    return numerator;
}

//An accessor function of the class Rational that simply returns the called Rational's current denominator.
//Parameters: none
//Returns: current denominator of the Rational object
int Rational::getDenominator(void)const
{
    return denominator;
}

/*
void Rational::simplifyFraction(Rational fraction)
{
    int numerator, denominator, gcd;
    
    numerator = fraction.getNumerator();
    denominator = fraction.getDenominator();
    
    normalize(numerator, denominator);
    
    fraction.setNumerator(numerator);
    fraction.setDenominator(denominator);
}
*/

//This function normalizes a fraction in two parts. First it calculates the greatest common divisor (gcd) of the numerator and the denominator by calling the calculateGCD function. If the numerator is not equal to 0, it simplifies the numerator and the denominator by the found gcd. Then, if the denominator of the fraction is negative, it multiplies the fraction by -1 so that the denominator is positive.
//Parameters: &a and &b are the numerator and denominator, respectively, of a fraction, and are passed in by reference in order to change their values at the address.
//Returns: Nothing.
void Rational::normalize(int &a, int &b)
{
    int gcd = calculateGCD(a, b);

    if (a != 0)
    {
        a = a / gcd;
        b = b / gcd;
    }
    
    if (b < 0)
    {
        b = b * (-1);
        a = a * (-1);
    }
    
    numerator = a;
    denominator = b;
}

//This function calculates the least common divisor (LCD) between two denominators through calling calculateGCD, which returns the greatest common divisor (GCD) that will be used in the calculation for the LCD.
//Parameters: two denominators, denominatorA and denominatorB of two different fractions.
//Returns: newDenominator, which is the least common divisor between the two denominators that were passed in.
int Rational::calculateLCD(int denominatorA, int denominatorB)
{
    int newDenominator;
    
    newDenominator = denominatorA * denominatorB / calculateGCD(denominatorA, denominatorB);
    
    return newDenominator;
}

//Calculates the greatest common divisor (GCD) through finding the remainder when b divides a and passing it into the function along with a again recursively, until a is equal to 0.
//Parameters: passes in two integers, a and b.
//Returns: the greatest common divisor (GCD) between a and b.
int Rational::calculateGCD(int a, int b)
{
    if (a == 0)
        return b;
    return Rational::calculateGCD(b % a, a);
}

//Overloads the operator << to output a fraction to the screen. Uses accessor functions to get the numerator and denominator of a fraction and prints it out with a slash in between them.
//Parameters: &out, which is modified to print out the fraction &frac to the screen. &frac is passed in with const in order to make sure it does not get modified in the process.
//Returns: the output stream back to the main program.
ostream& operator <<(ostream &out, const Rational &frac)
{
    out << frac.numerator;
    out << "/";
    out << frac.denominator;

    return out;
}

//Overloads the operator >> to read input from user when the program asks them to define a fraction. It reads in the numerator, the slash, and the denominator all separately, and passes in the numerator and denominator into the constructor for a new object Rational.
//Parameters: &in, which reads in the input given by the user, and &fraction, which is the address of a new fraction that will be defined by the input.
//Returns: the input stream back to the main program.
istream& operator>>(istream &in, Rational &fraction)
{
    char slash;
    int numerator, denominator;
    
    in >> fraction.numerator;
    in >> slash;
    if (slash != '/')
    {
        cout << "Wrong format" << endl;
        exit(1);
    }
    in >> fraction.denominator;
    //fraction = Rational(numerator, denominator);

    return in;
}

//Overloads the operator == to check if two fractions are equal. Checks if for fractions a/b and c/d, a/d = c/b.
//Parameters: two Rational objects, &fractionA and &fractionB, which are passed in with const to make sure they're not modified by the function
//Returns: the bool 1 if the fractions passed in are equal and 0 if they are not.
bool operator==(const Rational &fractionA, const Rational &fractionB)
{
    //int denominatorA, denominatorB;
    //int numeratorA, numeratorB;
    
    //denominatorA = fractionA.getDenominator();
    //denominatorB = fractionB.getDenominator();
    //numeratorA = fractionA.getNumerator();
    //numeratorB = fractionB.getNumerator();
    
    if ((fractionA.numerator * fractionB.denominator) == (fractionB.numerator * fractionA.denominator))
    {
        return 1;
    } else
    {
        return 0;
    }
}

//Overloads the operator <= to check if the first fraction is less than or equal to the second frections. Checks if for fractions a/b and c/d, a/d <= c/b.
//Parameters: two Rational objects, &fractionA and &fractionB, which are passed in with const to make sure they're not modified by the function
//Returns: the bool 1 if the fraction passed in on the left is less than or equal to the fraction passed in on the left and 0 if not.
bool operator<=(const Rational &fractionA, const Rational &fractionB)
{
    //int denominatorA, denominatorB;
    //int numeratorA, numeratorB;
    
    //denominatorA = fractionA.getDenominator();
    //denominatorB = fractionB.getDenominator();
    //numeratorA = fractionA.getNumerator();
    //numeratorB = fractionB.getNumerator();
    
    if ((fractionA.numerator * fractionB.denominator) <= (fractionB.numerator * fractionA.denominator))
    {
        return 1;
    } else
    {
        return 0;
    }
}

//Overloads the operator >= to check if the first fraction is greater than or equal to the second frections. Checks if for fractions a/b and c/d, a/d >= c/b.
//Parameters: two Rational objects, &fractionA and &fractionB, which are passed in with const to make sure they're not modified by the function
//Returns: the bool 1 if the fraction passed in on the left is greater than or equal to the fraction passed in on the left and 0 if not.
bool operator>=(const Rational &fractionA, const Rational &fractionB)
{
    //int denominatorA, denominatorB;
    //int numeratorA, numeratorB;
    
    //denominatorA = fractionA.getDenominator();
    //denominatorB = fractionB.getDenominator();
    //numeratorA = fractionA.getNumerator();
    //numeratorB = fractionB.getNumerator();
    
    if ((fractionA.numerator * fractionB.denominator) >= (fractionB.numerator * fractionA.denominator))
    {
        return 1;
    } else
    {
        return 0;
    }
}

//Overloads the operator < to check if the first fraction is less than the second frections. Checks if for fractions a/b and c/d, a/d < c/b.
//Parameters: two Rational objects, &fractionA and &fractionB, which are passed in with const to make sure they're not modified by the function
//Returns: the bool 1 if the fraction passed in on the left is less than the fraction passed in on the left and 0 if not.
bool operator<(const Rational &fractionA, const Rational &fractionB)
{
    //int denominatorA, denominatorB;
    //int numeratorA, numeratorB;
    
    //denominatorA = fractionA.getDenominator();
    //denominatorB = fractionB.getDenominator();
    
    //numeratorA = fractionA.getNumerator();
    //numeratorB = fractionB.getNumerator();
    
    if ((fractionA.numerator * fractionB.denominator) < (fractionB.numerator * fractionA.denominator))
    {
        return 1;
    } else
    {
        return 0;
    }
}

//Overloads the operator > to check if the first fraction is greater than the second frections. Checks if for fractions a/b and c/d, a/d > c/b.
//Parameters: two Rational objects, &fractionA and &fractionB, which are passed in with const to make sure they're not modified by the function
//Returns: the bool 1 if the fraction passed in on the greater is less than the fraction passed in on the left and 0 if not.
bool operator>(const Rational &fractionA, const Rational &fractionB)
{
    //int denominatorA, denominatorB;
    //int numeratorA, numeratorB;
    
    //denominatorA = fractionA.getDenominator();
    //denominatorB = fractionB.getDenominator();
    //numeratorA = fractionA.getNumerator();
    //numeratorB = fractionB.getNumerator();
    
    if ((fractionA.numerator * fractionB.denominator) > (fractionB.numerator * fractionA.denominator))
    {
        return 1;
    } else
    {
        return 0;
    }
}

//Overloads the operator + to add two fractions together after finding a common denominator.
//Parameters: two Rational objects, &fractionA and &fractionB, which are passed in with const to make sure they're not modified by the function
//Returns: a Rational object called result which holds the value of the sum of the two fractions that were passed in.
const Rational operator+(const Rational &fractionA, const Rational &fractionB)
{
    Rational result;
    int lcd;
    //int denominatorA, denominatorB;
    int numeratorA, numeratorB;
    int multiplierA, multiplierB;
    
    //denominatorA = fractionA.getDenominator();
    //denominatorB = fractionB.getDenominator();
    //numeratorA = fractionA.getNumerator();
    //numeratorB = fractionB.getNumerator();
    
    lcd = result.calculateLCD(fractionA.denominator, fractionB.denominator);
    
    multiplierA = lcd / fractionA.denominator;
    numeratorA = multiplierA * fractionA.numerator;
    
    multiplierB = lcd / fractionB.denominator;
    numeratorB = multiplierB * fractionB.numerator;
    
    result = Rational(numeratorA + numeratorB, lcd);

    return result;
}


//Overloads the operator - to subtract two fractions together after finding a common denominator.
//Parameters: two Rational objects, &fractionA and &fractionB, which are passed in with const to make sure they're not modified by the function
//Returns: a Rational object called result which holds the value of the difference of the two fractions that were passed in.
const Rational operator-(const Rational &fractionA, const Rational &fractionB)
{
    Rational result;
    int lcd;
    //int denominatorA, denominatorB;
    int numeratorA, numeratorB;
    int multiplierA, multiplierB;
    
    //denominatorA = fractionA.getDenominator();
    //denominatorB = fractionB.getDenominator();
    //numeratorA = fractionA.getNumerator();
    //numeratorB = fractionB.getNumerator();
    
    lcd = result.calculateLCD(fractionA.denominator, fractionB.denominator);
    
    multiplierA = lcd / fractionA.denominator;
    numeratorA = multiplierA * fractionA.numerator;
    
    multiplierB = lcd / fractionB.denominator;
    numeratorB = multiplierB * fractionB.numerator;
    
    result = Rational(numeratorA - numeratorB, lcd);

    return result;
}

//Overloads the operator * to add multiply two fractions.
//Parameters: two Rational objects, &fractionA and &fractionB, which are passed in with const to make sure they're not modified by the function
//Returns: a Rational object called result which holds the value of the product of the two fractions that were passed in.
const Rational operator*(const Rational &fractionA, const Rational &fractionB)
{
    Rational result;
    //int denominatorA, denominatorB;
    //int numeratorA, numeratorB;
    
    //denominatorA = fractionA.getDenominator();
    //denominatorB = fractionB.getDenominator();
    //numeratorA = fractionA.getNumerator();
    //numeratorB = fractionB.getNumerator();
    
    result = Rational(fractionA.numerator * fractionB.numerator, fractionA.denominator * fractionB.denominator);

    return result;
}

//Overloads the operator / to divide two fractions.
//Parameters: two Rational objects, &fractionA and &fractionB, which are passed in with const to make sure they're not modified by the function
//Returns: a Rational object called result which holds the value of the quotient of the two fractions that were passed in.
const Rational operator/(const Rational &fractionA, const Rational &fractionB)
{
    Rational result;
    //int denominatorA, denominatorB;
    //int numeratorA, numeratorB;
    
    //denominatorA = fractionA.getDenominator();
    //denominatorB = fractionB.getDenominator();
    //numeratorA = fractionA.getNumerator();
    //numeratorB = fractionB.getNumerator();
    
    result = Rational(fractionA.numerator * fractionB.denominator, fractionA.denominator * fractionB.numerator);

    return result;
}

/*
//displays Rational number (numerator and denominator info set in class Rational) as fraction
void Rational::display(void)
{
    cout << numerator << "/" << denominator;
}
*/

/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein.
All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.
Date: 09/30/2023
Name: Wendy Carvalho
*/
