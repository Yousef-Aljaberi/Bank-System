#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include<iomanip>b
using namespace std;

void ReadClientInfo(clsBankClient& Client)
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
	ReadClientInfo(Client);
	clsBankClient::enSaveResults SaveResult = Client.Save();
	switch (SaveResult)
	{
	case clsBankClient::enSaveResults::svObjectSavedSuccessed:
		cout << "\nAccount Updated Successfully :-)\n";
		break;
	case clsBankClient::enSaveResults::svSaveFialdEmptyObject:
		cout << "\nErorr account was not saved it's Empty";
		break;
	}


}

void AddNewClient()
{
	
	cout << "Please Enter Account Number:\n";
	string AccountNumber = clsInputValidate::ReadString();
	while (clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "Account NumberAlrady Used! Choose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

	ReadClientInfo(NewClient);

	clsBankClient::enSaveResults SaveResult;

	SaveResult = NewClient.Save();
	switch (SaveResult)
	{
	case clsBankClient::enSaveResults::svFaildAccountNumberExists:

	case clsBankClient::enSaveResults::svObjectSavedSuccessed:
		cout << "\nAccount Updated Successfully :-)\n";
		break;
	case clsBankClient::enSaveResults::svSaveFialdEmptyObject:
		cout << "\nErorr account was not saved it's Empty";
		break;
	}
}

void PrintClientRecordLine(clsBankClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber();
	cout << "| " << left << setw(20) << Client.FullName();
	cout << "| " << left << setw(13) << Client.Phone;
	cout << "| " << left << setw(20) << Client.Email;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(12) << Client.AccountBalance;
}
void ShowClientsList()
{
	vector<clsBankClient>vClients = clsBankClient::GetClientsList();
	cout << "\n" << clsUtil::Taps(5) << "Clients List (" << vClients.size() << ") Client(s)";
	cout << "\n-----------------------------------------------------------------------";
	cout << "-------------------------\n";
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(13) << "Phone";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n-----------------------------------------------------------------------";
	cout << "-------------------------\n";
	
	if (vClients.size() == 0)
		cout << clsUtil::Taps(3) << "No Clients Available In the System!";
	else
		for (clsBankClient Client : vClients) 
		{
			PrintClientRecordLine(Client);
			cout << endl;
		}
		
	

}

void PrintClientBalanceLine(clsBankClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber();
	cout << "| " << left << setw(20) << Client.FullName();
	cout << "| " << left << setw(12) << Client.AccountBalance;
}
void ShowTotalBalances()
{
	vector<clsBankClient>vClients = clsBankClient::GetClientsList();
	cout << "\n" << clsUtil::Taps(5) << "Clients List (" << vClients.size() << ") Client(s)";
	cout << "\n-----------------------------------------------------------------------";
	cout << "-------------------------\n";
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n-----------------------------------------------------------------------";
	cout << "-------------------------\n";

	double TotalBalances= clsBankClient::GetTotalBalance();
	if (vClients.size() == 0)
		cout << clsUtil::Taps(3) << "No Clients Available In the System!";
	else
	{
		for (clsBankClient Client : vClients)
		{
			PrintClientBalanceLine(Client);
			cout << endl;
		}
		cout << "\n-----------------------------------------------------------------------";
		cout << "-------------------------\n";
		cout << clsUtil::Taps(3) << "Total Balances: " << TotalBalances << endl;
		cout << clsUtil::Taps(3) <<" ( " << clsUtil::NumberToText(TotalBalances)<<" )";
	}

}
void DeleteClient()
{
	cout << "Please Enter Account Number: ";
	string AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount Number is Not Found, choose another one:  ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client = clsBankClient::Find(AccountNumber);
	Client.Print();
	char answer;
	cout << "Are you sure you want to delete this client? y/n?  ";
	cin >> answer;
	if (tolower(answer) == 'y')
	{
		if (Client.Delete())
		{
			cout << "\nClient Deleted Successfully :-)" << endl;
			Client.Print();
		}
		else
		{
			cout << "\n Error Client Was not Deleted\n";
		}
	}
	
}
int main()
{
	ShowTotalBalances();
	cout << endl;
	system("pause");
	return 0;
}