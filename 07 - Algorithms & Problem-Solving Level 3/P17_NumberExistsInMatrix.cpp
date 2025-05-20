// P17_NumberExistsInMatrix

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}
int ReadNum(string Massege)
{
    int Num;
    cout << Massege;
    cin >> Num;
    return Num;
}
void FillMatrixArray(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}
void PrintMatrixArray(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf("%0*d   ", 2, arr[i][j]);
        }
        cout << endl;
    }
}
bool IsNumberExistsInMatrix(int arr1[3][3], short Rows, short Cols, int Number)
{
    int NumCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (arr1[i][j] == Number)
            {
                return true;
            }

        }
    }
    return false;
}
int main()
{
    srand((unsigned)time(NULL));
    int MatrixArr[3][3];

    cout << "1st Matrix:\n";
    FillMatrixArray(MatrixArr, 3, 3);
    PrintMatrixArray(MatrixArr, 3, 3);

    int Number = ReadNum("Enter Number to Exists: ");

    if (IsNumberExistsInMatrix(MatrixArr, 3, 3, Number))
    {
        cout << "Yes, the Number is Exists";
    }
    else
        cout << "No, The number not exists.";
}