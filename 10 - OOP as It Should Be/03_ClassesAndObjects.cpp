// 03_ClassesAndObjects

#include <iostream>
using namespace std;

class clsPerson
{
public:
    string FName;
    string LName;

    string FullName()
    {
        return FName + " " + LName;
    }
};

int main()
{
    clsPerson Person1;
    cout << "First Name: ";
    cin >> Person1.FName;
     
    cout << "Last Name: ";
    cin >> Person1.LName;

    cout << Person1.FullName();

}