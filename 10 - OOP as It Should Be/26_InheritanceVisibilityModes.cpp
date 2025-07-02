#include <iostream>
using namespace std;

class clsA
{

private:
    int V1;
    int Fun1()
    {
        return 1;
    }

protected:
    int V2;
    int Fun2()
    {
        return 2;
    }

public:
    int V3;
    int Fun3()
    {
        return 3;
    }

};

//try to change visibility mode public/private/protected 
//and see in the main what will happen iside objects.
class clsB : protected clsA
{

public:

    int Fun4()
    {
		clsA::Fun2(); // This will work because Fun2 is protected in clsA
        return 4;
    }

};

class clsC : private clsB
{

public:

    int Fun5()
    {
        clsB::Fun4();
        return 5;
    }
};


int main()
{


    clsB B1;
    B1.Fun4();
    //Try B1 after you change visibility mode in clsB.   and see what you can see.


    clsC C1;
    C1.Fun5();
    //Try C1 after you change visibility mode in clsB.   and see what you can see.

}
