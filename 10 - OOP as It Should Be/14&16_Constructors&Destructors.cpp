// 14&16_Constructors&Destructors
#include <iostream>
#include <string>
using namespace std;

class clsAddress
{
private: 
    int _AdressNum;
    string _Street;
    string _AdressName;
    string _PoBox;

public:

    //Constructor
    clsAddress(string Street)
    {
        cout << "Hi, I'm Contructor.\n";
        _Street = Street;
    }
    string Street() { return _Street; }

    //Get and Set properties with throught =.
    void setAdressNum(int Num) { _AdressNum = Num; }
    int getAdressNum(){ return _AdressNum; }
    __declspec(property(get = getAdressNum, put = setAdressNum)) int AdressNum;

    void setAdressName(string Name) { _AdressName = Name; }
    string getAdressName() { return _AdressName; }
    __declspec(property(get = getAdressName, put = setAdressName)) string AdressName;

    void setPoBox(string Box) { _PoBox = Box; }
    string getPoBox() { return _PoBox; }
    __declspec(property(get = getPoBox, put = setPoBox)) string PoBox;



    //Destructor
    ~clsAddress()
    {
        cout << "Hi, I'm Destructor.\n";
    }
    
};

//This Fun to see the destructor when destroy the object.
void Fun()
{
    clsAddress Ad("0");
}

int main()
{
    //Fun();

    clsAddress Ad1("Wordl1"), Ad2("world2");

    cout << Ad1.Street() << endl;
    Ad1.AdressName = "Ms.Dr1";
    cout << Ad1.AdressName << endl;;


    cout << Ad2.Street() << endl;
    Ad2.AdressName = "Ms.Dr2";
    cout << Ad2.AdressName << endl;

    system("pause>0");
    return 0;
}