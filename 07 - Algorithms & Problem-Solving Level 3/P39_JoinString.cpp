// P39_JoinString

// P37_SplitString
#include <iostream>
#include <string>
#include <vector>

using namespace std;


string JoinString(vector<string> words, string Delim)
{
    string St="";

    for (string &s : words)
    {
        St = St + s + Delim;
    }
    return St.substr(0, St.length()-Delim.length()) + ".";
}
int main()
{
    vector<string> vSt = { "Eslam","Ahmed","Ali","Mohammed" };
    
    cout << "Words after joing:\n";
    cout << JoinString(vSt, ", ");

    system("pause>0");
}

