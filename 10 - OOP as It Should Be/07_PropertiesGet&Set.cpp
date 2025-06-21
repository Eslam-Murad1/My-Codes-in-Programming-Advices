// 07_PropertiesGet&Set
#include <iostream>
using namespace std;

class clsPerson
{
private:
    string _FName;
    string _LName;
public:
    void setFName(string FName) {_FName = FName;}
    string getFName(){ return _FName; }

    void setLName(string LName) { _LName = LName; }
    string getLName() { return _LName; }

};
int main()
{
    clsPerson Person1;

    Person1.setFName("Eslam");
    cout << Person1.getFName() << endl;

    Person1.setLName("Mohammed");
    cout << Person1.getLName() << endl;

    system("pause>0");
    return 0;
}