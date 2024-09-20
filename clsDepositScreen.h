#pragma once
#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsInputValidate.h"
using namespace std;
class clsDepositScreen : protected clsScreen
{
	static double _ReadAmount()
	{
		cout << "\nEnter Amount to Deposit: ";
		double Amount;
		Amount = clsInputValidate::ReadPositiveNumber<double>("Invalid Amount, Enter Anohter: ");
		return Amount;
	}

public:
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t   Deposit Screen");

		double Amount = _ReadAmount();

		cout << "\nAre You Sure You Want To Perform This Deposit(y/n): ";
		char sure;
		cin >> sure;
		if (sure == 'y' || sure == 'Y')
		{
			CurrentClient.Deposit(Amount);
			cout << "\n\nDeposit Done Successfullly, New Balance is " << CurrentClient.Balance;
		}
		else
			cout << "\n\nDeposit Cancelled";
	}



};

