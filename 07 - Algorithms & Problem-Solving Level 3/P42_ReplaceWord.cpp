// P42_ReplaceWord.
#include <string>
#include <iostream>
using namespace std;

string ReplaaceWordInstringUsingBuildInFunction(string St, string StringToReplace, string ReplaceString)
{
	short pos = St.find(StringToReplace);
	while (pos != string::npos)
	{
		St = St.replace(pos, StringToReplace.length(), ReplaceString);
		pos = St.find(StringToReplace);//Find Next StringToReplace.
	}
	return St;
}
int main()  
{
	string St = "Welcome to Yemen, Yemen is a great Country.";

	cout << "Original String: " << St;
	cout << "\n\nAfter Replace: \n";
	cout << ReplaaceWordInstringUsingBuildInFunction(St, "Yemen", "KSA");

	system("pause>0");
}