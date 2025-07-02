// P7_DayName.cpp
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
int ReadDay()
{
    short Month;
    cout << "Please, Enter a Day: ";
    cin >> Month;

    return Month;
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
string DayName(int day)
{
    string Days[7] = { "Sunday", "Monday","Tuesday","Wedensday","Thursday","Friday","Saturday" };
    return Days[day];
}
int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    short day = ReadDay();
    short DayNum = DayNumber(day, month, year);

    cout << "\nDate      :" << day << '/' << month << '/' << year;
    cout << "\nDay Order :" << DayNum;
    cout << "\nDay Name  :" << DayName(DayNum);

    return 0;
}