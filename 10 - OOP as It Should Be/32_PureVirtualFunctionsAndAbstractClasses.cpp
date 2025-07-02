// 32_PureVirtualFunctionsAndAbstractClasses

#include <iostream>
using namespace std;

//Abstract Class / Interface / Contract
class clsMobile
{
public:
    virtual void Dial(string PhoneNumber) = 0;
    virtual string SendSMS(string Text) = 0;
    virtual void TakePicture() = 0;
     int Sum(int x, int y)
    {
        return x + y;
    }
};

class clsSamsung : public clsMobile
{
public:
    void Dial(string PhoneNumber)
    {
        cout << "Dial: " << PhoneNumber << endl;
    }
    string SendSMS(string Text)
    { 
        return Text;
    }

    void TakePicture()
    {
        cout << "Chit.";
    }

    void Call(int Number)
    {
        cout << "Calling " << Number << endl;
    }

};

int main()
{
    clsSamsung Note10;
    cout << Note10.SendSMS("Hello") << endl;
    Note10.Call(77951);

    return 0;
}
