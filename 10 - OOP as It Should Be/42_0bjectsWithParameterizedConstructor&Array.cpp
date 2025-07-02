// 42_0bjectsWithParameterizedConstructor&Array.cpp 
#include <iostream>
using namespace std;

class clsA
{
public:
    //Parameterized constructor
    
    clsA(int value)
    {
        x = value;
    }

    int x;

    void Print()
    {
        cout << "The Value of X = " << x << endl;
    }
};

int main()
{
    clsA A1[] = { clsA(10), clsA(20),clsA(30) };

    for (int i = 0; i < 3; i++)
    {
        A1[i].Print();
    }

    return 0;
}
