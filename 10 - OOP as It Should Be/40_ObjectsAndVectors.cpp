// 40_ObjectsAndVectors.cpp
#include <iostream>
#include <vector>
using namespace std;

class clsA
{
public:
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
    short NumOfObjects = 5;
    vector <clsA> v1;

    //Insetring objects at the end of vector
    for (int i = 0; i < NumOfObjects; i++)
    {
        v1.push_back(clsA(i));
    }

    //Printing objects Content 
    for (int i = 0; i < NumOfObjects; i++)
    {
        v1[i].Print();
    }

    return 0;
}