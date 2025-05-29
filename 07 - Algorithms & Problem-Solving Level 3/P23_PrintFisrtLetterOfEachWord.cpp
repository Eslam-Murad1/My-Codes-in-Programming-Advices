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
void PrintFirstLetterOfWord(string S)
{
	bool isFirstLetter = true;

	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] != ' ' && isFirstLetter)
		{
			cout << S[i] << endl;
		}
		
		isFirstLetter = (S[i] == ' ' ? true : false);
	}
}
int main()
{
	PrintFirstLetterOfWord(ReadString());
}