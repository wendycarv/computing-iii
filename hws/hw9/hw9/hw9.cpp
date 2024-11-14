/*
Author: Wendy Carvalho
Date: 11/26/2023
Purpose: This program creates a class object called PFArrayD and uses the user's input to create its capacity and store elements. It also creates a class called OutOfRange for exception handling regarding the PFArrayD object, like accessing an index out of range. This program demonstrates the functionality of trys, throws, and catches using this OutOfRange class.
Sources of Help: Lecture notes
Time Spent: 1h30min 
*/

#include <iostream>
#include <string>

using namespace std;

void testPFArrayD(void);
void testException(void);

class OutOfRange{
public:
    //A constructor that sets parameters iNum and iString to the index of the error and a display message, respectively.
    explicit OutOfRange(int iNum, string iString): num(iNum), message(iString){};
    
    //Function that has no parameters and returns the index stored in private mbr num
    int index(){
        return num;
    }
    
    //Function that reads out error message stored in private mbr variable called message, takes no parameters and returns nothing.
    void err(){
        cout << message << endl;
    }
private:
    int num;
    string message;
};

//Objects of this class are partially filled arrays of doubles.
class PFArrayD
{
public:
    friend class OutOfRange;
    //Initializes with a capacity of 50.
    PFArrayD(){
        capacity = 50;
        a = new double[capacity];
        used = 0;
    }
    
    //Initializes class object with value passed in parameter, capacityValue
    PFArrayD(int capacityValue){
        capacity = capacityValue;
        a = new double[capacity];
        used = 0;
    }
    
    //Copy constructor using PFArrayD object passed in parameter
    PFArrayD(const PFArrayD& pfaObject){
        a = new double[pfaObject.capacity];
        capacity = pfaObject.capacity;
        
        for(int i = 0; i < pfaObject.used; i++)
        {
            a[i] = pfaObject.a[i];
            used++;
        }
    }
    
    //Function adds double element passed in parameter to array
    //Precondition: The array is not full.
    //Postcondition: The element has been added.
    void addElement(double element){
        if (used != capacity)
        {
            a[used] = element;
            used++;
        }
        else
        {
            OutOfRange insertion(used+1, " capacity of PFArrayD has been reached, element does not fit");
            cout << "Error at index " << insertion.index();
            insertion.err();
        }
    }
    
    //Returns true if the array is full, false otherwise.
    bool full( ) const { return (capacity == used); }
    
    //returns capacity of array
    int getCapacity( ) const{ return capacity; }
    
    //returns number of variables currently stored in array
    int getNumberUsed( ) const { return used; }
    
    //Empties the array.
    void emptyArray( ){
        //for (int i = used - 1; i != 0; i--)
            //a[i] = NULL;
        used = 0;
    }
    
    //Read and change access to elements 0 through numberUsed - 1.
    double& operator[](int index){
        if (index <= used)
            return a[index];
        else{
            OutOfRange obj(index, " index value given is out of range");
            cout << "Error at index " << obj.index();
            obj.err();
            return a[capacity];
        }
    }
    
    //Copy assignment operator; deletes original array and replaces it with PFArrayD object passed in thru parameter
    PFArrayD& operator =(const PFArrayD& rightSide){
        if (this == &rightSide)
            return *this;
        //step one: delete lefthand side
        delete []a;
        //step two: copy over righthand side
        a = new double[rightSide.capacity];
        capacity = rightSide.capacity;
        
        for (int i = 0; i < rightSide.used - 1; i++)
        {
            a[i] = rightSide.a[i];
            used++;
        }
            
        return *this;
    }
    
    ~PFArrayD(){
        delete []a;
        //used = 0;
    };
private:
    double *a; //for an array of doubles.
    int capacity; //for the size of the array.
    int used; //for the number of array positions currently in use.
    
};


int main(int argc, char *argv[])
{
     cout << "This program tests the class PFArrayD.\n\n";
     
     char ans;
    /*
     do
     {
         testPFArrayD();
         cout << "Test again? (y/n) ";
         cin >> ans;
     }while ((ans == 'y') || (ans == 'Y'));
     */
    cout << "Testing now the class OutOfRange.\n\n";
    do
    {
        testException();
        cout << "Test again (y/n) ";
        cin >> ans;
    }while ((ans == 'y') || (ans == 'Y'));
    return 0;
}

//creates and tests PFArrayD object created per user's inputs, takes no parameters and returns nothing
void testPFArrayD(){
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);
    
    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";
    
    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full( )))
    {
        temp.addElement(next);
        cin >> next;
    }
    
    cout << "You entered the following " << temp.getNumberUsed( ) << " numbers:\n";
    int index;
    int count = temp.getNumberUsed( );
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value.)\n";
}

//has user test errors involved with PFArrayD objects, like accessing an index out of range, takes no parameters and returns nothing
void testException(){
    int cap;
    int index;
    
    do{
        cout << "Enter a capacity for another super array: ";
        
        try{
            cin >> cap;
            if (cap <= 0){
                throw OutOfRange(cap, "Capacity cannot be less than or equal to zero.\n");
            }
            break;
        } catch (OutOfRange &ex) {
            cout << "Caught OutOfRange: ";
            ex.err();
        }

    } while (true);

    PFArrayD temp(cap);
    
    cout << "Enter up to " << cap << " nonnegative numbers (I dare you to try going over this amount). \n";
    cout << "Then, place a negative number at the end.\n";
    
    double next;
    
    do{
        try{
            cin >> next;
            if ((temp.getNumberUsed() == temp.getCapacity()) && next >= 0){
                throw OutOfRange(next, "Array is full, you can only enter a negative number now.\n");
            } else if(next < 0){
                break;
            } else {
                temp.addElement(next);
            }
        } catch (OutOfRange &ex){
            cout << "Caught OutOfRange: ";
            ex.err();
        }
    } while (next >= 0);
    
    cout << "\nLet's try accessing some elements of the array.\n";
    
    do{
        cout << "Enter an index.\n";
        try{
            cin >> index;
            if (index >= temp.getCapacity()){
                throw OutOfRange(index, "Index is a number beyond capacity of the array.\n");
            } else if (index < 0) {
                throw OutOfRange(index, "Index cannot be a negative number.\n");
            } else {
                cout << "Array at index " << index << "is: " << temp[index] << endl;
                break;
            }
        } catch (OutOfRange &ex){
            cout << "Caught OutOfRange: ";
            ex.err();
        }
    } while (true);
}


/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein.
All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.
Date: 11/26/2023
Name: Wendy Carvalho
*/
