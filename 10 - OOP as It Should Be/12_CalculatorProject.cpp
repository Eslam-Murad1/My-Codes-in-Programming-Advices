// 12_CalculatorProject
#include <iostream>
using namespace std;

class clsCalculator
{
private:
    double _Result = 0;
    float _lastNumber = 0;
    string _lastOperation = "Clear";
    double _PreviousResult = 0;
    bool _IsZero(double Number)
    {
        return (Number == 0);
    }

public:
    void Clear()
    {
        _Result = 0;
        _lastOperation = "Clearing";
    }
    void Add(double num)
    {
        _lastNumber = num;
        _lastOperation = "Adding ";
        _PreviousResult = _Result;
        _Result += num;
        
    }
    void Subtract(double num)
    {
        _lastNumber = num;
        _lastOperation = "Subtracting ";
        _PreviousResult = _Result;
        _Result -= num;
        
    }
    void Multiply(double num)
    {
        _lastNumber = num;
        _lastOperation = "Multiply ";
        _PreviousResult = _Result;
        _Result *= num;
        
    }
    void Divide(double num)
    {
        _lastNumber = num;
        _lastOperation = "Dividing ";
        _PreviousResult = _Result;
        if (_IsZero(num))
        {
            _Result /= 1;
        }
        else
        {
            _Result /= num;
        }
        
    }
    void CancelTheLastOperation()
    {
        _lastNumber = 0;
        _lastOperation = "Cancaling the last Operation";
        _Result = _PreviousResult;
    }
    double GetFinalResult()
    {
        return _Result;
    }
    void PrintResult()
    {
        if (_lastOperation == "Clearing" || _lastOperation == "Cancaling the last Operation")
        {
            cout << "The result after " << _lastOperation << " is: " << _Result << endl;
        }
        else
        {
         cout << "The result after " << _lastOperation << _lastNumber << " is: " << _Result << endl;
        }
       
    }

};
int main()
{
    clsCalculator Calculator;
    Calculator.Clear();
    Calculator.PrintResult();

    Calculator.Add(10);
    Calculator.PrintResult();

    Calculator.Add(10);
    Calculator.PrintResult();

    Calculator.Divide(2);
    Calculator.PrintResult();

    Calculator.CancelTheLastOperation();
    Calculator.PrintResult();
}