// P26 UpperLower All letters of Each Word

#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Enter the Sentense:\n";
	getline(cin, S1);

	return S1;
}
string LowerAllWord(string S)
{
	bool isFirstLetter = true;

	for (int i = 0; i < S.length(); i++)
	{
		S[i] = tolower(S[i]);
	}
	return S;
}
string UpperAllWord(string S)
{
	bool isFirstLetter = true;

	for (int i = 0; i < S.length(); i++)
	{
		S[i] = toupper(S[i]);
	}
	return S;
}

int main()
{
	string St = ReadString();

	cout << "\nLower Word:\n";
	St = LowerAllWord(St);
	cout << St << endl;

	cout << "\nUpper Word:\n";
	St = UpperAllWord(St);
	cout << St << endl;


}