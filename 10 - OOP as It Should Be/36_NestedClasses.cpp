#include<iostream>
using namespace std;
class clsPerson
{
private:
	string _FullName;

	class clsAddress
	{
	private:
		string _AddressLine1;
		string _AddressLine2;
		string _City;
		string _Country;
	public:
		clsAddress(string Add1, string Add2, string city, string country)
		{
			_AddressLine1 = Add1;
			_AddressLine2 = Add2;
			_City = city;
			_Country = country;
		}
		void Print()
		{
			cout << "\nAddress:\n";
			cout << _AddressLine1 << endl;
			cout << _AddressLine2 << endl;
			cout << _City << endl;
			cout << _Country << endl;
		}
	};
public:
	clsAddress Address = clsAddress("", "", "", "");


	clsPerson(string FullName, string AddressLine1, string AddressLine2, string City, string Country)
	{
		_FullName = FullName;

		//initiate address class by it's constructor 
        Address = clsAddress (AddressLine1, AddressLine2, City, Country); 
	}

	string setFullName(string FullName)
	{ _FullName = FullName; }
	string FullName() 
	{ return _FullName; }

};

int main()
{
	clsPerson Person1 ("Eslam Murad", "Building 10", "Queen Rania Street", "Amman", "Jordan");

	cout << Person1.FullName();
	Person1.Address.Print();

	return 0;
}