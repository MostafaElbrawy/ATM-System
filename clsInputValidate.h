#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsPeriod.h"

using namespace std;

class clsInputValidate
{
public:

	template<typename T>
	static bool IsNumberBetween(T number, T from, T to)
	{
		return (number >= from && number <= to);
	}

	static bool IsNumberBetween(short number, short from, short to)
	{
		return (number >= from && number <= to);
	}

	static bool IsNumberBetween(int number , int from , int to)
	{
		return (number >= from && number <= to);
	}

	static bool IsNumberBetween(double number, double from, double to)
	{
		return (number >= from && number <= to);
	}

	static bool IsNumberBetween(float number, float from, float to)
	{
		return (number >= from && number <= to);
	}

	static bool IsDateBetween(clsDate date , clsDate dateFrom , clsDate dateTo)
	{
		if (dateFrom.IsDateAfterDate2(dateTo))
			return IsDateBetween(date,dateTo, dateFrom);

		return clsPeriod::isDateInPeriod(clsPeriod(dateFrom, dateTo), date);

	}

	static short ReadShortNumber(string massage = "Invalid Number, Enter again: ")
	{
		short number;


		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << massage;
		}

		return number;

	}

	static short ReadShortNumberBetween(short from, short to, string massage)
	{
		short number = ReadShortNumber();

		while (!IsNumberBetween(number, from, to))
		{
			cout << massage;
			number = ReadShortNumber();
		}

		return number;
	}

	static int ReadIntNumber(string massage = "Invalid Number, Enter again: ")
	{
		int number;
		

		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << massage;
		}

		return number;

	}

	static int ReadIntNumberBetween(int from , int to ,string massage)
	{
		int number = ReadIntNumber();

		while (!IsNumberBetween(number,from ,to))
		{
			cout << massage;
			number = ReadIntNumber();
		} 

		return number;
	}

	static double ReadDblNumber(string massage = "Invalid Number, Enter again: ")
	{
		double number;

		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << massage;
		}

		return number;

	}

	static double ReadDblNumberBetween(double from, double to, string massage)
	{
		double number = ReadDblNumber();
	
		while (!IsNumberBetween(number, from, to))
		{
			cout << massage;
			number = ReadDblNumber();
		}

		return number;
	}

	static double ReadPositiveDblNumber(string massage = "Invalid Number, Enter again: ")
	{
		double number = ReadDblNumber();

		while (number < 1)
		{
			cout << massage;
			number = ReadDblNumber();
		}

		return number;
	
	}
	
	template<typename T>
	static T ReadNumber(string Massage = "Invalid Number, Enter again : ")
	{
		T Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Massage;
			
		}

		return Number;
	}
	
	template<typename T>
	static T ReadNumberBetween(T From, T To, string Massage)
	{
		T Number = ReadNumber<T>();
		while (!IsNumberBetween<T>(Number, From, To))
		{
			cout << Massage;
			Number = ReadNumber<T>();	
		}
		return Number;

	}

	template<typename T>
	static T ReadPositiveNumber(string Massage = "Invalid Number, Enter again: ")
	{
		T Number = ReadNumber<T>();
		while (Number < 1)
		{
			cout << Massage;
			Number = ReadNumber<T>();
		}
		return Number;

	}

	static string ReadString()
	{
		string s;
		getline(cin >> ws, s);
		return s;
	}

	static bool IsValidDate(clsDate date)
	{
		return clsDate::IsValidDate(date);
	}



};

