#pragma once
#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"

using namespace std;
class clsLoginScreen : protected clsScreen 
{
	static void _Login()
	{
		bool LoginFalid = false; short counter = 3;
		string AcccountNumber, Pincode;
		do
		{
			if (LoginFalid)
			{
				counter--;
				cout << "\nInvalid Acoount Number / Picode!";
				cout << "\nYou Have " << counter << " Trials\n";
			}

			if (counter == 0)
			{
				cout << "\nYou Are Locked, Contact Us To Solve The Problem\n";
				exit(0);
			}

			

			cout << "\nEnter Account Number: ";
			cin >> AcccountNumber;
			cout << "\nEnter Pincode: ";
			cin >> Pincode;

			CurrentClient = clsBankClient::Find(AcccountNumber, Pincode);

		} while (LoginFalid = CurrentClient.IsEmpty());


	}

public:

	static void ShowLoginScreen()
	{
		_DrawScreenHeader("\t    Login Screen");
		_Login();
		clsMainScreen::ShowMainMenuScreen();
	}
};

