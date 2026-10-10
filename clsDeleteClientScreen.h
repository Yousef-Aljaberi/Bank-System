#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsDeleteClientScreen:protected clsScreen
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
public:
	static void ShowDeleteClientScreen()
	{
		_DrawScreenHeader("\tDelete Client Screen");
		cout << "Please Enter Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is Not Found, choose another one:  ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		char answer;
		cout << "Are you sure you want to delete this client? y/n?  ";
		cin >> answer;
		if (tolower(answer) == 'y')
		{
			if (Client.Delete())
			{
				cout << "\nClient Deleted Successfully :-)" << endl;
				_PrintClient(Client);
			}
			else
			{
				cout << "\n Error Client Was not Deleted\n";
			}
		}

	}
};

