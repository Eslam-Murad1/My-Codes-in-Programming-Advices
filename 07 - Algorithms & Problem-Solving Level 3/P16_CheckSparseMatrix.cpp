// P15_CountNUmberInMatrix

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
            arr[i][j] = RandomNumber(0, 3);
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
int CountNumberInMatrix(int MatrixArr[3][3], short Rows, short Cols, int Number)
{
    int NumCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (MatrixArr[i][j] == Number)
            {
                NumCount += 1;
            }

        }
    }
    return NumCount;
}
bool CheckSparseMatrix(int arr[3][3], short Rows, short Cols)
{
    int MatrixSize = Rows * Cols;
    return (CountNumberInMatrix(arr, 3, 3, 0) >= (MatrixSize/2));
}
int main()
{
    srand((unsigned)time(NULL));
    int MatrixArr[3][3];

    cout << "1st Matrix:\n";
    FillMatrixArray(MatrixArr, 3, 3);
    PrintMatrixArray(MatrixArr, 3, 3);

    if (CheckSparseMatrix(MatrixArr, 3, 3))
        cout << "The matrix is sparse.";
    else
        cout << "The matrix is'nt sparse.";


    return 0;
}