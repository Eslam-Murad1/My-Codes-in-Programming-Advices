// P8_MonthCalendar.cpp

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
short NumberOfDaysInMonth(int month, int year)
{
    if (month < 1 || month >12)
        return 0;

    short NumberOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month];
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
    /*string arrMonth[13] = { "", "January", "Feberuary","March", "April","May","June",
                         "July","August","September","October","November","Decambre" };*/
	string arrMonths[13] = {"", "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
    return arrMonths[month];
}
void MonthCalendar(int month, int year)
{
    string MonthNam = MonthName(month);
    int DaysInMonth = NumberOfDaysInMonth(month, year);
    int CurruntDay = DayNumber(1, month, year);

    printf("\n  _______________%s_______________\n\n",MonthNam.c_str());
              
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
int main()
{
    short year = ReadYear();
    short month = ReadMonth();

    MonthCalendar(month, year);

    return 0;
}