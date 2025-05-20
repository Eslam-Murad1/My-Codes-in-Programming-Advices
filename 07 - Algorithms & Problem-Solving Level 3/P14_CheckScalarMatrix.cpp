// P14m_ChackIdentitylMatrs

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
            arr[i][j] = RandomNumber(0, 1);
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
bool CheckScalarMatrix(int arr1[3][3], short Rows, short Cols)
{
    int FirstElement = arr1[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && arr1[i][j] != FirstElement)
            {
                return false;
            }
            else if (i != j && arr1[i][j] != 0)
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
    int arr1[3][3] = { {9,0,0},{0,9,0}, {0,0,9} };

    cout << "1st Matrix:\n";
    //FillMatrixArray(arr1, 3, 3);
    PrintMatrixArray(arr1, 3, 3);

    if (CheckScalarMatrix(arr1, 3, 3))
        cout << "\nYes,Matrix is Scalar.";
    else
        cout << "\nNo,Matrix is'nt Scalar";

}