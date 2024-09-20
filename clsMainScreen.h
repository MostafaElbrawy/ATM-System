#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsQuickWithdarwScreen.h"
#include "clsNormalWithdrawScreen.h"
#include "clsDepositScreen.h"
#include "clsChangePincodeScreen.h"
using namespace std;
class clsMainScreen : protected clsScreen
{

private:
    enum enMainMenuOptions { QuickWithdraw = 1 , NormalWithdraw =2 , Deposit =3 , ChangePincode = 4 , Logout =5 };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Enter Your Choice [1:5]: ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1,5,"\nInvalid Choice, Enter Number Between [1:5]: ");
        return Choice;
    }

    static void _ShowQuickWithdrawScreen()
    {
        clsQuickWithdarwScreen::ShowQuickWithdarwScreen();
    }

    static void _ShowNormalWithdrawScreen()
    {
        clsNormalWithdrawScreen::ShowNormalWithdrawScreen();
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowChanagePincodeScreen()
    {
        clsChangePincodeScreen::ShowChangePincodeScreen();
    }

    static void _PerformMainMenuOption(enMainMenuOptions Choice)
    {
        system("cls");

        switch (Choice)
        {
        case clsMainScreen::QuickWithdraw:

            _ShowQuickWithdrawScreen();
            break;

        case clsMainScreen::NormalWithdraw:

            _ShowNormalWithdrawScreen();
            break;

        case clsMainScreen::Deposit:

            _ShowDepositScreen();
            break;

        case clsMainScreen::ChangePincode:

            _ShowChanagePincodeScreen();
            break;

        case clsMainScreen::Logout:

            return;
            break;
   
        }

        cout<<"\n\n" << setw(37) << left << "" << "Press Any Key To Go Back To Main Menu....";
        system("pause>0");
        system("cls");
        ShowMainMenuScreen();
    }



public:

	static void ShowMainMenuScreen()
	{
        system("cls");
		_DrawScreenHeader("\t Main Menu Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t     Main Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Quick Withdraw.\n";
        cout << setw(37) << left << "" << "\t[2] Normal Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Deposit.\n";
        cout << setw(37) << left << "" << "\t[4] Change Pincode.\n";
        cout << setw(37) << left << "" << "\t[5] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOption(enMainMenuOptions(_ReadMainMenuOption()));

	}

};

