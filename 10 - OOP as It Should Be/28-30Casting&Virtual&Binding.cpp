// 28-30Casting&Virtual&Binding
#include <iostream>
using namespace std;

class clsPerson
{
public:
    string Name = "Eslam";
    virtual void Print()
    {
        cout << "I'm person\n";
    }
};

class clsEmployee : public clsPerson
{
public:
    string Tital = "CEO";
    void Print()
    {
        cout << "I'm Employee\n";
    }
};
class clsStudent : public clsPerson
{
public:
    void Print()
    {
        cout << "I'm Student\n";
    }
};

int main()
{
    clsEmployee Employee1;
    clsStudent Student1;
    cout << "Early-Static Binding.\n";
    Employee1.Print();
    Student1.Print();
    /*cout << Employee1.Name << endl;
    cout << Employee1.Tital << endl;*/


    ////Up Casting. (form Biger to Smaller)
    clsPerson* Person1 = &Employee1;
    clsPerson* Person2 = &Student1;
    cout << "Late-Dynamic Binding by Pointer\n";
    Person1->Print();
    Person2->Print();

    return 0;
}