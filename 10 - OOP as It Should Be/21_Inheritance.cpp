// 21_Inheritance
// 19_PersonExercise.cpp 

#include <iostream>
#include<iomanip>
using namespace std;

class clsPerson
{
private:
	int _ID;
	string _FName, _LName, _Email, _PhoneNum;
public:
	clsPerson(int ID, string FName, string LName, string Email, string Phone)
	{
		_ID = ID;
		_FName = FName;
		_LName = LName;
		_Email = Email;
		_PhoneNum = Phone;
	}

	int ID() { return _ID; }

	void setFName(string FName) { _FName = FName; }
	string FName() { return _FName; }
	__declspec(property(get = FName, put = setFName)) string FirstName;

	void setLName(string LName) { _LName = LName; }
	string LName() { return _LName; }
	__declspec(property(get = LName, put = setLName)) string LastName;

	void setEmail(string Email) { _Email = Email; }
	string getEmail() { return _Email; }
	__declspec(property(get = getEmail, put = setEmail)) string Email;

	void setPhoneNum(string Number) { _PhoneNum = Number; }
	string getPhoneNum() { return _PhoneNum; }
	__declspec(property(get = getPhoneNum, put = setPhoneNum)) string PhoneNum;

	string FullName() { return _FName + _LName; }

	void Print()
	{
		cout << "\tPerson Information" << endl;
		cout << "_______________________________________\n";
		cout << "ID           : " << _ID << endl;
		cout << "First Name   : " << _FName << endl;
		cout << "Last Name    : " << _LName << endl;
		cout << "Full Name    : " <<  FullName() << endl;
		cout << "Email        : " << _Email << endl;
		cout << "Phone Number : " << _PhoneNum << endl;
		cout << "_______________________________________\n";
	}

	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe following message sent successfullt to email: " << _Email << endl;
		cout << "Subject: " << Subject << endl;
		cout << "Body:" << Body << endl;
	}

	void SendSMS(string Message)
	{
		cout << "\nThe following SMS sent successfullt to Phone Number: " << _PhoneNum << endl;
		cout << Message << endl;
	}



};
class clsEmployee : public clsPerson
{
private:
	string _Tital, _Department;
	float _Salary;

public:
	clsEmployee(int ID, string FName, string LName, string Email, string Phone, string Tital, string Depart, float Salary) :clsPerson(ID, FName, LName, Email, Phone)
	{
		_Tital = Tital;
		_Department = Depart;
		_Salary = Salary;
	}

	void setTital(string Tital) { _Tital = Tital; }
	string getTital() { return _Tital; }
	__declspec(property(get = getTital, put = setTital)) string Tital;

	void setDepartment(string Dep) { _Department = Dep; }
	string getDepartment() { return _Department; }
	__declspec(property(get = getDepartment, put = setDepartment)) string Department;

	void setSalary(float Salary) { _Salary = Salary; }
	float getSalary() { return _Salary; }
	__declspec(property(get = getSalary, put = setSalary)) float Salary;

	
	void Print()
	{
		//I can Access to Print method in class clsPerson as follow:
		//clsPerson::Print(); 

		cout << "\tPerson Information" << endl;
		cout << "_______________________________________\n";
		cout << "ID           : " << ID() << endl;
		cout << "First Name   : " << FirstName << endl;
		cout << "Last Name    : " << LastName << endl;
		cout << "Full Name    : " << FullName() << endl;
		cout << "Email        : " << Email << endl;
		cout << "Phone Number : " << PhoneNum << endl;
		cout << "Tital        : " << _Tital << endl;
		cout << "Department   : " << _Department << endl;
		cout << "Salary       : " << _Salary << endl;
		cout << "_______________________________________\n";
	}

};
int main()
{

	clsEmployee Employee1(2003, "Eslam", "Mohammed", "eslam@gmail", "7795130", "Enginer","IT",2500);

	Employee1.Print();

	Employee1.SendEmail("Work", "Finished the Project");
	Employee1.SendSMS("Helllllllo.");

	return 0;
}