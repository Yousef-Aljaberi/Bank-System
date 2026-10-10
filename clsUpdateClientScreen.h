#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsUpdateClientScreen:protected clsScreen
{private:
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

	static void ShowUpdateClientScreen()
	{
		_DrawScreenHeader("\t Update Client Screen");

		cout << "Please enter account number: \n";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client Not Foune!.	Please Enter Another Number\n";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		char answer;

		cout << "Are you sure you want to delete this client? y/n?  ";
		cin >> answer;

		if (answer == 'y'||answer=='Y')
		{
			cout << "\n\nUpdate Client Info:";
			cout << "\n____________________\n";

			_ReadClient(Client);

			clsBankClient::enSaveResults SaveResult = Client.Save();

			switch (SaveResult)
			{
			case clsBankClient::enSaveResults::svSucceeded:
				cout << "\nAccount Updated Successfully :-)\n";
				_PrintClient(Client);
				break;

			case clsBankClient::enSaveResults::svSaveFialdEmptyObject:
				cout << "\nErorr account was not saved it's Empty";
				break;
			}
		}


	}


};

