// P40_JoinString(Overloading)

#include <iostream>
#include <string>
#include <vector>

using namespace std;


string JoinString(vector<string> words, string Delim)
{
    string St = "";

    for (string& s : words)
    {
        St = St + s + Delim;
    }
    return St.substr(0, St.length() - Delim.length()) + ".";
}
string JoinString(string arr[], string Delim, short arrLenght) // OverLoading function
{
    string St = "";

    for (int i = 0; i < arrLenght; i++)
    {
        St = St + arr[i] + Delim;
    }
    return St.substr(0, St.length() - Delim.length());
}
int main()
{
    vector<string> vSt = { "Eslam","Ahmed","Ali","Mohammed" };
    string arrSt[] = {"Eslam","Ahmed","Ali","Mohammed"};

    cout << "Vector after joing:\n";
    cout << JoinString(vSt, ", ");
    
    cout << "\n\nArray after joing:\n";
    cout << JoinString(arrSt," ",4);

    system("pause>0");
}

