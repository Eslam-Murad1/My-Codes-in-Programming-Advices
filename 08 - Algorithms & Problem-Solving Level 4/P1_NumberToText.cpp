// P1_NumberToText
#include <iostream>
#include <string>
using namespace std;

long int ReadNumber()
{
    int Number;

    cout << "Enter the Number?";
    cin >> Number;
    return Number;
}

string NumberToText(int num)
{
    if (num == 0)
    {
        return "Ziro";
    }

    else if (num >= 1 && num <= 19)
    {
        string arr[] = { "", "One", "Tow","Three","Four","Five", "Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fiveteen","Sixteen","Seventeen","Eighteen","Nineteen" };

        return arr[num];
    }

    else if (num >= 20 && num <= 99)
    {
        string arr[] = { "","","Twenty","Thirty" ,"Fourty","Fifty","Sixty","Seventy","Eighty","Ninety" };

        //To Dailling with Ziro.
        if (num % 10 != 0)
        {
            return arr[num / 10] + " " + NumberToText(num % 10);
        }
        else
        {
            return arr[num / 10];
        }
    }

    else if (num >= 100 && num <= 999)
    {
        if (num % 100 != 0)
        {
            return NumberToText(num / 100) + " Hundred " + NumberToText(num % 100);
        }
        else
        {
            return NumberToText(num / 100) + " Hundred ";
        }
    }

    else if (num >= 1000 && num <= 999999)
    {
        if (num % 1000 != 0)
        {
             return NumberToText(num / 1000) + " Thousand " + NumberToText(num % 1000);
        }
        else
        {
            return NumberToText(num / 1000) + " Thousand ";
        }
    }

    else if (num >= 1000000 && num <= 999999999)
    {
        if (num % 1000000 != 0)
        {
            return NumberToText(num / 1000000) + " Million " + NumberToText(num % 1000000);
        }
        else
        {
            return NumberToText(num / 1000000) + " Million ";
        }
    }

   /* else if (num >= 1000000000 && num <= 1999999999)
    {
        if (num % 1000000000 != 0)
        {
            return NumberToText(num / 1000000000) + " Billion " + NumberToText(num & 1000000000);
        }
        else
        {
            return NumberToText(num / 1000000000) + " Billion ";
        }
    }*/
    else if (num >= 1000000000 && num <= 1999999999)
    {
        return "One Billion " + NumberToText(num % 1000000000);
    }
    
    else
    {
        return NumberToText(num / 1000000000) + " Billion " + NumberToText(num & 1000000000);
    }
}
int main()
{
    int Number = ReadNumber();

    cout << NumberToText(Number);
    
    return 0;
}