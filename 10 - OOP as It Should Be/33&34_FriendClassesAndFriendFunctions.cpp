// 33&34_FriendClassesAndFriendFunctions

#include <iostream>
using namespace std;

class clsA
{
private:
    int _var1;

protected:
    int _var2;
public:
    int var3;

    clsA(int v1, int v2, int v3)
    {
        _var1 = v1;
        _var2 = v2;
         var3 = v3;
       
    }

    friend class clsB; //Friend Class
    friend int MySum(clsA A1); //Friend Function
};


class clsB
{
public:
    
    void display(clsA A1)
    {
        cout << "Var 1: " << A1._var1 << endl;
        cout << "Var 2: " << A1._var2 << endl;
        cout << "Var 3: " << A1.var3<< endl;
    }
    
};

//Friend Function
int MySum(clsA A1)
{
    return A1._var1 + A1._var2 + A1.var3;
}

int main()
{
    clsA A1(10,20,30);
    clsB B1;

    B1.display(A1);

    cout << MySum(A1);
    //cout << A1.v4 << endl;
}