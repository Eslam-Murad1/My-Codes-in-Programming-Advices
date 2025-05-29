// P29_CountSmallCapitalLetters
#include <iostream>
#include <string>
using namespace std;

enum enWhatToCount { SmallLetter = 0, CapitalLetter= 1, All=2};
short CountLetter(string S1, enWhatToCount WhatToCount=enWhatToCount::All)
{
	if (WhatToCount == enWhatToCount::All)
		return S1.length();

	short Counter = 0;
	for (short i = 0; i <= S1.length(); i++)
	{
		if (WhatToCount == enWhatToCount::CapitalLetter && isupper(S1[i]))
			Counter++;

		if (WhatToCount == enWhatToCount::SmallLetter && islower(S1[i]))
			Counter++;
	}
	return Counter;

}
string ReadString()
{
	string S1;
	cout << "Enter the Sentense:\n";
	getline(cin, S1);

	return S1;
}
short CountCapitalLetter(string s)
{
	short Counter=0;
	for (int i = 0; i <= s.length(); i++)
	{
		if (isupper(s[i]))
			Counter++;
	}
	return Counter;
}
short CountSmallLetter(string s)
{
	short Counter=0;
	for (int i = 0; i <= s.length(); i++)
	{
		if (islower(s[i]))
			Counter++;
	}
	return Counter;
}
int main()
{
	string s = ReadString();

	cout << "Method 1:\n";
	cout <<"String Lenght: " << s.length()<<endl;
	cout << "Capitel letter count: " << CountCapitalLetter(s) << endl;
	cout << "Small letter count: " << CountSmallLetter(s) << endl;

	cout << "\n\nMethod 2:\n";
	cout << "String Lenght: " << CountLetter(s) << endl;
	cout << "Capitel letter count: " << CountLetter(s,enWhatToCount::CapitalLetter) << endl;
	cout << "Small letter count: " << CountLetter(s,enWhatToCount::SmallLetter) << endl;


	return 0;
}