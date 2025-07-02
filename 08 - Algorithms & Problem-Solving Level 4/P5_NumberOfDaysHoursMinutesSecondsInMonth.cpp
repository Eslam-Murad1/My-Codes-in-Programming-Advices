// P5_NumberOfDaysHoursMinutesSecondsInMonth.cpp
#include <iostream>

using namespace std;

int ReadYear()
{
    short Year;
    cout << "Please, Enter a Year to check: ";
    cin >> Year;

    return Year;
}
int ReadMonth()
{
    short Month;
    cout << "Please, Enter a Month to check: ";
    cin >> Month;

    return Month;
}

bool IsLeapYear(int Year)
{
    return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
}

int NumberOfHours(int TheNumber)
{
    return TheNumber * 24;
}
int NumberOfMinutes(int TheNumber)
{
    return TheNumber * 24 * 60;
}
int NumberOfSeconds(int TheNumber)
{
    return TheNumber * 24 * 60 * 60;
}
short NumberOfDaysInMonth(int Year, int Month)
{
    if (Month < 1 || Month >12)
        return 0;

    short NumberOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month];
    /*if (Month == 2)
    {
        return IsLeapYear(Year) ? 29 : 28;
    }

    short arr31Days[7] = { 1,3,5,7,8,10,12 };
    for (int i = 1; i <= 7; i++)
    {
        if (arr31Days[i - 1] == Month)
            return 31;
    }
    return 30;*/
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Days = NumberOfDaysInMonth(Year,Month);

    if (Days == 0)
    {
        cout << "\nInfalid Month!";
    }
    else
    {
        cout << endl;
        cout << "Number of Days in Year [" << Month << "] is: " << Days << endl;
       /* cout << "Number of Hours in Year [" << Month << "] is: " << NumberOfHours(Days) << endl;
        cout << "Number of Minutes in Year [" << Month << "] is: " << NumberOfMinutes(Days) << endl;
        cout << "Number of Days in Year [" << Month << "] is: " << NumberOfSeconds(Days) << endl;*/
    }
    return 0;
}