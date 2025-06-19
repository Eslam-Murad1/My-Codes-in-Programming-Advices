// BankProjectWithExtension

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include<string>
using namespace std;

const string ClientFileName = "ClientsFile.txt";

enum enAction { eShowClient = 1, eAddClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5, eTransactions = 6, Exit = 7 };
enum enTransacetionsAction { eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eMainMenue = 4 };

void ShowMainScreen();
void GoBackToMainScreen();
void ShowTransactionsScreen();
void PreformTransactionOption(enTransacetionsAction Choice);

struct stClient
{
    string AccountNum, ClientName, PhoneNum, PinCode;
    double AccountBalance;
    bool MarkForDelete = false;
};

string ReadAccountNumber()
{
    string AccNum;

    cout << "Please, Enter Account Number: ";
    cin >> AccNum;
    return AccNum;
}
short ReadMenueOption(string  Quetion)
{
    short Answer;

    cout << Quetion << endl;
    cin >> Answer;
    return Answer;
}

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
    sClient.AccountBalance = stod(vClientData[4]);

    return sClient;

}

string ConvertRecordToLine(stClient Client, string seperator = "#//#")
{
    string ClientInLine = "";

    ClientInLine += Client.AccountNum + seperator;
    ClientInLine += Client.PinCode + seperator;
    ClientInLine += Client.ClientName + seperator;
    ClientInLine += Client.PhoneNum + seperator;
    ClientInLine += to_string(Client.AccountBalance);

    return ClientInLine;

}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{

    vector <stClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            if (Client.AccountNum == AccountNumber)
            {
                MyFile.close();
                return true;
            }
            vClients.push_back(Client);
        }

        MyFile.close();

    }
    return false;
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

stClient ReadNewClientInfo()
{
    stClient Client;
    vector <stClient> vClients = LoadClientsDataFromFile(ClientFileName);

    cout << "Enter Account Number: ";
    //Usge of std::ws will extract all the whitespace character.
    getline(cin >> ws, Client.AccountNum);

    while (ClientExistsByAccountNumber(Client.AccountNum, ClientFileName))
    {
        cout << "\nClient with [" << Client.AccountNum << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNum);
    }


    cout << "Enter PIN Code: ";
    getline(cin, Client.PinCode);

    cout << "Enter Client Name: ";
    getline(cin, Client.ClientName);

    cout << "Enter Client Phone Number: ";
    getline(cin, Client.PhoneNum);

    cout << "Enter Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
}

void PrintClientRecord(stClient Client)
{
    cout << "| " << setw(20) << left << Client.AccountNum;
    cout << "| " << setw(15) << left << Client.PinCode;
    cout << "| " << setw(35) << left << Client.ClientName;
    cout << "| " << setw(15) << left << Client.PhoneNum;
    cout << "| " << setw(15) << left << Client.AccountBalance;
    cout << "\n";
}

void PrintClientBalances(stClient Client)
{
    cout << "| " << setw(20) << left << Client.AccountNum;
    cout << "| " << setw(35) << left << Client.ClientName;
    cout << "| " << setw(15) << left << Client.AccountBalance;
    cout << "\n";
}

void PrintAllClientData()
{
    vector <stClient> vClients = LoadClientsDataFromFile(ClientFileName);

    cout << "--------------------------------------------------------------------------------------------------------------\n\n";
    cout << "\t\t\t\t\tClient List: " << vClients.size() << " Client(s)            \n";
    cout << "\n--------------------------------------------------------------------------------------------------------------\n";
    cout << "| " << left << setw(20) << "Account Number";
    cout << "| " << left << setw(15) << "PIN Code";
    cout << "| " << left << setw(35) << "Client Name";
    cout << "| " << left << setw(15) << "Phone Number";
    cout << "| " << left << setw(15) << "Balance";
    cout << "\n--------------------------------------------------------------------------------------------------------------\n";

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
        for (stClient Client : vClients)
        {
            PrintClientRecord(Client);
        }
    cout << "--------------------------------------------------------------------------------------------------------------\n";

}

void TotalBalances()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientFileName);
    stClient sClients;


    cout << "--------------------------------------------------------------------------------------------------------------\n\n";
    cout << "\t\t\t\t\tClient List: " << vClients.size() << " Client(s)            \n";
    cout << "\n--------------------------------------------------------------------------------------------------------------\n";
    cout << "| " << left << setw(20) << "Account Number";
    cout << "| " << left << setw(35) << "Client Name";
    cout << "| " << left << setw(15) << "Balance";
    cout << "\n--------------------------------------------------------------------------------------------------------------\n";

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
    {
        int BalancesSum = 0;
        for (stClient& Client : vClients)
        {
            PrintClientBalances(Client);
            //cout << endl;
            BalancesSum += Client.AccountBalance;

        }
        cout << "--------------------------------------------------------------------------------------------------------------\n";
        cout << "\t\t\t\t\t Total Balances: " << BalancesSum << endl;
    }
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details: \n";
    cout << "--------------------------------------\n";
    cout << "| Account Number     : " << Client.AccountNum << endl;
    cout << "| PIN Code           : " << Client.PinCode << endl;
    cout << "| Client Name        : " << Client.ClientName << endl;
    cout << "| Client Phone Number: " << Client.PhoneNum << endl;
    cout << "| Account Balance    : " << Client.AccountBalance << endl;
    cout << "--------------------------------------\n";

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

    cout << "Enter PIN Code: ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Client Name: ";
    getline(cin, Client.ClientName);

    cout << "Enter Phone Number: ";
    getline(cin, Client.PhoneNum);

    cout << "Enter Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient>& vClient)
{
    for (stClient& C : vClient)
    {
        if (C.AccountNum == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

vector <stClient> SaveClientsDataToFile(string FileName, vector <stClient>& vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (stClient C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

void AddDataLineToFile(string FileName, string DataLine)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << DataLine << endl;

        MyFile.close();
    }

}

void AddNewClient()
{
    stClient Client;
    Client = ReadNewClientInfo();
    AddDataLineToFile(ClientFileName, ConvertRecordToLine(Client));

}

void AddNewClients()
{
    char AddMore = 'Y';
    do
    {
        cout << "Adding New Client:\n\n";
        AddNewClient();

        cout << "\n--> Client Adding Successfully, Do you want to add more client: (Y OR y)\n\n";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}

void DeleteClientByAccounNumber(string AccountNumber, vector <stClient>& vClient)
{
    stClient Client;
    char AnswerDelete = 'N';

    if (FindClientByAccountNumber(AccountNumber, vClient, Client))
    {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want to delet this record? (Y/N)\n";
        cin >> AnswerDelete;

        if (AnswerDelete == 'Y' || AnswerDelete == 'y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClient);
            SaveClientsDataToFile(ClientFileName, vClient);

            //Refresh Vector.
            vClient = LoadClientsDataFromFile(ClientFileName);

            cout << "--> Client Delete Successfully.";
        }
        else
        {
            cout << "OK, the Record doesn't deleted.";
        }
    }
    else
    {
        cout << "Client with The Account Number (" << AccountNumber << ") Not Found!";
    }


}

bool UpdateClientByAccountNumber(string AccountNum, vector <stClient>& vClients)
{
    stClient Client;
    char AnswerUpdate = 'N';

    if (FindClientByAccountNumber(AccountNum, vClients, Client))
    {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want to update this Client? (Y/N) ? ";
        cin >> AnswerUpdate;

        if (AnswerUpdate == 'Y' || AnswerUpdate == 'y')
        {
            for (stClient& C : vClients)
            {
                if (C.AccountNum == AccountNum)
                {
                    C = ChangeClientRecord(AccountNum);
                    break; //break exit from loop just, but return exet from all method;
                }
            }
            SaveClientsDataToFile(ClientFileName, vClients);

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

void WithdrawFromBalanceByAccountNumber(vector <stClient>& vClients, stClient& sClient)
{
    string AccountNumber;
    int WithdrawAmount = 0;
    char AnswerWithdraw;
    do
    {
        AccountNumber = ReadAccountNumber();

        if (FindClientByAccountNumber(AccountNumber, vClients, sClient))
        {
            PrintClientCard(sClient);
            cout << "\n Please, Enter withdraw amount: ";
            cin >> WithdrawAmount;
            while (WithdrawAmount > sClient.AccountBalance)
            {
                cout << "Amount Exceeds the balance, you can withdraw up to : " << sClient.AccountBalance << endl;
                cout << "\nPlease, Enter another amount : ";
                cin >> WithdrawAmount;
            }
            cout << "\nAre you sure you want perform this transaction: (Y/N) ?";
            cin >> AnswerWithdraw;
            if (AnswerWithdraw == 'Y' || AnswerWithdraw == 'y')
            {
                for (stClient& C : vClients)
                {
                    if (C.AccountNum == AccountNumber)
                    {
                        C.AccountBalance -= WithdrawAmount;
                        cout << "--> Done Successfully, New Balance is: " << C.AccountBalance;
                        break;
                    }
                }
                SaveClientsDataToFile(ClientFileName, vClients);

            }
        }
        else
        {
            cout << "Client with this Account Number [" << AccountNumber << "] does not exist.\n\n";
        }

    } while (!FindClientByAccountNumber(AccountNumber, vClients, sClient));
}

void DepositBalanceByAccountNumber(vector <stClient>& vClients, stClient& sClient)
{
    string AccountNumber;
    double DepositAmount = 0;
    char AnswerDeposit;
    do
    {
        AccountNumber = ReadAccountNumber();

        if (FindClientByAccountNumber(AccountNumber, vClients, sClient))
        {
            PrintClientCard(sClient);
            cout << "\n Please, Enter deposit amount: ";
            cin >> DepositAmount;

            cout << "\nAre you sure you want perform this transaction: (Y/N) ?";
            cin >> AnswerDeposit;
            if (AnswerDeposit == 'Y' || AnswerDeposit == 'y')
            {
                for (stClient& C : vClients)
                {
                    if (C.AccountNum == AccountNumber)
                    {
                        C.AccountBalance += DepositAmount;
                        cout << "--> Done Successfully, New Balance is: " << C.AccountBalance;
                        break;
                    }
                }
                SaveClientsDataToFile(ClientFileName, vClients);
            }
        }
        else
        {
            cout << "Client with this Account Number [" << AccountNumber << "] does not exist.\n";
        }

    } while (!FindClientByAccountNumber(AccountNumber, vClients, sClient));

}

void ShowDipostScreen()
{
    vector <stClient> vClients = LoadClientsDataFromFile(ClientFileName);
    stClient sClient;

    cout << "----------------------------------------\n";
    cout << "\t  Deposit Screen\n";
    cout << "----------------------------------------\n\n";

    DepositBalanceByAccountNumber(vClients, sClient);

    cout << "\n\nPress any key to go back to Transaction Screen...";
    system("pause>0");
}
void ShowWithdrawScreen()
{
    vector <stClient> vClients = LoadClientsDataFromFile(ClientFileName);
    stClient sClient;

    cout << "----------------------------------------\n";
    cout << "\t  Withdraw Screen\n";
    cout << "----------------------------------------\n\n";

    WithdrawFromBalanceByAccountNumber(vClients, sClient);

    cout << "\n\nPress any key to go back to Transaction Screen...";
    system("pause>0");
}
void ShowTotalBalanceeList()
{
    TotalBalances();
    cout << "\n\nPress any key to go back to Transaction Screen...";
    system("pause>0");
}
void ShowClientsListScreen()
{
    PrintAllClientData();
}
void ShowAddClientsScreen()
{
    cout << "----------------------------------------\n";
    cout << "\t  Add New Client Screen\n";
    cout << "----------------------------------------\n";
    AddNewClients();
}
void ShowDeleteClientScreen()
{

    cout << "----------------------------------------\n";
    cout << "\t  Delet Client Screen\n";
    cout << "----------------------------------------\n";

    vector <stClient> vClients = LoadClientsDataFromFile(ClientFileName);
    string AccountNum = ReadAccountNumber();
    DeleteClientByAccounNumber(AccountNum, vClients);
}
void ShowUpdateClientScreen()
{
    cout << "----------------------------------------\n";
    cout << "\t  Update Client Screen\n";
    cout << "----------------------------------------\n";

    vector <stClient> vClients = LoadClientsDataFromFile(ClientFileName);
    string AccountNum = ReadAccountNumber();
    UpdateClientByAccountNumber(AccountNum, vClients);
}
void ShowFindClientScreen()
{
    cout << "----------------------------------------\n";
    cout << "\t  Find Client Screen\n";
    cout << "----------------------------------------\n";

    vector <stClient> vClients = LoadClientsDataFromFile(ClientFileName);
    stClient sClient;
    string AccNum = ReadAccountNumber();
    if (FindClientByAccountNumber(AccNum, vClients, sClient))
    {
        PrintClientCard(sClient);
    }
    else
    {
        cout << "Client with The Account Number (" << AccNum << ") Not Found!";
    }
}
void ShowTransactionsScreen()
{
    system("cls");
    cout << "========================================\n";
    cout << "\t  Transactions Screen\n";
    cout << "========================================\n";
    cout << "\t[1] Deopsit." << endl;
    cout << "\t[2] Withdraw." << endl;
    cout << "\t[3] Total Balances." << endl;
    cout << "\t[4] Main Menue." << endl;
    cout << "========================================\n";
    PreformTransactionOption((enTransacetionsAction)ReadMenueOption("Choose What do you want to do? (1 to 4):"));
}
void ShowEndScreen()
{
    cout << "----------------------------------------\n";
    cout << "\t  Program End X﹏X\n";
    cout << "----------------------------------------\n";
}
void GoBackToMainScreen()
{
    cout << "\n\nPress any key to go back to Main Screen...";
    system("pause>0");
    ShowMainScreen();
}

void PreformTransactionOption(enTransacetionsAction Choice)
{
    switch (Choice)
    {
    case eDeposit:
    {
        system("cls");
        ShowDipostScreen();
        ShowTransactionsScreen();
        break;
    }
    case eWithdraw:
    {
        system("cls");
        ShowWithdrawScreen();
        ShowTransactionsScreen();
        break;
    }
    case eTotalBalances:
    {
        system("cls");
        ShowTotalBalanceeList();
        ShowTransactionsScreen();
        break;
    }
    break;
    case eMainMenue:
    {
        system("cls");
        ShowMainScreen();
        break;
    }
    }
}
void PerfromMainMenueOption(enAction Choice)
{
    switch (Choice)
    {
    case enAction::eShowClient:
    {
        system("cls");
        ShowClientsListScreen();
        GoBackToMainScreen();
        break;
    }

    case enAction::eAddClient:
    {
        system("cls");
        ShowAddClientsScreen();
        GoBackToMainScreen();
        break;
    }

    case enAction::eDeleteClient:
    {
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainScreen();
        break;
    }

    case enAction::eUpdateClient:
    {
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainScreen();
        break;
    }

    case enAction::eFindClient:
    {
        system("cls");
        ShowFindClientScreen();
        GoBackToMainScreen();
        break;
    }

    case enAction::eTransactions:
    {
        system("cls");
        ShowTransactionsScreen();
        break;
    }
    case enAction::Exit:
    {
        system("cls");
        ShowEndScreen();
        break;
    }
    }
}

void ShowMainScreen()
{
    system("cls");
    cout << "========================================\n";
    cout << "\t  Main Menue Start\n";
    cout << "========================================\n";
    cout << "\t[1] Show Client List." << endl;
    cout << "\t[2] Add New Client." << endl;
    cout << "\t[3] Delet Client." << endl;
    cout << "\t[4] Update Client." << endl;
    cout << "\t[5] Find Client." << endl;
    cout << "\t[6] Transaction Menue." << endl;
    cout << "\t[7] Exit." << endl;
    cout << "========================================\n";

    PerfromMainMenueOption((enAction)ReadMenueOption("Choose What do you want to do ? (1 to 7) : "));
}

int main()
{
    ShowMainScreen();

    system("pause>0");
    return 0;
}