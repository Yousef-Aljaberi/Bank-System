#pragma once
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include<fstream>

class clsBankClient:public clsPerson
{
private:
	enum enMode { EmptyMode = 1, UpdateMode = 2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string PhoneNumber, string AccountNumber, string PinCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, PhoneNumber) 
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}


};

