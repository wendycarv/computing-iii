/*
Author: Wendy Carvalho
Date: 10/16/2023
Purpose: This program creates a dynamic string array that acts as a vector in the sense that it has member functions that allows you to access and modify a particular index of the array.
Sources of Help: Lecture notes
Time Spent: 2 hours
*/

#include <iostream>
using namespace std;

class DynamicStringArray{
public:
    //A default constructor that sets the dynamic array to nullptr and sets size to 0.
    DynamicStringArray(){
        size = 0;
        dynamicArray = nullptr;
    }
    DynamicStringArray(string iString);
    DynamicStringArray(const DynamicStringArray &org);
    ~DynamicStringArray();
    
    //Function that returns size, takes no parameters
    int getSize(){
        return size;
    }
    
    DynamicStringArray& operator=(const DynamicStringArray &obj);
    friend ostream& operator<<(ostream &out, const DynamicStringArray &obj);

    void addEntry(string iString);
    bool deleteEntry(string iString);
    string getEntry(int value);
    
private:
    int size; //private member variable that holds the number of entries in the array
    string *dynamicArray; //private member variable that references a dynamic array of type string

};

//A default constructor that sets the dynamic array to a string passed in through the parameters and sets size to 0.
//Parameters: string iString, which is the string to be set as the dynamicArray's contents.
//Returns: a new DynamicStringArray object.
DynamicStringArray::DynamicStringArray(string iString)
{
    dynamicArray = new string[1];
    dynamicArray[0] = iString;
    size = 1;
}

// A copy constructor that makes a copy of the input object’s dynamic array.
//Parameters: the address to a DynamicStringArray object, &obj, which has const before it so that it is not modified in the function. This is the object to get copied over into the calling object.
//Returns: a new DynamicStringArray object with the same values as the object that was passed in.
DynamicStringArray::DynamicStringArray(const DynamicStringArray &org)
{
    dynamicArray = new string[org.size];
    int i;
    
    for(i = 0; i <= org.size; i++)
    {
        dynamicArray[i] = org.dynamicArray[i];
    }
    size = org.size;
}

//Destructor function that deletes the data in the DynamicStringArray objects created during the program execution.
//Parameters: none
//Returns: nothing
DynamicStringArray::~DynamicStringArray()
{
    delete []dynamicArray;
}

//Overloaded copy assignment operator that allows the dynamic array to be properly copied to the target object. In this function, the calling object's original content gets deleted and replaced with the DynamicStringArray object that is passed in as a parameter.
//Parameters: the address to a DynamicStringArray object, &obj, which has const before it so that it is not modified in the function. This is the object to get copied over into the calling object.
//Returns: the calling DynamicStringArray object that has now been modified to have equal values as the object in the parameter
DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray &obj)
{
    //step0: if lefthand operand is the same as righthand operand, return immediately
    if (this == &obj)
        return *this;
    
    int i;
    //step1: delete calling object
    delete[]dynamicArray;
    dynamicArray = new string[obj.size];
    
    //step2: copy over righthand object
    for (i = 0; i < obj.size; i++)
    {
        this->dynamicArray[i] = obj.dynamicArray[i];
    }
    this->size = obj.size;
    
    //step3: returning the calling object with this pointer
    return *this;
}

ostream& operator<<(ostream &out, const DynamicStringArray &obj);

//This function creates a new dynamic array one element larger than dynamicArray, copies all elements from dynamicArray into the new array, adds the new string onto the end of the new array, increments size, deletes the old dynamicArray, and then sets dynamicArray to the new array.
//Parameters: string iString, which is the string to be added to the end of the dynamicArray.
//Returns: nothing
void DynamicStringArray::addEntry(string iString)
{
    int i;
    string *newDynamicArray = new string[size + 1];
    //DynamicStringArray tmp;
    for (i = 0; i < size; i++)
    {
        newDynamicArray[i] = dynamicArray[i];
    }
    newDynamicArray[i] = iString;
    size++;
    //delete old dynamicArray
    delete[] dynamicArray;
    dynamicArray = newDynamicArray;
}

//This function searches dynamicArray for a string. If it's not found, it returns false. If it's found, it creates a new dynamic array one element smaller than dynamicArray and copies all elements except the input string into the new array, deletes dynamicArray, decrements size, and returns true.
//Parameters: string iString, which is the string that is looked for inside the DynamicStringArray object.
//Returns: true if the string iString is found in the DynamicStringArray object and false if not.
bool DynamicStringArray::deleteEntry(string iString)
{
    int i, index;
    
    for (i = 0; i < size; )
    {
        if (dynamicArray[i] != iString)
        {
            i++;
        }
        else
        {
            int j;
            index = i;
            string *newArray = new string[size - 1];
            for (j = 0, i = 0; i < size; i++)
            {
                if (i != index)
                    newArray[j++] = dynamicArray[i];
            }
            delete[] dynamicArray;
            dynamicArray = newArray;
            size--;
            return true;
        }
    }
    return false;
}


//This function takes an integer as input and uses it as the index value for a specific string in the DynamicStringArray object.
//Parameters: int value, which is used as the index value for the array.
//Returns: a pointer that references the string at that index in dynamicArray. It returns nullptr if the index is out of dynamicArray’s bounds.
string DynamicStringArray::getEntry(int value)
{
    string *reference = nullptr;
    
    if (value <= size - 1)
        reference = &dynamicArray[value];
    
    return *reference;
}

int main(int argc, const char * argv[])
{
    //default constructor
    DynamicStringArray obj1;
    cout << obj1 << endl;
    
    DynamicStringArray obj3("strawberries");
    cout << "Object3: " << obj3 << endl;

    DynamicStringArray obj2("grapes");
    obj2.addEntry("cheese");
    obj2.addEntry("olives");
    cout << "Object2 after adding three items: " << obj2 << endl;
    
    obj2.deleteEntry("cheese");
    cout << "Object2 after deleting second item: "<< obj2 << endl;

    cout << "Object2 at index 0: " << obj2.getEntry(0) << endl;
    DynamicStringArray obj4 = obj3;
    cout << "Object4 (initialized by copying Object3): " << obj4 << endl;

    obj2 = obj3;
    cout << "Object2 after operator= used to copy object3: " << obj2 << endl;

    return 0;
}

//Overloads the operator << to output a DynamicStringArray object to the screen. As a friend function, it can access the object size without the use of accessor functions.
//Parameters: &out, which is modified to print out the DynamicStringArray &obj to the screen. &obj is passed in with const in order to make sure it does not get modified in the process.
//Returns: the output stream back to the main program.
ostream& operator<<(ostream &out, const DynamicStringArray &obj)
{
    int i = 0;
    
    if (obj.size == 0)
    {
        out << "Array is empty" << endl;
        return out;
    }
    
    while (i < obj.size)
    {
        out << obj.dynamicArray[i] << " ";
        i++;
    }
    out << endl;
    return out;
}

/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein.
All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.
Date: 10/16/2023
Name: Wendy Carvalho
*/
