// P41_ReverseWords

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

    while ((pos = S.find(Delim)) != string::npos) //ex. 5(" ") != npos
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
string ReverseString(string St)
{
    vector <string> vSt;
    string RevSt = "";

    vSt = SplitString(St, " ");

    //Vector Pointer.
    vector <string>::iterator iter = vSt.end();

    while (iter != vSt.begin())
    {
        --iter;
        RevSt += *iter + " ";
    }
    return RevSt;
}

//MyWay
/*string ReverseString(string st)
{
    string word = "", RevSt;

    for (int i = 0; i <= st.length(); i++)
    {
        if (st[i] == ' ' || i == st.length())
        {
            RevSt.insert(0, word);
            RevSt.insert(0, " ");
            word = "";
        }
        else
            word += st[i];
    }
    return RevSt;
}*/
int main()
{
    string St = ReadString();
    cout << "The Normal String: " << St << endl;

    cout << "Reverse String:\n";
    cout << ReverseString(St);

    system("pause>0");
}

