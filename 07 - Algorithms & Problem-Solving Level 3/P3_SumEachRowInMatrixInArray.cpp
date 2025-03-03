#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;

    return RandNum;
}
void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}
void PrintMatrix(int arr[3][3], short Rows, short Cols)
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
int RowSum(int arr[3][3], short Rows, short Cols)
{
    int Sum = 0;
    for (short j = 0; j < Cols; j++)
    {
         Sum += arr[Rows][j];
    }
    return Sum;
}
void FillSumMatrixIn1Array(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    
    for (short i = 0; i < Rows; i++)
    {
        arrSum[i] = RowSum(arr, i, Cols);
    }
}
void PrintRowsSumMatrixFrom1Array(int arr1[3],short Rows)
{

    cout << "The Following is The Sum of a 3×3 Random Matrix: " << endl;
    for (short i = 0; i < Rows; i++)
    {
        cout << "Row "<< i + 1<< " sum: " << arr1[i] << endl;
    }
 }
int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3], arrSum[3];

    FillMatrixWithRandomNumber(arr, 3, 3);
    cout << "The Following is a 3×3 Random Matrix: " << endl;
    PrintMatrix(arr, 3, 3);

    FillSumMatrixIn1Array(arr, arrSum, 3, 3);
    PrintRowsSumMatrixFrom1Array(arrSum,3);

    system("pause>0");
}