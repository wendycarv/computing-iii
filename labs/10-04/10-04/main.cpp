#include <iostream>
#include <string>

using namespace std;

class NewDate{
    friend class Holiday;
    
public:
    NewDate();
    NewDate(int initMonth, int initDay, int initYear);
            
    void setMonth(string initMonth);
    void setDay(int initDay);
    void setYear(int initYear);
            
    string getMonth(void)const;
    int getDay(void)const;
    int getYear(void)const;
    
    friend ostream& operator<<(ostream &out, const NewDate &aDate);

    void displayDate(void);
    
    private:
    int month;
    int day;
    int year;
};

NewDate::NewDate()
{
    month = 1;
    day = 1;
    year = 1999;
}

NewDate::NewDate(int initMonth, int initDay, int initYear)
{
    month = initMonth;
    day = initDay;
    year = initYear;
}


class Holiday{
public:
    Holiday():name("New Year's Day"), date(NewDate()), isDayOff(true){};
    Holiday(string iName, NewDate iDate, bool iIsDayOff):name(iName),  date(iDate),isDayOff(iIsDayOff){}
    Holiday(string iName, int iMonth, int iDay, int iYear, bool iIsDayOff);
    
    //overload << operator as a friend of the class
    friend ostream& operator <<(ostream &out, const Holiday &aHoliday);
    
private:
    string name;
    NewDate date;
    bool isDayOff;

};

Holiday::Holiday(string iName, int iMonth, int iDay, int iYear, bool iIsDayOff)
{
    name = iName;
    //month = iMonth;
    date = NewDate(iMonth, iDay, iYear); //explicitly calling constructor to create object
    isDayOff = iIsDayOff;
}

ostream& operator<<(ostream &out, const Holiday &aHoliday);

int main(int argc, const char * argv[])
{
    NewDate oneDay(10, 4, 2023);
    cout << oneDay << endl;
    
    Holiday newYearDay("New Year", 1, 1, 2023, true);
    cout << newYearDay << endl;

    return 0;
}

ostream& operator<<(ostream &out, const Holiday &aHoliday)
{
    out << aHoliday.name << ": " << aHoliday.date;
    if (aHoliday.isDayOff)
    {
        out <<", has a day off";
    } else
    {
        out <<", does not have a day off";
    }
    return out;
}
