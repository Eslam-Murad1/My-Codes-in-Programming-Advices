// P48_ShowAllClients
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

stClient ConvertLineToRecord(string Line, string seperator ="#//#")
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

void PrintClientRecord(stClient Client)
{
    cout << "| " << setw(20) << left << Client.AccountNum;
    cout << "| " << setw(15) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.ClientName;
    cout << "| " << setw(15) << left << Client.PhoneNum;
    cout << "| " << setw(15) << left << Client.AccountBal;
   
}

void PrintAllClientData(vector <stClient> vClients)
{
    cout << "\t\t\t\tClient List (" << vClients.size() << ")                 " << endl;
    cout << "\n--------------------------------------------------------------------------------------------------------------\n";
    cout <<"| " << left << setw(20) << "Account Number" ;
    cout <<"| " << left << setw(15) << "PIN Code" ;
    cout <<"| " << left << setw(40) << "Client Name" ;
    cout <<"| " << left << setw(15) << "Phone Number" ;
    cout <<"| " << left << setw(15) << "Balance" ;
    cout << "\n--------------------------------------------------------------------------------------------------------------\n";
    
    for (stClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    cout << "\n--------------------------------------------------------------------------------------------------------------\n";
    
}

int main()
{
    vector <stClient> vClients = LoadClientsDataFromFile(ClientFileName);
   
    PrintAllClientData(vClients);

    return 0;
}