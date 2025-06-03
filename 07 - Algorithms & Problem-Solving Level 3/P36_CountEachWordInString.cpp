// P36_CountEachWordInString

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
void CountEachWordInString(string S)
{
	string delim = " ";
	cout << "\nThe Number of words in your string are: ";

	short pos = 0,Counter = 0;
	string sWord;

	while ((pos = S.find(delim)) != string::npos) //
	{
		sWord = S.substr(0, pos);
		if (sWord != "")
			Counter++;

		S.erase(0, pos + delim.length());
	}
	if (S != "")
	  Counter++;

	cout << Counter;
}
int main()
{
	CountEachWordInString(ReadString());
}