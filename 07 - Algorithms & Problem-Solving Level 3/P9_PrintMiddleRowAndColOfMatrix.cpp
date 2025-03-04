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
           printf("%0*d  ", 2,  arr[i][j]);
           //cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
}
void PrintMiddleOfRows(int arr[3][3], short Rows, short Cols)
{
    short MidRow = Rows / 2;
    for (int j = 0; j < Cols; j++)
    {
        printf("%0*d  ", 2, arr[MidRow][j]);
    }
    cout << endl;
}
void PrintMiddleOfCols( int arr[3][3], short Rows, short Cols)
{
    
    short MidCol = Cols / 2;
    for (int j = 0; j < Rows; j++)
    {
        printf("%0*d  ", 2, arr[j][MidCol]);
    }
    cout << endl;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];

    cout << "The Matrix Array: \n";
    FillMatrixArray(arr, 3, 3);
    PrintMatrixArray(arr, 3, 3);

    cout << "\nMiddel Row of Matrix:\n";
    PrintMiddleOfRows(arr, 3, 3);
    

    cout << "\nMiddel Colum of Matrix:\n";
    PrintMiddleOfCols(arr, 3, 3);

}