// P22_FIbonacciWithRecursion
#include <iostream>
using namespace std;

void PrintFIbonacciUsingRecursion(int Num, int Prev1, int Prev2)
{
    int FebNum = 0;
    if (Num > 0)
    {
        FebNum = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = FebNum;
        cout << FebNum << "  ";

        PrintFIbonacciUsingRecursion(Num - 1, Prev1, Prev2);
    }
}
int main()
{
    PrintFIbonacciUsingRecursion(10, 0, 1);
}