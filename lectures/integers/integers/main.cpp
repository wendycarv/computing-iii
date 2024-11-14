#include <iostream>

void printInt(int number);
//void swapInt(int& num1, int& num2);
void mySwap(double, double);
void mySwap(int, int);
            
int main(int argc, const char * argv[])
{
    int int1 = 1;
    int int2 = 2;
    
    double d1 = 1.4;
    double d2 = 5.6;
    
    //swapInt(num, num2);
    mySwap(int1, int2);
    mySwap(d1, d2);
    
    cout << "After calling swapInt(), ";
    return 0;
}

/* void swapInt(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
*/

void mySwap(int& input1, int& input2)
{
    int temp = input1;
    input1 = input2;
    input2 = temp;
}

void mySwap(double& input1, double& input2)
{
    double temp = input1;
    input1 = input2;
    input2 = temp;
}

void getInt(int &num)
{
    cin >> num;
}

void printInt(int number)
{
    
}
