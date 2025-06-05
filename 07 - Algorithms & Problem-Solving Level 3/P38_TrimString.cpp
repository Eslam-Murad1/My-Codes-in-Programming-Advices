// P38_TrimString

#include <iostream>
#include <string>
using namespace std;

string TrimRight(string s)
{
	for (int i = s.length()-1; i >= 0; i--)
	{
		if (s[i] != ' ')
		{
			return s.substr(0, i+1);
		}
	}
	return "";
		
}
string TrimLeft(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
		{
			return s.substr(i, s.length()-i);
		}
	}
	return "";
}
string TrimAll(string s)
{
	return  TrimLeft(TrimRight(s));
}
int main()
{
	string St = "   Eslam Murad   ";
	cout << "The String: " << St << endl<<endl;
	cout << "Trim Right:" << TrimRight(St)<< "Sss" << endl;
	cout << "Trim Lift :" << TrimLeft(St) << "Sss" << endl;
	cout << "Trim All  :" << TrimAll(St)<<"Sss";
	

}