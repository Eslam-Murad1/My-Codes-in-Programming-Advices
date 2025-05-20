// P19_Min&MaxNumberInMatrix// P18_InstersectedNumberInMatrix

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
int MinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    int MinNum = Matrix1[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] < MinNum)
            {
                MinNum = Matrix1[i][j];
            }
        }
    }
    return MinNum;
}
int MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    int MaxNum = Matrix1[0][0];
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] > MaxNum)
            {
                MaxNum = Matrix1[i][j];
            }
        }
    }
    return MaxNum;
}
int main()
{
    srand((unsigned)time(NULL));
    int MatrixArr1[3][3];

    cout << "1st Matrix:\n";
    FillMatrixArray(MatrixArr1, 3, 3);
    PrintMatrixArray(MatrixArr1, 3, 3);

    cout << "Min Number in Matrix: \n" << MinNumberInMatrix(MatrixArr1, 3, 3) << endl;
    cout << "Max Number in Matrix: \n" << MaxNumberInMatrix(MatrixArr1, 3, 3) << endl;

}