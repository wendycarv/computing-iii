/*
Author: Wendy Carvalho
Date: 11/12/2023
Purpose: This program demonstrates the use of a base class (Vehicle) and a derived class (Truck), with a complimentary class called Person that is used to declare some information for both Vehicle and Truck.
Sources of Help: C++ forum, Lab 8, class notes
Time Spent: 1h30min
*/

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
    Vehicle(): manufacturer("Unknown Manufactory"), cylindersInEngine(0), owner("Unknown Owner"){};
    Vehicle(string iManufacturer, int cylinders, Person iOwner)
    {
        manufacturer = iManufacturer;
        cylindersInEngine = cylinders;
        owner = iOwner;
    }
    
    Vehicle(const Vehicle& vObject)
    {
        manufacturer = vObject.manufacturer;
        cylindersInEngine = vObject.cylindersInEngine;
        owner = vObject.owner;
    }
    
    Vehicle& operator=(const Vehicle& rtSide)
    {
        if (this == &rtSide)
            return *this;
        
        manufacturer = rtSide.manufacturer;
        cylindersInEngine = rtSide.cylindersInEngine;
        owner = rtSide.owner;
        
        return *this;
    }
    
    void output(ostream &outStream) const
    {
        outStream << *this;
    }
    friend ostream& operator<<(ostream& outStream, const Vehicle& vObject);
    
private:
    string manufacturer;
    int cylindersInEngine;
    Person owner;
};

ostream& operator<<(ostream& outStream, const Vehicle& vObject);

class Truck : public Vehicle{
public:
    Truck(): Vehicle(), loadCapacityInTons(0), towingCapacityInPounds(0){};
    Truck(string iManufactory, int iCylinders, Person iOwner, double iLoadCap, int iTowingCap): Vehicle(iManufactory, iCylinders, iOwner){
        loadCapacityInTons = iLoadCap;
        towingCapacityInPounds = iTowingCap;
    }
    
    Truck(const Truck& tObject) : Vehicle(tObject)
    {
        loadCapacityInTons = tObject.loadCapacityInTons;
        towingCapacityInPounds = tObject.towingCapacityInPounds;
    }
    
    Truck& operator=(const Truck& rtSide)
    {
        if (this == &rtSide)
            return *this;
        
        Vehicle::operator=(rtSide);
        loadCapacityInTons = rtSide.loadCapacityInTons;
        towingCapacityInPounds = rtSide.towingCapacityInPounds;
        
        return *this;
    }
    friend ostream& operator<<(ostream& outStream, const Truck& tObject);

private:
    double loadCapacityInTons;
    int towingCapacityInPounds;
};

ostream& operator<<(ostream& outStream, const Truck& tObject);

int main()
{
    cout << "//////////////////// Testing Person Class //////////////////////" << endl;
    
    Person p1;
    cout << "Testing default constructor: the person is: " << p1 << endl;
    
    Person p2("Wendy Lima");
    cout << "Testing constructor(string): I am: " << p2 << endl;
    
    Person p3(p2);
    cout << "Testing copy constructor: another me is: " << p3 << endl;
    
    Person p4;
    cout << "Testing >> overloading: Enter your name: ";
    cin >> p4;
    cout << "You're: " << p4 << endl;;
    
    p3 = p4;
    cout << "Testing = overloading: Another you is: " << p3;
    
    cout << "//////////////////// Testing Vehicle Class //////////////////////" << endl;
    Vehicle v1;
    cout << "Testing default constructor: the vehicle is: " << v1 << endl;
    
    Vehicle v2("Volkswagen", 8, p2);
    cout << "Testing constructor(args): for my car: " << v2 << endl;

    Vehicle v3(v2);
    cout << "Testing copy constructor: my second same car: " << v3 << endl;
    
    Person p5("James Smith");
    Vehicle v4("Ford", 6, p5);
    v3 = v4;
    cout << "Testing = overloading:" << endl;
    cout << "\t\tYour car is: " << v4 << endl;
    cout << "\t\tYour second car is: " << v3 << endl;
    
    cout << "//////////////////// Testing Truck Class //////////////////////" << endl;
    Truck t1;
    cout << "Testing default constructor: the truck is: " << t1 << endl;
    
    Person p6("Mike Elf");
    Truck t2("Mac", 8, p6, 250, 2000);
    cout << "Testing constructor(args): for a truck: " << t2 << endl;
    
    Truck t3(t2);
    cout << "Testing copy constructor: copied truck " << t3 << endl;

    Person p7("James Smith");
    Truck t4("Toyota", 8, p7, 200, 5000);
    t3 = t4;
    cout << "Testing = overloading: " << endl;
    cout << "\t\tHis truck is: " << t4 << endl;
    cout << "\t\tHis same truck is: " << t3 << endl;


    return 0;
}

istream& operator >>(istream& inStream, Person& personObject)
{
    string inputName;
    getline(inStream, inputName);
    personObject.name = inputName;
    return inStream;
}

ostream& operator <<(ostream& outStream, const Person& pObject)
{
    outStream << pObject.name;
    return outStream;
}

ostream& operator<<(ostream& outStream, const Vehicle& vObject)
{
    outStream << vObject.manufacturer << ", " << vObject.cylindersInEngine << " cylinders, belongs to: " << vObject.owner;
    return outStream;
}

ostream& operator<<(ostream& outStream, const Truck& tObject)
{
    tObject.Vehicle::output(outStream);
    outStream << ", load capacity: " << tObject.loadCapacityInTons << ", towing capacity: " << tObject.towingCapacityInPounds;
    
    return outStream;
}

/*
Computing III -- COMP.2010 Honor Statement

The practice of good ethical behavior is essential for maintaininggood order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein.

 All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors. I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.

 Date: 11/12/2023
 Name: Wendy Carvalho
*/
