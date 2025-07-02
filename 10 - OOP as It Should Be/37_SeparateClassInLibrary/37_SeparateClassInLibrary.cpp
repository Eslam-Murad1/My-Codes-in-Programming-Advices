
#include <iostream>
#include<iomanip>
#include "clsPerson.h"
#include "clsEmployee.h"
using namespace std;

int main()
{
	clsPerson Person1("2003", "Eslam", "Mohammed", "1eslam.murad@gmail.com", "0096777951302");

	Person1.Print();
	Person1.SendEmail("Hello", "I love Programming.");
	Person1.SendSMS("Hi Eslam.");

	cout << "\n\n\tSecond Class with overriding\n";
	clsEmployee Employee1(2003, "Eslam", "Mohammed", "1eslam.murad@gmail.com", "0096777951302", "Software engineering", "IT", 120.5);
	Employee1.Print();
	Employee1.SendEmail("Work", "Finished the Project");

	return 0;
}