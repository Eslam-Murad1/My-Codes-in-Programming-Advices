//38_thisPointerInC++

#include <iostream>
using namespace std;

class clsEmployee
{
public:
    int ID;
    string Name;
    float Salary;

    clsEmployee(int ID, string Name, float Salary)
    {
        this->ID = ID;
        this->Name = Name;
        this->Salary = Salary;
    }

    static void Fun1S(clsEmployee Emplo1)
    {
        Emplo1.Print();
    }

    void Fun2()
    {
        Fun1S(*this);
    }

    void Print()
    {
        cout << ID << " " << Name << " " << Salary << endl;
        cout << this->ID << " " << this->Name << " " << this->Salary << endl;
    }
};
int main()
{
    clsEmployee Emp1(2003, "Eslam", 50000);

    Emp1.Print();
    Emp1.Fun2();

    return 0;
}
