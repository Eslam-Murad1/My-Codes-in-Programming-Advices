// P42_ReplaceWord(Custom).
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector <string>SplitString(string S, string Delim)
{
	vector <string> vSt;

	short pos = 0;
	string sWord;

	while ((pos = S.find(Delim)) != string::npos) //
	{
		sWord = S.substr(0, pos);
		if (sWord != " ")
			vSt.push_back(sWord);

		S.erase(0, pos + Delim.length());
	}
	if (S != "")
		vSt.push_back(S);

	return vSt;

}
string JoinString(vector<string> words, string Delim)
{
	string St = "";

	for (string& s : words)
	{
		St = St + s + Delim;
	}
	return St.substr(0, St.length() - Delim.length());
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
string ReplaceWordInStringUsingSplit(string St, string StringToReplace, string ReplaceTo, bool MatchCase = true)
{		
	vector <string> vString = SplitString(St," ");

	for (string& s : vString)
	{
		if (MatchCase)
		{
			if (s == StringToReplace)
			{
				s = ReplaceTo;
			}
		}
		else
		{
			if (LowerAllWord(s) == LowerAllWord(StringToReplace))
			{
				s = ReplaceTo;
			}
		}
	}
	return JoinString(vString, " ");
}
int main()
{
	string St = "Welcome to Yemen , Yemen is a great Country.";
	string StringToReplace = "yemen";
	string ReplaceTo = "KSA";

	cout << "Original String: \n" << St;

	cout << "\n\nAfter Replace with match case: \n";
	cout << ReplaceWordInStringUsingSplit(St, StringToReplace, ReplaceTo);

	cout << "\n\nAfter Replace without match case: \n";
	cout << ReplaceWordInStringUsingSplit(St, StringToReplace, ReplaceTo, false);
	system("pause>0");
}