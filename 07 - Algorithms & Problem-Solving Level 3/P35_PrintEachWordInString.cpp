// P35_PrintEachWordInString
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
void PrintEachWordInString(string S)
{
	string delim = " ";
	cout << "\nYour string words are:\n";

	short pos = 0;
	string sWord;

	while ((pos = S.find(delim)) != string::npos) //
	{
		sWord = S.substr(0, pos);
		if (sWord != "")
			cout << sWord << endl;

		S.erase(0, pos + delim.length());
	}
	if (S != "")
		cout << S << endl;
}
int main()
{
	PrintEachWordInString(ReadString());
}