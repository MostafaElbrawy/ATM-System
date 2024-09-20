#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"

using namespace std;
class clsNormalWithdrawScreen : protected clsScreen
{
	static double _ReadAmount()
	{
		double Amount;

		cout << "\nEnter Amount Multiple of 5's: ";
		Amount = clsInputValidate::ReadPositiveNumber<double>("\nInvalid Amount, Enter Another Amount Mulitple of 5's: ");

		while (int(Amount) % 5 != 0 || Amount > CurrentClient.Balance)
		{
			if (Amount > CurrentClient.Balance)
			{
				cout << "\nAmount Exceeds Balance, Enter Another Amount Mulitple of 5's: ";
		    }else
				cout << "\nInvalid Amount, Enter Amount Multiple of 5's: ";

			Amount = clsInputValidate::ReadPositiveNumber<double>("\nInvalid Amount, Enter Another Amount Mulitple of 5's: ");

		} 

		return Amount;
	}

public:
	static void ShowNormalWithdrawScreen()
	{
		_DrawScreenHeader("       Normal Withdraw Screen");

		double Amount = _ReadAmount();

		cout << "\nAre You Sure You Want To Perform This Withdraw(y/n): ";
		char sure;
		cin >> sure;
		if (sure == 'y' || sure == 'Y')
		{
			if (CurrentClient.Withdraw(Amount))
				cout << "\n\nWithdraw Done Successfully, New Balance is " << CurrentClient.Balance;
			else
				cout << "\n\nWithdraw Failed";
		}
		else
			cout << "\n\nWithdraw Cancelled";

	}
	
};

