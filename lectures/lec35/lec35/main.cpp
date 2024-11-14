//
//  non-mutating
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyContainer{
public:
private:
    
};

void print(int oneNum);
bool isEven(int oneNum);
void printOneNum(int number);
void doubleValue(int &oneNum);

bool myCompare(int num1, int num2){
    return num1 > num2;
}

template <class T>
void printT (const T& oneItem);

template <class ForwardIterator, class T>
void myReplace(ForwardIterator b, ForwardIterator e, const T &oldValue, const T &newValue);

int main(int argc, const char * argv[])
{
    vector<int> vec;
    vec.push_back(17);
    vec.push_back(10);
    vec.push_back(13);
    vec.push_back(13);
    vec.push_back(18);
    vec.push_back(15);
    
    //print all elements in vector
    vector<int>::iterator b, e;
    b = vec.begin();
    e = vec.end();
    for_each(b, e, print);
    cout << endl;
    
    //count how many 13
    cout << "number of 13 is: " << count(b, e, 13) << endl;
    
    //count the number of even values
    cout << "number of even values is: " << count_if(b, e, isEven) << endl;

    //double each value and print the vector
    cout << "After double value: " << endl;
    for_each(b, e, doubleValue);
    //for_each(b, e, print);
    for_each(b, e, printT<int>);
    
    cout << endl;
    
    //reverse the vector
    reverse(b, e);
    cout << "After reverse: " << endl;
    for_each(b,e, printOneNum);
    cout << endl;
    
    //replace all instances of 13 and print the vector
    cout << "After replacing 13 with 0: " << endl;
    myReplace(b, e, 13, 0);
    for_each(b, e, printT<int>);
    
    cout << endl;
    
    string s1[] = {"Lowell", "Boston", "Andover", "Chelmsford"};
    vector<string> s2(4);
    
    copy(s1, s1+4, s2.begin());
    
    
    //sort in ascending order
    sort(b, e);
    
    //sort in customized order
    return 0;
}

void print(int oneNum)
{
    cout << oneNum << " ";
}

bool isEven(int oneNum)
{
    return (oneNum % 2 == 0);
}

//use pass-by-reference to change oneValue
void doubleValue(int &oneNum)
{
    oneNum = oneNum * 2;
}

template <class T>
void printT (const T &oneItem)
{
    cout << oneItem << " ";
}

template <class ForwardIterator, class T>
void myReplace(ForwardIterator b, ForwardIterator e, const T &oldValue, const T &newValue)
{
    //find all instances of key in container
    //replace with newValue
    
    while (b != e)
    {
        if (*b == oldValue)
        {
            *b = newValue;
        }
        b++;
    }
}
