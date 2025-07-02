#pragma once
#include<iostream>
using namespace std;
class clsPerson
{
private:
	string _ID, _FName, _LName, _Email, _PhoneNum;
public:
	clsPerson(string ID, string FName, string LName, string Email, string Phone)
	{
		_ID = ID;
		_FName = FName;
		_LName = LName;
		_Email = Email;
		_PhoneNum = Phone;
	}

	string ID() { return _ID; }

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


	void Print()
	{
		cout << "\tPerson Information" << endl;
		cout << "_______________________________________\n";
		cout << "ID           : " << _ID << endl;
		cout << "First Name   : " << _FName << endl;
		cout << "Last Name    : " << _LName << endl;
		cout << "Full Name    : " << _FName << " " << _LName << endl;
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