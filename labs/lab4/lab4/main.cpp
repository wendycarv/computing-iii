#include <iostream>
#include <string>

using namespace std;

class Month {
    friend class Date;
    
    friend ostream& operator<< (ostream&, Month);
    
    private:
        enum EMonth { Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
            
        Month() : _month(Jan) {} // default constructor
        Month(int im) : _month( static_cast<EMonth>(im) ) {} // value constructor
        
        void setMonth(string m) { _month = StringToEMonth(m); } // mutator functions
        void setMonth(int im) { _month = static_cast<EMonth>(im); }
        
        /* Private helper member functions */
        EMonth StringToEMonth(string);
        int MonthToInt() { return static_cast<int>(_month); }
        string MonthToString();
        string MonthToString2();

        EMonth _month;
};

/* Definitions of helper member functions for class Month */

Month::EMonth Month::StringToEMonth(string m) {
    if (m == "Jan") return Jan;
    else if (m == "Feb") return Feb;
    else if (m == "Mar") return Mar;
    else if (m == "Apr") return Apr;
    else if (m == "Jun") return Jun;
    else if (m == "Jul") return Jul;
    else if (m == "Aug") return Aug;
    else if (m == "Sep") return Sep;
    else if (m == "Oct") return Oct;
    else if (m == "Nov") return Nov;
    else if (m == "Dec") return Dec;
    else {
        cerr << "Month::StringToMonth: Invalid input month \"" << m << "\"\n";
        exit(1);
    }
}

string Month::MonthToString() {
    switch (_month) {
        case Jan: return "Jan";
        case Feb: return "Feb";
        case Mar: return "Mar";
        case Apr: return "Apr";
        case May: return "May";
        case Jun: return "Jun";
        case Jul: return "Jul";
        case Aug: return "Aug";
        case Sep: return "Sep";
        case Oct: return "Oct";
        case Nov: return "Nov";
        case Dec: return "Dec";
        default:
            cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
            exit(1);
    }
}

string Month::MonthToString2() {
    switch (_month) {
        case Jan: return "January";
        case Feb: return "February";
        case Mar: return "March";
        case Apr: return "April";
        case May: return "May";
        case Jun: return "June";
        case Jul: return "July";
        case Aug: return "August";
        case Sep: return "September";
        case Oct: return "October";
        case Nov: return "November";
        case Dec: return "December";
        default:
            cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
            exit(1);
    }
}

/* Definition of friend function operator<< */

ostream& operator<< (ostream& out, Month m) {
    out << m.MonthToString2();
    return out;
}


/*
 • a member function outputDateAsInt(ostream&) that writes the Date to an output stream
 passed as an argument to the function, representing the month using an integer (e.g.,
 “12/31/2018”);
 • a member function outputDateAsString(ostream&)that writes the Date to an output
 stream passed as an argument to the function, representing the month using the first three letters in
 the name of the month (e.g., “Dec 31, 2018”);
 • an overloaded version of the pre-increment operator ++ (written as a member function) that retains
 the same month and day of month as the current Date, but increments the year number.
 */
class Date{
    
    //friend class Month;
    
    public:
    //default constructor
    Date(): Month.month("January"), day(1), year(2018){};
    //value constructor that sets the month value
    Date (int initMonth, int initDay, int initYear);
    //value constructor that sets the month using the first three letters for the month
    Date (string initMonth, int initDay, int initYear);
    
    //accessors
    
    //mutators
    //mutator that changes the value of the month
    void setMonth (int initMonth);
    
    //writes the Date to an output stream passed as an argument to the function, representing the month using an integer (e.g.,“12/31/2018”);
    void outputDateAsInt(ostream& out, Date& date);
    void outputDateAsString(ostream& out);

    void setMonth3Letters(Month &month);
    
    Date operator++()
    {
        year++;
        return *this;
    }
    //non-member friend function that overloads <<
    friend ostream& operator<< (ostream &out, const Date &date);
    private:
        Month month;
        int day;
        int year;
};

Date::Date(int initMonth, int initDay, int initYear)
{
    month = initMonth;
    day = initDay;
    year = initYear;
}

//value constructor that sets the month using the first three letters for the month
Date::Date(string initMonth, int initDay, int initYear)
{
    month.StringToEMonth(initMonth);
    day = initDay;
    year = initYear;
}

//sets month using integer
void Date::setMonth (int initMonth)
{
    month = initMonth;
}

//writes the Date to an output stream passed as an argument to the function, representing the month using an integer
void Date::outputDateAsInt(ostream& out, Date &date)
{
    int m;
    m = month.MonthToInt();
    out << m << "/" << day << "/" << year << endl;
}


void Date::outputDateAsString(ostream& out)
{
    int m;
    string mon;
    m = tmp.MonthToInt();
    out << mon << day << "," << year << endl;
}
 


ostream& operator<< (ostream &out, const Date &date);

//
//
//
//
//
//*****MAIN PROGRAM******//
int main(int argc, const char * argv[])
{
    Date default_date, test;
    
    cout << "Default constructor date: " << default_date << endl;
    
    test = Date("Sep", 27, 2023);
    cout << "Value constructor taking in \"Sep\", date is: " << test << endl;
    
    test.setMonth(3);
    cout << "Changing month to March using an integer: " << test << endl;
    
    test = Date(2, 1, 2023);
    cout << "Value constructor setting month to February: " << test << endl;
    
    test.outputDateAsInt(cout);
    
    return 0;
}

ostream& operator<< (ostream &out, const Date &date)
{
    out << date.month << " " << date.day << ", " << date.year << endl;
    return out;
}


