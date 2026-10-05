#pragma once
#include<iostream>
using namespace std;
class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _PhoneNumber;
public:
	clsPerson(string FirstName, string LastName, string Email, string PhoneNumber)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_PhoneNumber = PhoneNumber;
	}
	//set property
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	//get property
	string GetFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	//set property
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	//get property
	string GetFirstName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	//set property
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	//get property
	string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	//set property
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	//get property
	string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	//set property
	void SetPhoneNumber(string PhoneNumber)
	{
		_PhoneNumber = PhoneNumber;
	}
	//get property
	string GetPhoneNumber()
	{
		return _PhoneNumber;
	}
	__declspec(property(get = GetPhoneNumber, put = SetPhoneNumber)) string PhoneNumber;


};