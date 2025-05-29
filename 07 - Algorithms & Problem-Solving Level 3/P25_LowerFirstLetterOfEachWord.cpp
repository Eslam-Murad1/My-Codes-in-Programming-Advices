// P25_LowerFirstLetterOfEachWord

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
		if (S[i] != ' ' && isFirstLetter)
		{
			S[i] = tolower(S[i]);
		}
		isFirstLetter = (S[i] == ' ' ? true : false);
	}
	return S;
}

int main()
{
	string St = ReadString();

	cout << "\nWord After make the first letter lower:\n";
	St = LowerAllWord(St);
	cout << St << endl;


}