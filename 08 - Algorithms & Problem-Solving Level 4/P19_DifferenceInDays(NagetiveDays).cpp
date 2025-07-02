// P19_DifferenceInDays(NagetiveDays).cpp
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
bool IsDate1EqualsDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) ? true : false : false : false;
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
void SwapDate(stDate& Date1, stDate& Date2)
{
    stDate temp;
    temp.Day = Date1.Day;
    temp.Month = Date1.Month;
    temp.Year = Date1.Year;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;

    Date2.Day = temp.Day;
    Date2.Month = temp.Month;
    Date2.Year = temp.Year;
}
short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    short DiffDays = 0;
    short SwapFlag = 1;
    if (!IsDate1BeforDate2(Date1, Date2))
    {
        SwapDate(Date1, Date2);
        SwapFlag = -1;
    }

    while (IsDate1BeforDate2(Date1, Date2))
    {
        DiffDays++;
        Date1 = IncreaseDateByOne(Date1);
    }

     return IncludeEndDay ? ++DiffDays*SwapFlag : DiffDays*SwapFlag;
}
int main()
{
    cout << "Date 1:  " << endl;
    stDate Date1 = ReadFullDate();
    cout << "\nDate 2:  " << endl;
    stDate Date2 = ReadFullDate();

    cout << "Difference days are:                    [" << GetDifferenceInDays(Date1, Date2) << "]" << endl;
    cout << "Difference days are (include last day): [" << GetDifferenceInDays(Date1, Date2, true) << "]" << endl;

    return 0;
}