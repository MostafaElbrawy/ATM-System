#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"

using namespace std;
class clsQuickWithdarwScreen : protected clsScreen
{

	static short _GetChoice()
	{
		cout << setw(37) << left << "" << "Enter Amount Of Withdraw[1:9]: ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1,9,"\nInvalid Choice, Enter Number Between[1:9]: ");

		if (Choice == 9)
			return -1;
		short Amounts[] = { 20,50,100,200,400,600,800,1000 };
		return Amounts[Choice-1];

	}

public:
	static void ShowQuickWithdarwScreen()
	{
		_DrawScreenHeader("\tQuick Withdraw Screen");

		cout<< setw(37) << left << ""<< "=====================================\n";
		cout<< setw(37) << left << ""<< "\t\tQuick Withdraw\n";
		cout<< setw(37) << left << ""<< "=====================================\n";
		cout<< setw(37) << left << ""<< "\t\t[1] 20    [2]50\n";
		cout<< setw(37) << left << ""<< "\t\t[3] 100   [4]200\n";
		cout<< setw(37) << left << ""<< "\t\t[5] 400   [6]600\n";
		cout<< setw(37) << left << ""<< "\t\t[7] 800   [8]1000\n";
		cout<< setw(37) << left << ""<< "\t\t[9] Exit\n";
		cout<< setw(37) << left << ""<< "=====================================\n";

		short Amount = _GetChoice();

		if (Amount == -1)
			return;

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

