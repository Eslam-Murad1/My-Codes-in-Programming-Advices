// 39_PassingObjectsToFunction(ByRef&ByVal).cpp
#include <iostream>
using namespace std;

class clsA
{
public:
	int x = 0;

	void Print()
	{
		cout << "Value of x: " << x << endl;
	}


};

//By Value
void Fun1(clsA A1)
{
	A1.x = 200;
	//cout << A1.x << endl;
}

//By Referans
void Fun2(clsA& A1)
{
	A1.x = 100;
}

int main()
{
	clsA A1;

	A1.x = 50;
	cout << "A.x befor calling Funtions: \n";
	A1.Print();

	//By Value
	A1.Print();
	Fun1(A1);

	//By Refrance
	Fun2(A1);
	A1.Print();





	return 0;
}