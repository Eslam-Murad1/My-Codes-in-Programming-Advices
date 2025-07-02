// P13_Date1LessThanDate2.cpp
#include <iostream>
using namespace std;

struct stDate
{
    short Day, Month, Year;
};
bool IsLeapYear(int Year)
{
    return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
    //OR
    //return (Year % 400 == 0 ? true : Year % 100 != 0 && Year % 4 == 0 ? true : false);
}
int ReadYear()
{
    short Year;
    cout << "Please, Enter a Year: ";
    cin >> Year;

    return Year;
}
int ReadMonth()
{
    short Month;
    cout << "Please, Enter a Month: "; 
    cin >> Month;

    return Month;
}
int ReadDay()
{
    short Day;
    cout << "Please, Enter a Day: ";
    cin >> Day;

    return Day;
}
stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}
bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)):false);
}
int main()
{
    cout << "Date 1:  " << endl;
    stDate Date1 = ReadFullDate();
    cout << "\nDate 2:  " << endl;
    stDate Date2 = ReadFullDate();

    if (IsDate1BeforDate2(Date1, Date2))
        cout << "Yes, Date 1 is less than Date 2";
    else
        cout << "No , Date 1 isn't less than Date 2";
 
    return 0;
}