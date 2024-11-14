//  C3_Lecture18, template function

#include <iostream>
using namespace std;

void mySwap(int &num1, int &num2);
void mySwap(double &num1, double &num2);

template <class T>//tempalte prefix,
//template <typename T>
void templateSwap (T &num1, T &num2);

int main(int argc, char *argv[])
{
    int num1 = 35, num2 = -53;
    templateSwap(num1, num2);
    
    cout << "num1: " << num1 << " num2: " << num2 << endl;
    
    double d1 = 1.1, d2 = 2.2;
    templateSwap(d1, d2);
    cout << "d1: " << d1 << ", d2: " << d2 << endl;
    
    // Exercise 2
    /*
    typedef int* ArrayPointer;
    
    ArrayPointer a, b, c;
    a = new int[3];
    b = new int[3];
    int i;
    for (i = 0; i < 3; i++)
    {
        a[i] = i;
        b[i] = i + 100;
    }
    c = a;
    templateSwap(a, b);
    */
    
    //Exercise 3:
    /*
    int arr1[3];
    int arr2[3];
    
    templateSwap(arr1, arr2);
     */
    return 0;
}

template <class T>//prefix
void templateSwap (T &num1, T &num2) {
    T temp = num2;
    num2 = num1;
    num1 = temp;
}

void mySwap(int &num1, int &num2)
{
    int holder = num1;
    num1 = num2;
    num2 = holder;
}

void mySwap(double &num1, double &num2)
{
    double holder = num1;
    num1 = num2;
    num2 = holder;
}
