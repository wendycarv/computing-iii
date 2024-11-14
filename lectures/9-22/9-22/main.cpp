
#include <iostream>
using namespace std;

class Money {
public:
    Money():dollars(0), cents(0){}
    Money(int iDollars, int iCents):dollars(iDollars), cents(iCents){}
    Money(int totalCents):dollars(totalCents/100), cents(totalCents%100){}
    Money(double totalAmount) {
        int totalCents = totalAmount * 100;
        dollars = totalCents / 100;
        cents = totalCents % 100;
    }
    
    int getDollars(void) const;//"const" promises not to modify the internal state (data members) of the object. It's used for functions that provide read-only access to the object's data.
    int getCents(void) const;
    
    void setDollars(int newValue);
    void setCents(int newValue);
    
    int toCents(void) const;//return the total cents
    void display(void) const;

    //Overload ++ as a friend operator/function
    friend Money& operator++(Money &op);//a friend function is NOT part of the class

        
    //Overload as a member operator
    //m1 + m2 => m1.+(m2);
    //const Money operator+(const Money& rightOp) ;
    //const Money operator+(double moneyAmount) ;
    
    friend const Money operator+(const Money &leftOp, const Money& rightOp);
    friend ostream& operator <<(ostream &out, const Money& rightOp);
private:
    int dollars;
    int cents;
};

//+(m1, m2)
const Money operator+(const Money &leftOp, const Money& rightOp);

bool operator==(const Money &leftOp, const Money& rightOp);

//overload << operator
///<<(cout, m1);
ostream& operator <<(ostream &out, const Money& rightOp);

//>>(cin, m1);
istream& operator >>(istream &in, Money &rightOp);

//overload ++
//prefix ++
//++m3
Money& operator++(Money &op);//by returning non-constant reference, enable the return object to be modified, so can chain the operator.  If decide not to modify the object, then use const

//postfix ++
//m3++;
const Money operator++(Money&op, int);

int main(int argc, char * argv[]) {
    Money m1(2, 55);
    Money m2(3, 50);
    Money m3(1, 23);
    (m1 + m2) + m3;
    //cout << "Enter a money value, e.g., $4.5: ";
    //cin >> m1;
    //>>(cin, m1);
    
    //cout <<"m1 is: " << m1 << endl;
    
    //cout <<"m1 + m2 = " << (m1+m2) << endl;
    //+(m1, m2)
    

    //Money m3(20, 25);
    //(m1 + m2) = m3;
    //(m1+m2).setDollars(10);
  
    //cout << "++m3 evalutes to " << ++m3 << endl;//21.26
    //cout << "after ++m3, m3 is: " << m3 << endl;
    
    //cout << "m3++ evalutes to " << m3++ << endl;//20.25
    //cout << "after m3++, m3 is: " << m3 << endl;
    
    Money  cost(1, 50), total;
    total = cost + 35.5; //(1)
    cout << "total is: " << total << endl;

    total = 35.5 + cost; //(2)
    //35.5+(cost)
    
    cout << "total is: " << total << endl;
    
    return 0;
}
 
//Overload + as a non-member operator

const Money operator+(const Money &leftOp, const Money& rightOp) {
    int totalCents = leftOp.toCents() + rightOp.toCents();
    //int totalD = totalCents / 100;
    //int totalC = totalCents % 100;
    //Money result(totalD, totalC);
    //Money result(totalCents);
    return Money(totalCents);
}

/*
//Overload + as a member operator
const Money Money::operator+(const Money& rightOp) {
    int totalCents = toCents() + rightOp.toCents();
    
    return Money(totalCents);
}
 */


//m3(20, 25);$20.25, increase by 1dollar, 1cent
//++m3:21 dollars, 26 cents
//m3: 21 dollars, 26 cents
/*
 prefix increment operator:
 the function should increment op and return op (the incremented value)
 */
Money& operator++(Money &op) {
    //int dollars = op.getDollars();
    //int cents = op.getCents();
    //op.setDollars(dollars + 1);
    //op.setCents(cents + 1);
    op.dollars++;
    op.cents++;
    return op;
}

//m3(20, 25);$20.25, increase by 1dollar, 1cent
//m3++:20, 25
//m3: 21, 26
/*
 postfix increment operator:
 the function should return the orginal value of op,
 also ensure that op is incremented
 */
 const Money operator++(Money& op, int) {
    
    int dollars = op.getDollars();
    int cents = op.getCents();
    op.setDollars(dollars + 1);
    op.setCents(cents + 1);
    
    return Money(dollars, cents);
}


ostream& operator <<(ostream &out, const Money& rightOp) {
    out << "$";
    
    out << rightOp.toCents()/100.0;
    return out;
}

void Money::display(void) const
{
    cout << "$" << toCents()/100.0 << endl;
}

//$3.45
istream& operator >>(istream &in, Money &rightOp) {
    char dollarSign;
    double dollarValue;
    in >> dollarSign;
    if (dollarSign != '$') {
        cout << "Wrong formate" << endl;
        exit(1);
    }
    in >> dollarValue;
    int totalCents = dollarValue * 100;
    
    //modify rightOp
    rightOp.setDollars(totalCents / 100);
    rightOp.setCents(totalCents % 100);
    
    return in;
}


//TODO: unary operator

/*
Money::Money() {
    dollars = 0;
    cents = 0;
}
Money::Money(int iDollars, int iCents) {
    dollars = iDollars;
    cents = iCents;
}
*/

int Money::getDollars(void) const {
    return dollars;
}
int Money::getCents(void) const {
    return cents;
}
void Money::setDollars(int newValue) {
    dollars = newValue;
}
void Money::setCents(int newValue) {
    cents = newValue;
}

int Money::toCents(void) const {
    return dollars * 100 + cents;
}
