// P31_CountLetter(MatchCase)
//

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
char ReadCharcter()
{
	char c;
	cout << "Enter Character to count in the string:\n";
	cin >> c;
	return c;
}
char InvertCharCase(char c)
{
	return isupper(c) ? tolower(c) : toupper(c);	
}
short CountSpecificLetter(string S, char c,bool MatchCase = true)
{
	short counter = 0;
	
	for (short i = 0; i < S.length(); i++)
	{
		if (MatchCase)
		{
			 if(c == S[i])
				counter++;
		}
		else
		{
		   if (tolower(c) == tolower(S[i]))
		    counter++;
			
		}
	}
	return counter;
}
int main()
{
	string S1 = ReadString();
	char Ch = ReadCharcter();
	

	cout << "Letter \'" << Ch << "\' count :" << CountSpecificLetter(S1, Ch) << endl ;
	cout << "\nLetter \'" << Ch << "\' or " << InvertCharCase(Ch) << " count :" << CountSpecificLetter(S1, Ch, false);

}
