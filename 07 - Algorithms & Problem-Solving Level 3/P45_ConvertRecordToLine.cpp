// P45_ConvertRecordToLine
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct stClient
{
    string AccountNum, Name, PhoneNum, PinCode;
    float AccountBal;
};
string ConvertRecordToLine(stClient Client, string seperator = "#//#")
{
    string ClientInLine = "";

    ClientInLine += Client.AccountNum + seperator;
    ClientInLine += Client.PinCode + seperator;
    ClientInLine += Client.Name + seperator;
    ClientInLine += Client.PhoneNum + seperator;
    ClientInLine += to_string(Client.AccountBal);

    return ClientInLine;

}

stClient ReadClientInfo()
{
    stClient Client;
   
    cout << "Account Number: ";
    getline(cin, Client.AccountNum);
 
    cout << "PIN Code: ";
    getline(cin, Client.PinCode);

    cout << "Client Name: ";
    getline(cin, Client.Name);

    cout << "Client Phone Number: ";
    getline(cin, Client.PhoneNum);

    cout << "Account Balance: ";
    cin >> Client.AccountBal;

    return Client;
}
int main()
{
    stClient Client;

    cout << "Please Enter Client Data: \n\n";
    Client = ReadClientInfo();

    cout << "Client Record For Seving is: \n";
    cout << ConvertRecordToLine(Client);

    system("pause>0");

}
