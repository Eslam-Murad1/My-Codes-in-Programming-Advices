// P49_FindClientByAccountNumber
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include<string>
using namespace std;


const string ClientFileName = "ClientFile.txt";

struct stClient
{
    string AccountNum, ClientName, PhoneNum, PinCode;
    double AccountBal;
};

vector <string> SplitString(string S, string Delim)
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

stClient ConvertLineToRecord(string Line, string seperator = "#//#")
{
    vector <string> vClientData = SplitString(Line, seperator);
    stClient sClient;

    sClient.AccountNum = vClientData[0];
    sClient.PinCode = vClientData[1];
    sClient.ClientName = vClientData[2];
    sClient.PhoneNum = vClientData[3];
    sClient.AccountBal = stod(vClientData[4]);

    return sClient;

}

vector <stClient> LoadClientsDataFromFile(string FileName)
{
    vector <stClient> vClients;

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }

        MyFile.close();
    }
    return vClients;
}

string ReadAccountNumber()
{
    string AccNum;

    cout << "Enter Account Number: ";
    cin >> AccNum;
    return AccNum;
}

void PrintClientCard(stClient Client)
{
    cout << "\n\nThe following are the client details: \n\n";

    cout << "Account Number     : " << Client.AccountNum << endl;

    cout << "PIN Code           : " << Client.PinCode << endl;

    cout << "Client Name        : " << Client.ClientName << endl;

    cout << "Client Phone Number: " << Client.PhoneNum << endl;

    cout << "Account Balance    : " << Client.AccountBal << endl;
}

bool FindClientByAccountNumber(string AccountNumber, stClient& Client)
{
    vector <stClient> vClients = LoadClientsDataFromFile(ClientFileName);

    for (stClient C : vClients)
    {
        if (C.AccountNum == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}


int main()
{
    stClient Client;
    string AccNum = ReadAccountNumber();

    if (FindClientByAccountNumber(AccNum, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "Client with The Account Number (" << AccNum << ") Not Found!";
    }

    system("pause>0");
    return 0;
}