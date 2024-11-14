#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    double interest_rate;
    double total_interest;
    double face_value;
    int duration_months;
    double duration_year;
    double monthly_payment;
    double amount_received;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "Please enter the annual interest rate as a percentage (e.g., 15 for 15%) (enter 0 to quit): ";
    cin >> interest_rate;
    if (interest_rate == 0)
    {
        return 0;
    }
    
    interest_rate = interest_rate / 100;
    
    cout << "Please enter the amount you would like to receive: ";
    cin >> amount_received;
    
    cout << "Please enter the loan period in months: ";
    cin >> duration_months;
    
    duration_year = duration_months/12.0;
    face_value = amount_received / ((1 - interest_rate) * duration_year);
    
    monthly_payment = face_value / duration_months;
    
    cout << " The total amount of your loan (including interest at " << interest_rate * 100 << "% per annum) is " << face_value << endl;
    cout << "Your monthly payment for " << duration_months << " months will be " << monthly_payment << endl;
    
    return 0;
}

