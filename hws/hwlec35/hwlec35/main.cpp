//
//  non-mutating
//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void print(int oneNum);
bool isEven(int oneNum);
void doubleValue(int &oneNum);

template <class T>
void printT (const T& oneItem);

template <class ForwardIterator, class T>
void myReplace(ForwardIterator b, ForwardIterator e, const T &oldValue, const T &newValue);

int main(int argc, const char * argv[])
{
    set<int> vec = {17, 10, 13, 13, 18, 15};
    
    set<int>::iterator b, e;
    b = vec.begin();
    e = vec.end();
    
    
    //replace all instances of 13 and print the vector
    cout << "After replacing 13 with 0: " << endl;
    
    replace(b, e, 13, 0);

    cout << endl;
    
    
    return 0;
}

void print(int oneNum)
{
    cout << oneNum << " ";
}

template <class T>
void printT (const T &oneItem)
{
    cout << oneItem << " ";
}


template <class InputIterator, class T>
void myReplace(InputIterator b, InputIterator e, const T &oldValue, const T &newValue)
{
    //find all instances of key in container
    //replace with newValue
    
    auto p = b;
    while (p != e)
    {
        if (*p == oldValue)
        {
            //*p = newValue;
            b.erase(p);
            b.insert(p, newValue);
        }
        p++;
    }
}


/*
 template <typename Iterator, typename ValueType>
 void myReplace(Iterator begin, Iterator end, const ValueType& oldValue, const ValueType& newValue) {
     for (auto it = begin; it != end; ++it) {
         if (*it == oldValue) {
             *it = newValue;
         }
     }
 }
 */
