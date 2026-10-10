#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

class clsBankClient :public clsPerson
{
private:
	enum enMode { EmptyMode = 1, UpdateMode = 2, AddNewMode = 3 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seprator = "#//#")
	{
		vector<string>vClient = clsString::Split(Line, Seprator);
		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stod(vClient[6]));
	}
	static clsBankClient _GetEmptyObject()
	{
		return  clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	string _ConverClientObjectToLineData(clsBankClient Client, string Seprator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord = Client.FirstName + Seprator;
		stClientRecord += Client.LastName + Seprator;
		stClientRecord += Client.Email + Seprator;
		stClientRecord += Client.Phone + Seprator;
		stClientRecord += Client.AccountNumber() + Seprator;
		stClientRecord += Client.PinCode + Seprator;
		stClientRecord += to_string(Client.AccountBalance);
		return stClientRecord;
	}
	void _SaveClientsDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				if (C._MarkedForDelete == false)
				{
					string Line = _ConverClientObjectToLineData(C);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		vector<clsBankClient> vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
	}
	void _AddNewDataLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}
	void _AddNew()
	{
		_AddNewDataLineToFile(_ConverClientObjectToLineData(*this));
	}


public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string PhoneNumber, string AccountNumber, string PinCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, PhoneNumber) 
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
		_MarkedForDelete = false;
	}
	
	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
	
	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	
	
	//Find 
	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}
			MyFile.close();
		}
		return _GetEmptyObject();
	}
	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if ((Client.AccountNumber() == AccountNumber) && (Client.PinCode == PinCode)) 
				{
					MyFile.close();
					return Client;
				}

			}
			MyFile.close();
		}
		return _GetEmptyObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	static enum enSaveResults { svSaveFialdEmptyObject = 1, svSucceeded = 2, svFaildAccountNumberExists = 3 };
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			if (IsEmpty())
			{
				return enSaveResults::svSaveFialdEmptyObject;
			}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}

		case enMode::AddNewMode:
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			_AddNew();
			_Mode = enMode::UpdateMode;
			return svSucceeded;
		default:
			return enSaveResults::svSaveFialdEmptyObject;
		}
	}

	bool Delete()
	{
		vector<clsBankClient>_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}
		*this = _GetEmptyObject();
		_SaveClientsDataToFile(_vClients);
		return true;
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	//Clients List
	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	//total balance
	static float GetTotalBalance()
	{
		vector<clsBankClient>vClients= _LoadClientsDataFromFile();
		float ToatlBalance = 0;
		for (clsBankClient Client : vClients)
		{
			ToatlBalance += Client.AccountBalance;
		}

		return ToatlBalance;
	}




};

