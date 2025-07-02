// P18_YourAgeInDays.cpp
// P17_DifferenceInDays.cpp
#pragma  warning(disable :4996)
#include <iostream>
#include <ctime>
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
short NumberOfDaysInMonth(int month, int year)
{
    if (month < 1 || month >12)
        return 0;

    short NumberOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month];
}
bool LastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}
bool LastMonthInYear(short Month)
{
    return (Month == 12);
}
bool IsDate1BeforDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
stDate IncreaseDateByOne(stDate& Date)
{
    if (LastDayInMonth(Date))
    {
        if (LastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
        Date.Day++;

    return Date;
}
short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    short DiffDays = 0;
    while (IsDate1BeforDate2(Date1, Date2))
    {
        DiffDays++;
        Date1 = IncreaseDateByOne(Date1);
    }
    return IncludeEndDay ? ++DiffDays : DiffDays;
}
stDate GetSystemDate()
{
    time_t t = time(0);
    tm* now = localtime(&t);

    stDate Date;
    Date.Day = now->tm_mday;
    Date.Month = now->tm_mon + 1;
    Date.Year = now->tm_year + 1900;

    return Date;
}

int main()
{
    cout << "Enter Your Date of Birth \n";
    stDate Date1 = ReadFullDate();
    stDate Date2 = GetSystemDate();

    cout << "\nYoue Age in Days is: [" << GetDifferenceInDays(Date1, Date2,true) << "] (days)";

    return 0;
}