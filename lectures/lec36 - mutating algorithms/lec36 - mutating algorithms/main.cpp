#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEven(int number);
void printOneNum(int number);
void doubleValue(int &number);

template <class T>
void printT(const T &item);

//trueÂ if the first argument appears before the second
//true if the first > second
//falseÂ otherwise
bool myCompare(int num1, int num2) {
    return num1 > num2;
}

int main(int argc, const char * argv[])
{
    
    vector<int> vec;
    vec.push_back(17);
    vec.push_back(10);
    vec.push_back(14);
    vec.push_back(13);
    vec.push_back(18);
    vec.push_back(15);
    
    vector<int>::iterator b = vec.begin(), e = vec.end();
    
    //count how many 13
    cout << "the number of 13 is: " << count(b, e, 13) << endl;

    //count the number of even values
    cout << "The number of even values is: " <<
        count_if(b, e, isEven) << endl;
  
    //print all elements in vector
    for_each(b, e, printOneNum);
    cout << endl;

    //double each value and print the vector
    for_each(b, e, doubleValue);
    cout << "After double: " << endl;
    for_each(b, e, printOneNum);
    cout << endl;
    
    //TODO: reverse the vector
    reverse(b, e);
    cout << "After reverse: " << endl;
    for_each(b, e, printOneNum);
    cout << endl;
    
    //TODO: sort in ascending order
    //sort(b, e);
    
    //TODO: sort in customized order
    
    sort(b, e, myCompare);
    cout << "After myCompre: " << endl;
    for_each(b, e, printOneNum);
    cout << endl;
    
    
    string s1[] = {"Lowell", "Boston", "Andover", "Chelmsford"};
    vector<string> s2(4);
   //make sure s2 has enough space to hold s1
    copy(s1, s1+4, s2.begin());
    for_each(b, e, printT);
    
    return 0;
}
//return true if the condition test is OK
bool isEven(int number) {
    return number % 2 == 0;
}


void printOneNum(int number) {
    cout << number << " ";
}

void doubleValue(int &number) {
    number *= 2;
    //cout << "new value: " << number << endl;
}
