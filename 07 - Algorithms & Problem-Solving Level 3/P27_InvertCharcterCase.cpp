// P27_InvertCharcterCase

#include <iostream>
#include <string>

using namespace std;

char GetCharUser(string Message)
{
	char Ch1;
	cout << Message;
	cin >> Ch1;
	return Ch1;
}
char InvertCharcterCase(char Ch)
{
	return isupper(Ch) ? tolower(Ch) : toupper(Ch);
}
int main()
{
	char Ch = GetCharUser("Enter Character to Inverst it:");

	cout <<"Charcter after invert: " << InvertCharcterCase(Ch);
}