// P51_UpdateClientByAccountNumber
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
    bool MarkForDelete;
};

vector <string> SplitString(string S, string Delim)
{
    vector <string> vSt;

    short pos = 0;
    string sWord;

    while ((pos = S.find(Delim)) != string::npos)
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

string ConvertRecordToLine(stClient Client, string seperator = "#//#")
{
    string ClientInLine = "";

    ClientInLine += Client.AccountNum + seperator;
    ClientInLine += Client.PinCode + seperator;
    ClientInLine += Client.ClientName + seperator;
    ClientInLine += Client.PhoneNum + seperator;
    ClientInLine += to_string(Client.AccountBal);

    return ClientInLine;

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

void PrintClientCard(stClient Client)
{
    cout << "\n\nThe following are the client details: \n\n";

    cout << "Account Number     : " << Client.AccountNum << endl;

    cout << "PIN Code           : " << Client.PinCode << endl;

    cout << "Client Name        : " << Client.ClientName << endl;

    cout << "Client Phone Number: " << Client.PhoneNum << endl;

    cout << "Account Balance    : " << Client.AccountBal << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClients, stClient& Client)
{
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

stClient ChangeClientRecord(string AccountNumber)
{
    stClient Client;

    Client.AccountNum = AccountNumber;

    cout << "Enter PIN Code:";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Client Name:";
    getline(cin, Client.PhoneNum);

    cout << "Enter Phone Number: ";
    getline(cin, Client.PhoneNum);

    cout << "Enter Account Balance: ";
    cin >> Client.AccountBal;

    return Client;
}

vector<stClient> SaveClientDataToFile(string FileName, vector <stClient> vClient)
{
    fstream MyFile;
    string DataLine;

    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
        for (stClient C : vClient)
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClient;
}

bool UpdateClientByAccountNumber(string AccountNum, vector <stClient>& vClients)
{
    stClient Client;
    char Answer = 'N';

    if (FindClientByAccountNumber(AccountNum, vClients, Client))
    {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want to update this Client? (Y/N) ? ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            for (stClient& C : vClients)
            {
                if (C.AccountNum == AccountNum)
                {
                    C = ChangeClientRecord(AccountNum);
                    break; //break exet from loop just, but return exet from all method;
                }
            }
            SaveClientDataToFile(ClientFileName, vClients);
            
            cout << "\nClient updated Successfully.";
            return true;
        }
        
    }
    else
    {
        cout << "Client with The Account Number (" << AccountNum << ") Not Found!";
        return false;
    }


}

string ReadAccountNumber()
{
    string AccNum;

    cout << "Enter Account Number: ";
    cin >> AccNum;
    return AccNum;
}

int main()
{
    vector <stClient> vClient = LoadClientsDataFromFile(ClientFileName);
    string AccNum = ReadAccountNumber();

    UpdateClientByAccountNumber(AccNum, vClient);

    system("pause>0");
    return 0;
}