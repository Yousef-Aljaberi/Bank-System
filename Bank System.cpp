#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;

void ReadClient(clsBankClient& Client)
{
	cout << "Please Enter First Name: \n";
	Client.FirstName = clsInputValidate::ReadString();
	cout << "Enter Last Name: \n";
	Client.LastName = clsInputValidate::ReadString();
	cout << "Enter Email: \n";
	Client.Email = clsInputValidate::ReadString();
	cout << "Enter Phone Number: \n";
	Client.Email = clsInputValidate::ReadString();
	cout << "Enter PinCode: \n";
	Client.PinCode = clsInputValidate::ReadString();
	cout << "Enter Account Balance: \n";
	Client.AccountBalance = clsInputValidate::ReadFloatNumber();

}

void UpdateClient()
{
	cout << "-------------------------------------------------\n";
	cout << "Please enter account number: \n";
	string AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "Client Not Foune!.	Please Enter Another Number\n";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client = clsBankClient::Find(AccountNumber);
	Client.Print();

	cout << "Update Info: \n";
	ReadClient(Client);
	clsBankClient::enSaveResults SaveResult = Client.Save();
	switch (SaveResult)
	{
	case clsBankClient::enSaveResults::enObjectSavedSuccessed:
		cout << "\nAccount Updated Successfully :-)\n";
		break;
	case clsBankClient::enSaveResults::enSaveFialdEmptyObject:
		cout << "\nErorr account was not saved it's Empty";
		break;
	}


}

int main()
{
	UpdateClient();
}