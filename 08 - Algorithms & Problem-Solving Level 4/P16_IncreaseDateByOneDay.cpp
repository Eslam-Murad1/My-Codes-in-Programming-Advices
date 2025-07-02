// P16_IncreaseDateByOneDay.cpp
#include <iostream>
using namespace std;

struct stDate
{
    short Day, Month, Year;
};
bool IsLeapYear(int Year)
{
    return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
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
stDate IncreaseDateByOne(stDate &Date)
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
int main()
{
    stDate Date = ReadFullDate();

    Date = IncreaseDateByOne(Date);
    cout << "Date After adding one day: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    return 0;
}