#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"

class clsAddNewClientScreen:protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAccuntNumber : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";																			

	}
	static void _ReadClient(clsBankClient& Client)
	{
		cout << "Please Enter First Name: \n";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "Enter Last Name: \n";
		Client.LastName = clsInputValidate::ReadString();
		cout << "Enter Email: \n";
		Client.Email = clsInputValidate::ReadString();
		cout << "Enter Phone Number: \n";
		Client.Phone = clsInputValidate::ReadString();
		cout << "Enter PinCode: \n";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "Enter Account Balance: \n";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

	}
public:

	static void	ShowAddNewClientScreen()
	{
		_DrawScreenHeader("\t Add New Client Screen");

		cout << "Please Enter Account Number:\n";

		string AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account NumberAlrady Used! Choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClient(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:

		case clsBankClient::enSaveResults::svSucceeded:
			cout << "\nAccount Updated Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		case clsBankClient::enSaveResults::svSaveFialdEmptyObject:
			cout << "\nErorr account was not saved it's Empty";
			break;
		}
	}
	
};

