// 41_ObjectsAndDynamicArray
#include <iostream>
using namespace std;

class clsA
{
public:
    //dummy/defualt constructor
    clsA(){}

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
    short NumbOfObjects = 5;

    //allocating dynamic array of size NumbOfObjects using new Keyword.
    clsA* arrA = new clsA[NumbOfObjects];


    //Calling Constructor for each index of array
    for (int i = 0; i < NumbOfObjects; i++)
    {
        arrA[i] = clsA(i);
    }

    for (int i = 0; i < NumbOfObjects; i++)
    {
        arrA[i].Print();
    }

    return 0;
}