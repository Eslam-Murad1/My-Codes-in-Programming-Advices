//SumCols
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}
void Fill3by3Matrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}
void Print3by3Matrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "  ";
        }
        cout << endl;
    }
}
int ColSum(int arr[3][3], short Rows, short Cols)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        Sum += arr[i][Cols];
    }
    return Sum;
}
void PrintEachColsSum(int arr[3][3], short Rows, short Cols)
{
    cout << "The Following is The Sum of a 3×3 Random Matrix: " << endl;
    for (short j = 0; j < Cols; j++)
    {
        cout << "The Sum of Colums " << j + 1 << " is: " << ColSum(arr, Rows, j) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    Fill3by3Matrix(arr, 3, 3);
    cout << "The Following is a 3×3 Random Matrix: " << endl;
    Print3by3Matrix(arr, 3, 3);

    PrintEachColsSum(arr, 3, 3);

    system("pause>0");
}