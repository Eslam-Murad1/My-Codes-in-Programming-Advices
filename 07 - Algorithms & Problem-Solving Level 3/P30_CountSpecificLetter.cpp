// P30_CountSpecificLetter.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
short CountSpecificLetter(string S, char c)
{
	short counter = 0;
	for (short i = 0; i <= S.length();i++)
	{
		if (c == S[i])
			counter++;
	}
	return counter;
}
int main()
{
	string S1 = ReadString();
	short Ch = ReadCharcter();

	cout <<"The Letter is repet: " << CountSpecificLetter(S1, Ch);
}
