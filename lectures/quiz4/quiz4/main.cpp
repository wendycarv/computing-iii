#include <iostream>
using namespace std;

/*
class Money
{
public:
    Money();
    Money(int theDollar, int theCents);
    Money(int theDollars);
    Money(double amount);
    //other public members
    
    int getCents(void)const;
    int getDollars(void)const;
    friend const Money operator+(const Money &amt1, const Money &amt2);
    friend ostream& operator <<(ostream &out, const Money& amt);

private:
    int dollars;
    int cents;
    //other private members
};

Money::Money()
{
    dollars = 0;
    cents = 0;
}

Money::Money(int theDollar, int theCents)
{
    dollars = theDollar;
    cents = theCents;
}

Money::Money(int theDollars)
{
    dollars = theDollars;
}


Money::Money(double amount)
{
    int totalCents = amount * 100;
    dollars = totalCents / 100;
    cents = totalCents % 100;
}
 

const Money operator+(const Money &amt1, const Money& amt2);
ostream& operator <<(ostream &out, const Money& amt);

int main(int argc, const char * argv[])
{
    Money baseAmount(120, 40); //e.g., $120.40
    Money fullAmount(20);
    Money tmp;
    
    tmp = baseAmount + 50;
    cout << tmp << endl;
    
    tmp = 25 + baseAmount;
    cout << tmp << endl;

    tmp = baseAmount + fullAmount;
    cout << tmp << endl;
    
    cout << fullAmount << endl;
    
    return 0;
}

const Money operator+(const Money &amt1, const Money& amt2)
{
    Money result;
    result.dollars = amt1.dollars + amt2.dollars;
    result.cents = amt1.cents + amt2.cents;
    
    return result;
}

ostream& operator <<(ostream &out, const Money& amt)
{
    out << "$";

    out << amt.dollars;
    out << ".";
    out <<amt.cents;
    
    return out;
}

*/

class Rectangle
{
public:
    Rectangle():width(1), length(1){}
    Rectangle(int w, int l):width(w), length(l){}
    int getWidth(void) const {      return width;     }
    void setWidth(int w) {      width = w;     }
    int getLength(void) const {      return length;     }
    void setLength(int l) {      length = l;     }
    //declare more functions here
    
    friend istream& operator>>(istream &in, Rectangle &rec);
    friend ostream& operator<<(ostream &out, const Rectangle &rec);
    friend const bool operator!=(const Rectangle &r1, const Rectangle &r2);
    
private:
    int width;
    int length;
};

const bool operator!=(const Rectangle &r1, const Rectangle &r2);
ostream& operator<<(ostream &out, const Rectangle &rec);
istream& operator>>(istream &in, Rectangle &rec);

int main(int argc, const char* argv[])
{
    Rectangle r1;
    cout << "Please enter values for a rectangle: ";
    cin >> r1;
    cout << "r1 is: " << r1 << endl;
    
    Rectangle r2(10, 5);
    cout << "r2 is: " << r2 << endl;
    
    if (r1 != r2)
        cout << "Not equal!" << endl;
    else cout << "Equal" << endl;
    
    return 0;
}

const bool operator!=(const Rectangle &r1, const Rectangle &r2)
{
    if ((r1.length != r2.length) || (r1.width != r2.width))
        return true;
    else return false;
}

ostream& operator<<(ostream &out, const Rectangle &rec)
{
    out << rec.width;
    out << "x";
    out << rec.length;
    return out;
}

istream& operator>>(istream &in, Rectangle &rec)
{
    char x = 'x';
    
    in >> rec.width;
    in >> x;
    if (x != 'x')
    {
        cout << "Wrong input!" << endl;
        exit(1);
    }
    in >> rec.length;
    
    return in;
}
