// P28_InvertAllLettersCase

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
char InvertCharcterCase(char Ch)
{
	return isupper(Ch) ? tolower(Ch) : toupper(Ch);
}
string InvertAllLettersCase (string S)
{
	for (int i = 0; i < S.length(); i++)
	{
		 S[i] = InvertCharcterCase(S[i]);
	}
	return S;
}
int main()
{
	string St = ReadString();

	cout << "Words after invert:\n" << InvertAllLettersCase(St);
}