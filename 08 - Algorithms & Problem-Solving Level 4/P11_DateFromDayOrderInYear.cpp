// P11_DateFromDayOrderInYear.cpp
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
    cout << "\nPlease, Enter a Year: ";
    cin >> Year;

    return Year;
}
int ReadMonth()
{
    short Month;
    cout << "\nPlease, Enter a Month: ";
    cin >> Month;

    return Month;
}
int ReadDay()
{
    short Day;
    cout << "\nPlease, Enter a Day: ";
    cin >> Day;

    return Day;
}
short NumberOfDaysInMonth(int month, int year)
{
    if (month < 1 || month >12)
        return 0;

    short NumberOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month];
}
short NumberOfDaysFromTheBeginningOfYear(int day, int month, int year)
{
    //Dr.Mohammed way
    short TotalDays = 0;
    for (int i = 1; i < month; i++)
    {
        TotalDays += NumberOfDaysInMonth(i, year);
    }
    TotalDays += day;
    return TotalDays;
}
stDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year)
{
    stDate Date;
    Date.Month = 1;
    Date.Year = Year;

    short RemainingDays = DayOrderInYear;
    short MonthDays;

    while (true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
            
    }
    return Date;
}
int main()
{
    int Day = ReadDay(), Month = ReadMonth(), Year = ReadYear();
    int DayOrderInYear = NumberOfDaysFromTheBeginningOfYear(Day, Month, Year);
   
    stDate Date = GetDateFromDayOrderInYear(DayOrderInYear, Year);

    cout << "\n\nNumber of days from the beginning of year is: " << DayOrderInYear << endl;
    cout << "Date for [" << DayOrderInYear << "] is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    return 0;
}