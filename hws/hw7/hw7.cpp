#include <iostream>
using namespace std;

class Person
{
public:
Person(): name("none"){};
    Person(string theName)
    {
        name = theName;
    }

    Person(const Person& theObject)
    {
        name = theObject.name;
    }

    string getName( ) const
    {
        return name;
    }

    Person& operator=(const Person& rtSide)
    {
        if (this == &rtSide)
            return *this;
        
        name = rtSide.name;

        return *this;
    }
    friend istream& operator >>(istream& inStream, Person& personObject);

    friend ostream& operator <<(ostream& outStream, const Person&
    pObject);

private:
    string name;
};

istream& operator >>(istream& inStream, Person& personObject);
ostream& operator <<(ostream& outStream, const Person&
pObject);

class Vehicle{
public:
    Vehicle();

private:
    string manufacturer;
    int cylindersInEngine;
    Person owner;
};

class Truck : public Vehicle{
public:
private:
double loadCapacityInTons;
int towingCapacityInPounds;
};

int main()
{
    Person p1, p2;
    cout << "Testing default constructor: the person is: " << p1 << endl;

    cout << "Testing constructor(string): I am: " << p1; endl;
    
    cout << "Testing copy constructor: another me is: " << p1 << endl;

    cout << "Testing >> overloading: ";

    cin >> "Enter your name: "

    cout << "You're: " << p2;
    
    return 0;
}

istream& operator >>(istream& inStream, Person& personObject)
{
    string inputName;
    inStream >> inputName;
    personObject.name = inputName;
    return inStream;
}

ostream& operator <<(ostream& outStream, const Person&
pObject)
{
    outStream << pObject.name << endl;
    return outStream;
}