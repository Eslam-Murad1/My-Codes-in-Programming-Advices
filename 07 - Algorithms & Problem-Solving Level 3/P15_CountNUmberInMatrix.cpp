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
int CountNumberInMatrix(int arr1[3][3], short Rows, short Cols,int Number)
{
    int NumCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (arr1[i][j] == Number)
            {
                NumCount += 1;
            }
            
        }
    }
    return NumCount;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr1[3][3];

    cout << "1st Matrix:\n";
    FillMatrixArray(arr1, 3, 3);
    PrintMatrixArray(arr1, 3, 3);

    int Number = ReadNum("\n\nEnter number to count in the matrix: ");
    cout << Number << endl;

    
	cout << "The count of the number " << Number << "in matrix is : " << CountNumberInMatrix(arr1, 3, 3, Number) << endl;
}