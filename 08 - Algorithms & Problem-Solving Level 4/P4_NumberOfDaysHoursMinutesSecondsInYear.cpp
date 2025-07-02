// P4_NumberOfDaysHoursMinutesSecondsInYear.cpp
#include <iostream>

using namespace std;

int ReadYear()
{
    short Year;
    cout << "Enter a year: ";
    cin >> Year;

    return Year;
}

bool IsLeapYear(int Year)
{
    return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
}

int NumberOfHours(int Days)
{
    return Days * 24;
}
int NumberOfMinutes(int Days)
{
    return Days * 24 *60;
}
int NumberOfSeconds(int Days)
{
    return Days * 24 * 60 * 60;
}
short NumberOfDaysHoursMinutesSecondsInYear(int Year)
{
    if (IsLeapYear(Year))
    {
        return 366;
    }
    else
    {
        return 365;
    }
}

int main()
{
    short Year = ReadYear();
    short Days = NumberOfDaysHoursMinutesSecondsInYear(Year);
    
    if (Days == 366)
    {
        cout << "Number of Days in Year ["<< Year<<"] is: " << Days << endl;
        cout << "Number of Hours in Year [" << Year << "] is: " << NumberOfHours(Days) << endl;
        cout << "Number of Minutes in Year [" << Year << "] is: " << NumberOfMinutes(Days) << endl;
        cout << "Number of Days in Year [" << Year << "] is: " << NumberOfSeconds(Days) << endl;
    }
    else
    {
        cout << "Number of Days in Year [" << Year << "] is: " << Days << endl;
        cout << "Number of Hours in Year [" << Year << "] is: " << NumberOfHours(Days) << endl;
        cout << "Number of Minutes in Year [" << Year << "] is: " << NumberOfMinutes(Days) << endl;
        cout << "Number of Days in Year [" << Year << "] is: " << NumberOfSeconds(Days) << endl;
    }
    return 0;
}