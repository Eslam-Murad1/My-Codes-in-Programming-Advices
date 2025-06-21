// P46_ConvertLineToRecord
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct stClient
{
    string AccountNum, Name, PhoneNum, PinCode;
    float AccountBal;
};
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
stClient ConvertLineToRecord(string Line, string seperator)
{
    vector <string> vClientData = SplitString(Line, seperator);
    stClient sClient;

    sClient.AccountNum = vClientData[0];
    sClient.PinCode = vClientData[1];
    sClient.Name = vClientData[2];
    sClient.PhoneNum = vClientData[3];
    sClient.AccountBal = stod(vClientData[4]);

    return sClient;

}

void PrintClientInfo(stClient Client)
{
    cout << "Account Number     : " << Client.AccountNum<<endl;

    cout << "PIN Code           : " << Client.PinCode << endl;

    cout << "Client Name        : " << Client.Name << endl;

    cout << "Client Phone Number: " << Client.PhoneNum << endl;

    cout << "Account Balance    : " << Client.AccountBal << endl;

}
int main()
{
    string ClientLine = "2003#//#2345#//#Eslam Murad#//#779513#//#20000";
    cout << "The line Record is: " << ClientLine << endl;

    cout << "\nClient Record For Saving is: \n\n";
    PrintClientInfo(ConvertLineToRecord(ClientLine, "#//#"));

    system("pause>0");

}
