//
//  C3_Lecture27-Inheritance Example
//

#include <iostream>
#include <string>

using namespace std;

//name, payRate
//paid monthly, pay method to calculate montly payment
//payRate different
//non-manager are paid hourly
//managers: (1) salary based (2) non-salary based: paid by hours

class Employee {
public:
    Employee(){};
    Employee(string iName, double iPayRate):name(iName), payRate(iPayRate){}
    string getName(void) const {return name;}
    double getPayRate(void) const {return payRate;}
    void setName(string newValue) {name = newValue;}
    void setPayRate(double newValue) {payRate = newValue;}
    double pay(int hourWorked) {
        return payRate * hourWorked;
    }
private:
    string name = "none";
    double payRate = 0.0;
};

class Manager:public Employee {
public:
    Manager():Employee(){}
    Manager(string iName, double iPayRate, bool iSalaried):Employee(iName, iPayRate),isSalaried(iSalaried){}
    
    double pay(int hourWorked) {//To be continued
        if (isSalaried) {
            return getPayRate();
        } else {
            return Employee::pay(hourWorked);
        }
    }
private:
    bool isSalaried = false;
    
};

int main(int argc, const char * argv[]) {
    Employee john("John", 15.0);
    cout << "John worked for 100 hours, so the payment is: " << john.pay(100) << endl;
    
    cout << endl;
    Manager mike("Mike", 3000, true);
    cout << mike.pay(160) << endl;
    
    return 0;
}
