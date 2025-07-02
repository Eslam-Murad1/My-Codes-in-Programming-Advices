// 09_PropertiesGet&SetThrougth=

#include <iostream>
using namespace std;

class clsPerson
{
private:
    string _FName;
    string _LName;
public:
    void setFName(string FName) { _FName = FName; }
    string getFName() { return _FName; }
    __declspec(property(get = getFName, put = setFName)) string FirstName;

    void setLName(string LName) { _LName = LName; }
    string getLName() { return _LName; }
    __declspec(property(get = getLName, put = setLName)) string LastName;

};
int main()
{
    clsPerson Person1;

    Person1.FirstName = "Eslam";
    cout << Person1.FirstName << endl;

    Person1.LastName = "Mohammed";
    cout << Person1.LastName << endl;

    system("pause>0");
    return 0;
}