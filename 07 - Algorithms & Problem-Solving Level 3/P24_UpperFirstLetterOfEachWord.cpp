// P24_UpperFirstLetterOfEachWord

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
string UpperFirstLetterOfWordToUpper(string S)
{
	bool isFirstLetter = true;

	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] != ' ' && isFirstLetter)
		{
			S[i] = toupper(S[i]);
		}

		isFirstLetter = (S[i] == ' ' ? true : false);
	}
	return S;
}

int main()
{
	string St = ReadString();
	
	St = UpperFirstLetterOfWordToUpper(St);
	cout << St;
}