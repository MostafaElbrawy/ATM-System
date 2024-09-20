#pragma once
#include <iostream>
#include "clsPerson.h"
#include <vector>
#include <fstream>
#include"clsString.h"
#include <string>
#include "clsUtil.h"
using namespace std;

const short _Key = 2;
class clsBankClient : public clsPerson
{
private:

	static clsBankClient _GetEmptyClient()
	{
		return clsBankClient(EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsBankClient _ConvertDataLineToClientObject(string Line ,string separator = "#//#")
	{
		vector <string> vClientData = clsString::Split(Line, separator);

		return clsBankClient(UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
			vClientData[4],clsUtil::DecryptText(vClientData[5] , _Key ),stod(vClientData[6]));
	}

	string _ConvertClientObjectToDataLine(clsBankClient Client, string separator = "#//#")
	{
		return Client._FirstName + separator + Client._LastName + separator + Client._Email + separator + Client._Phone + separator +
			Client._AccountNumber + separator +clsUtil::EncryptText(Client._Pincode , _Key) + separator +to_string(Client._Balance);
	}

	vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;
		fstream file;
		file.open("Clients.txt", ios::in);
		
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				if (line != "")
					vClients.push_back(_ConvertDataLineToClientObject(line));
			}

			file.close();				

		}
		return vClients;
	}

	void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	{
		fstream file;
		file.open("Clients.txt", ios::out);
		if (file.is_open())
		{
			for (const clsBankClient& Client : vClients)
			{
				if(!Client._MarkedForDelete)
					file << _ConvertClientObjectToDataLine(Client) << '\n';
			}

		}
		file.close();


	}

	void _Update()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();
		for (clsBankClient& Client : vClients)
		{
			if (Client._AccountNumber == this->_AccountNumber)
			{
				Client = *this;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
	}

	enum enMode { EmptyMode = 0, UpdateMode = 1/*, AddNewNode = 2*/ };

	string _AccountNumber;
	string _Pincode;
	double _Balance;
	enMode _Mode;
	bool _MarkedForDelete = false;

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string Pincode, double Balance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_Pincode = Pincode;
		_Balance = Balance;
	}

	bool IsEmpty()
	{
		return (_Mode == EmptyMode);
	}

	string getAccountNumber()
	{
		return _AccountNumber;
	}

	__declspec(property(get = getAccountNumber))string AccountNumber;

	void setPincode(string Pincode)
	{
		_Pincode = Pincode;
		_Update();
	}

	string getPincode()
	{
		return _Pincode;
	}

	_declspec (property(put = setPincode, get = getPincode))string Pincode;

	void setBalance(double Balance)
	{
		_Balance = Balance;
	}

	double getBalance()
	{
		return _Balance;
	}

	__declspec(property(put = setBalance, get = getBalance))double Balance;


	static clsBankClient Find(string AccountNumber)
	{
		fstream file;
		file.open("Clients.txt", ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				clsBankClient Client = _ConvertDataLineToClientObject(line);
				if (Client._AccountNumber == AccountNumber)
				{
					file.close();
					return Client;
				}
			}
			file.close();
			return _GetEmptyClient();

		} 

	}

	static clsBankClient Find(string AccountNumber ,string Pincode)
	{
		fstream file;
		file.open("Clients.txt", ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				clsBankClient Client = _ConvertDataLineToClientObject(line);
				if (Client._AccountNumber == AccountNumber && Client._Pincode == Pincode)
				{
					file.close();
					return Client;
				}
			}
			file.close();
			return _GetEmptyClient();

		}

	}

	static bool IsClientExists(string AccountNumber)
	{
		return !Find(AccountNumber).IsEmpty();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _Balance || Amount < 1)
			return false;

		_Balance -= Amount;
		_Update();
		return true;
	}

	void Deposit(double Amount)
	{
		_Balance += Amount;
		_Update();
	}


};

