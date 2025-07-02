// P12_AddDaysToDate.cpp 
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
stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month= ReadMonth();
    Date.Year = ReadYear();

    return Date;
}
short ReadDaysToAdd()
{
    short DaysToAdd;
    cout << "How many days to add: ";
    cin >> DaysToAdd;

    return DaysToAdd;
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
    short TotalDays = 0;
    for (int i = 1; i < month; i++)
    {
        TotalDays += NumberOfDaysInMonth(i, year);
    }
    TotalDays += day;
    return TotalDays;
}
stDate DateAddDays(short DaysToAdd,stDate Date)
{
    short Remaining = DaysToAdd + NumberOfDaysFromTheBeginningOfYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;
    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

        if (Remaining > MonthDays)
        {
            Remaining -= MonthDays;
            Date.Month++;

            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = Remaining;
            break;
        }
    }
    return Date;
}

int main()
{
    stDate Date = ReadFullDate();
    short DaysToAdd = ReadDaysToAdd();
    
    Date = DateAddDays(DaysToAdd, Date);

    cout << "Date after adding [" << DaysToAdd << "] days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

    return 0;
}