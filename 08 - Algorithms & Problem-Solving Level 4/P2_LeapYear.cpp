// P2_LeapYear.cpp
#include <iostream>

using namespace std;

bool IsLeapYear(int Year)
{
    return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
    //OR
    //return (Year % 400 == 0 ? true : Year % 100 != 0 && Year % 4 == 0 ? true : false);
}

int ReadYear()
{
    short Year;
    cout << "Enter a year: ";
    cin >> Year;

    return Year;
}
int main()
{
    short Year = ReadYear();

    if (IsLeapYear(Year))
    {
        cout << Year << " is a leap year." << endl;
    }
    else
    {
        cout << Year << " is not a leap year." << endl;
	}
}