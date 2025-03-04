// P8_MultiplyTowMatrix
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
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
}
void MultiplyTwoMatrix(int arrMult[3][3], int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arrMult[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3], arr2[3][3], arrMult[3][3];

    cout << "The First Matrix Array: \n";
    FillMatrixArray(arr1, 3, 3);
    PrintMatrixArray(arr1, 3, 3);

    cout << "\nThe Second Matrix Array: \n";
    FillMatrixArray(arr2, 3, 3);
    PrintMatrixArray(arr2, 3, 3);

    cout << "\nMultiply the two matrix:\n";
    MultiplyTwoMatrix(arrMult,arr1, arr2, 3, 3);
    PrintMatrixArray(arrMult, 3, 3);


}