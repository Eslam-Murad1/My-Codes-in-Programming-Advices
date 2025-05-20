// P20_PalindromeMatrix

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}
void FillMatrixArray(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}
void PrintMatrixArray(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf("%0*d   ", 2, Matrix[i][j]);
        }
        cout << endl;
    }
}
bool IsPalindromArray(int arr[3][3], int Rows,int Cols)  
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols/2; j++)
        {
            if (arr[i][j] != arr[i][Cols - 1 - j])
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
    int MatrixArr[3][3] = { {1,0,1}, {2,3,2},{4,5,4} };

    cout << "1st Matrix:\n";
   /// FillMatrixArray(MatrixArr, 3, 3);
    PrintMatrixArray(MatrixArr, 3, 3);

    if (IsPalindromArray(MatrixArr,3, 3))
    {
        cout << "The matrix is Palindrom.";
    }
    else
        cout << "The matrix isn't Palindrom.";
}