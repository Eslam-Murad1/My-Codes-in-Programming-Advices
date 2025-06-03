// P37_SplitString
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
    string  S;
    cout << "Enter The String: ";
    getline(cin, S);

    return S;
}
vector <string>SplitString(string S, string Delim)
{
    vector <string> vSt;

    short pos = 0;
    string sWord;

    while ((pos = S.find(Delim)) != string::npos) //
    {
        sWord = S.substr(0, pos);
        if (sWord != " ")
           vSt.push_back(sWord);
        
        S.erase(0, pos + Delim.length());
    }
    if (S != "")
        vSt.push_back(S);

    return vSt;

}
int main()
{
    vector<string> vSt;
    vSt = SplitString(ReadString()," ");

    cout << "Token of String: " << vSt.size() << endl;

    for (string& s : vSt)
    {
        cout << s << endl;
    }

}