// P18_InstersectedNumberInMatrix

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
            Matrix[i][j] = RandomNumber(1, 10);
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
bool IsNumberExistsInMatrix(int Matrix1[3][3], short Rows, short Cols, int Number)
{
    int NumCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                return true;
            }

        }
    }
    return false;
}
void InstersectedNumberInMatrix(int Matrix1[3][3],int Matrix2[3][3], short Rows, short Cols)
{
    int Number;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Number = Matrix1[i][j];
            if (IsNumberExistsInMatrix(Matrix2,Rows,Cols,Number))
            {
                cout << setw(4) << Matrix1[i][j] << "         ";
            }

        }
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int MatrixArr1[3][3], MatrixArr2[3][3];

    cout << "1st Matrix:\n";
    FillMatrixArray(MatrixArr1, 3, 3);
    PrintMatrixArray(MatrixArr1, 3, 3);

    cout << "2nd Matrix:\n";
    FillMatrixArray(MatrixArr2, 3, 3);
    PrintMatrixArray(MatrixArr2, 3, 3);

    cout << "Instersected Number in Matrix: \n";
    InstersectedNumberInMatrix(MatrixArr1, MatrixArr2, 3, 3);

}