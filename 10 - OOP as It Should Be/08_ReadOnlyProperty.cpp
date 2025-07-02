// 08_ReadOnlyProperty

#include <iostream>
using namespace std;

class clsPerson
{
private:
    int _ID = 200321;
    string _FName;
    string _LName;
    int _DaysWork = 28;

public:
    void setFName(string FName) { _FName = FName; }
    string FName() { return _FName; }

    void setLName(string LName) { _LName = LName; }
    string LName() { return _LName; }

    int ID() { return _ID; }
    double Salary() { return _DaysWork * 50; }
};
int main()
{
    clsPerson Person1;

    Person1.setFName("Eslam");
    Person1.setLName("Mohammed");


    cout << "First Name: " <<  Person1.FName() << endl;
    cout << "Last Name: " << Person1.LName() << endl;
    cout << "ID: " << Person1.ID() << endl;
    cout << "Salary: " << Person1.Salary();

    system("pause>0");
    return 0;
}