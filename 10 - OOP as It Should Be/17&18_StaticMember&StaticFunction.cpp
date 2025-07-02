// 17&18_StaticMember&StaticFunction

#include <iostream>
#include <string>
using namespace std;


class clsA
{

public: 

    int NotNumStatic= 10;
    static int NumStatic;
    static string StringStatic;

    clsA()
    {
        NumStatic++;
    }

    void print()
    {
        cout << "Static Number: " << NumStatic << endl;
        cout << "Not Static Number: " << NotNumStatic << endl;
        cout << "Static Strign: " << StringStatic << endl;
    }

    static void Fun1(char Word[])
    {
        /*return 90;*/
        printf("Hi %s, I'm Static Function. \n",Word);
    }

    static int Fun2(int Num)
    {
        return NumStatic + Num;
    }

};
int clsA::NumStatic = 0;
string clsA::StringStatic = "Hi";

int main()
{
    //for Using printf formating.
    char Word[] = "Eslam";

    clsA A1, A2;

    A1.NumStatic = 50;
    A1.print();
    cout << clsA::NumStatic << endl;

   clsA::Fun1(Word);
   cout << clsA::Fun2(50) << endl;
   A1.Fun1(Word);

    system("pause>0");
    return 0;
}