// P9_YearCalendar.cpp
#include <iostream>

using namespace std;

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
bool IsLeapYear(int Year)
{
    return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
    //OR
    //return (Year % 400 == 0 ? true : Year % 100 != 0 && Year % 4 == 0 ? true : false);
}
short NumberOfDaysInMonth(int Year, int Month)
{
    if (Month < 1 || Month >12)
        return 0;

    short NumberOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month];
}
int DayNumber(int day, int month, int year)
{
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + (12 * a) - 2;
    //By Gregerian Calendar.
    int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    return d;
}
string MonthName(int month)
{
    string arrMonths[13] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
    return arrMonths[month];
}
void MonthCalendar(int month, int year)
{
    string MonthNam = MonthName(month);
    int DaysInMonth = NumberOfDaysInMonth(year, month);
    int CurruntDay = DayNumber(1, month, year);

    printf("\n  _______________%s_______________\n\n", MonthNam.c_str());

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for (i = 0; i < CurruntDay; i++)
        printf("     ");

    for (int j = 1; j <= DaysInMonth; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n  _________________________________\n\n");
}
void YearCalendar(int year)
{
    printf( "\n  _________________________________\n\n");
    printf( "         Calendar - %d\n",year);
    printf( "  _________________________________\n");


    for (int i = 1; i <= 12; i++)
    {
        MonthCalendar(i, year);
    }
    return;
}
int main()
{
    short year = ReadYear();

    YearCalendar(year);
  
    return 0;
}