#pragma once
#include <iostream>
#include "clsDate.h"
#include "Global.h"
using namespace std;
class clsScreen
{

protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t___________________________________";
		cout << "\n\n\t\t\t\t\t" << Title;

		if (SubTitle != "")
			cout << "\n\t\t\t\t\t" << SubTitle;

		cout << "\n\t\t\t\t\t___________________________________\n\n";

		cout << "\t\t\t\t\tBalance = " << CurrentClient.Balance;
		cout << "\n\t\t\t\t\tDate: " << clsDate().ToString() << endl;
	}

};

