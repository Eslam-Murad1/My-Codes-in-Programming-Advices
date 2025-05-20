// P11_ChackTypicalMatrices

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
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
bool CheckMatrixesEquality(int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3], arr2[3][3];

    cout << "1st Matrix:\n";
    FillMatrixArray(arr1, 3, 3);
    PrintMatrixArray(arr1, 3, 3);

    cout << "2nd Matrix:\n";
    FillMatrixArray(arr2, 3, 3);
    PrintMatrixArray(arr2, 3, 3);

    if (CheckMatrixesEquality(arr1, arr2, 3, 3))
        cout << "\nYes, Both Matrix are Typical.";
    else
        cout << "\nNo, Both Matrix are'nt Typical";

}