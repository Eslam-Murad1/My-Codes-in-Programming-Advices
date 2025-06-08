// P44_RemovePunctuations
#include <iostream>
#include <string>
using namespace std;

string RemovePunctuations(string st)
{
    string NewSt = "";
    for (int i = 0; i < st.length(); i++)
    {
        if (!ispunct(st[i]))
        {
            NewSt += st[i];
        }
    }
    return NewSt;
}
int main()
{
    string st = "Eslam, Murad: Abaullah... Mohammed.";

    cout << st;
    cout << endl;
    cout << RemovePunctuations(st);

    system("pause>0");
}