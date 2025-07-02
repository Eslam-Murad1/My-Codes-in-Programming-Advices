// 28_UpCasting&DownCasting
#include <iostream>
using namespace std;

class clsPerson
{
public:
    string Name =  "Eslam";
};

class clsEmplo : public clsPerson
{
public:
    string Tital = "CEO";
};
int main()
{
    clsEmplo Employee1;
    //Early-Static Binding.
    cout << Employee1.Name << endl;
    cout << Employee1.Tital << endl;

    ////Up Casting. (form Biger to Smaller)
    clsPerson* person1 = &Employee1;
    //Late-Dynamic Binding.
    cout << person1->Name;

    ////Down Casting (We cant do that; becaus from Smaller to biger).
    //clsEmplo* Employee2 = &Person2;

    return 0;
}