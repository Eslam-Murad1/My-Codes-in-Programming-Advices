// P33_CountVowelLetter

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
int CountVowel(string s)
{
	short Counter = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (IsVowel(s[i]))
		{
			Counter++;
		}
	}
	return Counter;
}
int main()
{
	string St = ReadString();

	cout << "Count of vowel letter in string: " << CountVowel(St);

	

}
