#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsMainScreen.h"
#include<iomanip>
using namespace std;







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

int main()
{
	clsMainScreen::ShowMainMenue();
	cout << endl;
	system("pause");
	return 0;
}