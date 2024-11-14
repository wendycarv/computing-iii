//
//  lab5
//
/*

 • an overloaded version of the unary operator ! that implements the “complex conjugate” operation as described in the Wikipedia entry linked above.

 */
#include <iostream>
using namespace std;

class ComplexNumber{
public:
    //default constructor
    ComplexNumber(): a(0), b(0){};
    //value constructor
    ComplexNumber(double real, double imaginary): a(real), b(imaginary){};
    
    //mutators
    void setComplexNumber(double real, double imaginary){
        a = real;
        b = imaginary;
    }
    void setReal(double real){
        a = real;
    }
    void setImaginary(double imaginary){
        b = imaginary;
    }
    //accessors
    double getReal(void) const{
        return a;
    }
    double getImaginary(void) const{
        return b;
    }
    
    friend ostream& operator<<(ostream& out, const ComplexNumber num);
    
    friend const ComplexNumber operator+(const ComplexNumber &num1, const ComplexNumber &num2);

    friend const ComplexNumber operator-(const ComplexNumber &num1, const ComplexNumber &num2);

    friend const ComplexNumber operator*(const ComplexNumber &num1, const ComplexNumber &num2);

    friend const ComplexNumber operator/(const ComplexNumber &num1, const ComplexNumber &num2);
    
    friend const ComplexNumber operator!(const ComplexNumber &num1, const ComplexNumber &num2);

    
private:
    double a; //real
    double b; //imaginary
};

ostream& operator<<(ostream& out, const ComplexNumber num);

const ComplexNumber operator+(const ComplexNumber &num1, const ComplexNumber &num2);

const ComplexNumber operator-(const ComplexNumber &num1, const ComplexNumber &num2);

const ComplexNumber operator*(const ComplexNumber &num1, const ComplexNumber &num2);

const ComplexNumber operator/(const ComplexNumber &num1, const ComplexNumber &num2);

const ComplexNumber operator!(const ComplexNumber &num1, const ComplexNumber &num2);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

ostream& operator<<(ostream& out, const ComplexNumber num)
{
    out << num.a;
    out << " + ";
    out << num.b;
    out << "i";
    out << endl;
    
    return out;
}

const ComplexNumber operator+(const ComplexNumber &num1, const ComplexNumber &num2)
{
    ComplexNumber resultNum;
    
    resultNum.a = num1.a + num2.a;
    resultNum.b = num1.b + num1.b;
    
    return resultNum;
}

const ComplexNumber operator-(const ComplexNumber &num1, const ComplexNumber &num2)
{
    ComplexNumber resultNum;
    
    resultNum.a = num1.a - num2.a;
    resultNum.b = num1.b - num1.b;
    
    return resultNum;
}

const ComplexNumber operator*(const ComplexNumber &num1, const ComplexNumber &num2)
{
    ComplexNumber resultNum;
    
    resultNum.a = num1.a * num2.a;
    resultNum.b = num1.b * num1.b;
    
    return resultNum;
}

const ComplexNumber operator/(const ComplexNumber &num1, const ComplexNumber &num2)
{
    ComplexNumber resultNum;
    
    resultNum.a = ((num1.a * num2.a) + (num1.b * num2.b))/((num2.a * num2.a)+(num2.b * num2.b));
    resultNum.b = ((num1.b * num2.a) - (num1.a * num2.b))/((num2.a * num2.a)+(num2.b * num2.b));
    
    return resultNum;
}

const ComplexNumber operator!(const ComplexNumber &num1, const ComplexNumber &num2)
{
    int z = num1.a - num1.b;
}
