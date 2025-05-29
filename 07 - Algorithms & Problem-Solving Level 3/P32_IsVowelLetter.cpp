// P32_IsVowelLetter
//

#include <iostream>
#include <string>
using namespace std;

char ReadCharcter()
{
	char c;
	cout << "Enter Character to check if vowel or not:\n";
	cin >> c;
	return c;
}
bool IsVowel(char c)
{
	c = tolower(c);
	return ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'));
}
int main()
{
	char Ch = ReadCharcter();

	if (IsVowel(Ch))
	{
		cout << "YES, Letter: '" << Ch << "' is a vowel.";
	}
	else
	{
		cout << "NO, Letter: '" << Ch << "' is not a vowel.";
	}

}
