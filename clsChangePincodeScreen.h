#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;
class clsChangePincodeScreen : protected clsScreen
{
private:
	static string _ReadPincode(string Massage)
	{
		string Pincode;
		cout << Massage;
		Pincode = clsInputValidate::ReadString();
		return Pincode;
	}


public :
	static void ShowChangePincodeScreen()
	{
		_DrawScreenHeader("\tChange Pincode Screen");
		string NewPincode = _ReadPincode("\nEnter New Pincode: ");
		string ConfirmedPincode = _ReadPincode("\nConfirm Pincode: ");

		while (NewPincode != ConfirmedPincode)
		{
	    	cout << "\n\nThe new PIN and the confirmation PIN do not match. Please try again.\n";
		     NewPincode = _ReadPincode("\nEnter New Pincode: ");
		     ConfirmedPincode = _ReadPincode("\nConfirm Pincode: ");
		}
		
		cout << "\n\nAre you sure do you want to change pincode (y/n): ";
		char sure;
		cin >> sure;
		if (sure == 'y' || sure == 'Y')
		{
			CurrentClient.Pincode = NewPincode;
			cout << "\n\nPicode Changed Succefully";
		}
		else
			cout << "\n\nPincode Was Not Changed";
	}

};

