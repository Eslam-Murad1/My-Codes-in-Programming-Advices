// P47_AddClientToFile

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const string ClientFileName = "ClientFile.txt";
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

void AddingDataLineToFile(string FileName, string DataLine)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << DataLine << endl;

        MyFile.close();
    } 

}

stClient ReadClientInfo()
{
    stClient Client;

    cout << "Account Number: ";
    //Usge of std::ws will extract all the whitespace character.
    getline(cin  >> ws, Client.AccountNum);

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

void AddNewClient()
{
    stClient Client;
    Client = ReadClientInfo();
    AddingDataLineToFile(ClientFileName, ConvertRecordToLine(Client));

}

void AddClients()
{
    char AddMore = 'Y';
    do
    {
        system("cls");
        cout << "Adding New Client:\n";
        AddNewClient();

        cout << "\nClient Adding Successfully, Do you want to add more client: (Y OR y)\n\n";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}

int main()
{
    AddClients();

    system("pause>0");

    return 0;
}
