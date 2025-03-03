// P6_OrderdMatrix

#include <iostream>
#include<iomanip>

using namespace std;

void FillMatrixWithOrderNumber(int arr[3][3], short Rows, short Cols)
{
    short Counter = 0;
    for (int i = 1; i <= Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Counter++;
            arr[i][j] = Counter;
        }
    }
}

void PrintMatrixWithOrderNumber(int arr[3][3], short Rows, short Cols)
{
    cout << "The Ordered Matrix array: \n";
    for (int i = 1; i <= Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(5) << arr[i][j];
        }
        cout << endl;
    }
}
int main()
{
    int arr[3][3];

    FillMatrixWithOrderNumber (arr,3,3);
    PrintMatrixWithOrderNumber(arr,3,3);
}