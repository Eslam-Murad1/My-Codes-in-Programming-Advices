// P34_PrintAllVowelLetterInString

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
bool IsVowel(char c)
{
	c = tolower(c);
	return ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'));
}
void CountVowel(string s)
{
	
	for (int i = 0; i < s.length(); i++)
	{
		if (IsVowel(s[i]))
		{
			cout << s[i] << " ";
		}
	}
	
}
int main()
{
	string St = ReadString();
	cout << "Vowel Letters: ";
	CountVowel(St);
}
