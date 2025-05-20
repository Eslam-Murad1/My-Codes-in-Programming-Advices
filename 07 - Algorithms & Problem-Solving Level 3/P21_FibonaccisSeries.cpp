// P21_FibonaccisSeries
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void FillFibonaccisSeries(short Num)
{
    int Pre1= 1, Pre2 = 0;
    int FibonaccisNum = 0;
    cout << "1  ";
    for (int i = 2; i <= Num; i++)
    {
        FibonaccisNum = Pre1 + Pre2;
        cout << FibonaccisNum << "  ";
        Pre2 = Pre1;
        Pre1 = FibonaccisNum;
    }
}
int main()
{
    FillFibonaccisSeries(10);
}