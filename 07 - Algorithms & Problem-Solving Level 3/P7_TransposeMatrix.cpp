// P7_TransposeMatrix

#include <iostream>
#include<iomanip>

using namespace std;

void FillMatrixWithOrderNumber(int arr[3][3], short Rows, short Cols)
{
    short Counter = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Counter++;
            arr[i][j] = Counter;
        }
    }
}
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    cout << "The Ordered Matrix array: \n";
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(5) << arr[i][j];
        }
        cout << endl;
    }
}

void FillTransposeMatrix(int arr[3][3], int arrTran[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arrTran[i][j] = arr[j][i];
        }
    }
}
void PrintTransposeMatrix(int arrTran[3][3], short Rows, short Cols)
{
    cout << "The Transpose Matrix array: \n";
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(5) << arrTran[i][j];
        }
        cout << endl;
    }
}
int main()
{
    int arr[3][3];
    int arrTran[3][3];

    FillMatrixWithOrderNumber(arr, 3, 3);
    PrintMatrix(arr, 3, 3);

    FillTransposeMatrix(arr,arrTran, 3, 3);
    PrintMatrix(arrTran, 3, 3);
}
