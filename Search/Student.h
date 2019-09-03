#pragma once
#include <iostream>
#include "Header.h"
#include <string>
using namespace std;

class Date
{
protected:
	int Day, Month, Year;
public:

	int Get_Day() const
	{
		return this->Day;
	}

	int Get_Month() const 
	{
		return this->Month;
	}

	int Get_Year() const
	{
		return this->Year;
	}

	void Put_Day(const int& Day)
	{
		this->Day = Day;
	}

	void Put_Month(const int &Month)
	{
		this->Month = Month;
	}

	void Put_Year(const int &Year)
	{
		this->Year = Year;
	}

	Date(int Day = 0, int Month = 0, int Year = 0)
	{
		this->Day = Day;
		this->Month = Month;
		this->Year = Year;
	}

	const bool operator == (const Date &d2)
	{
		int number1 = this->Get_Day() + 100 * (this->Get_Month()) + 10000 * (this->Get_Year());
		int number2 = d2.Get_Day() + 100 * (d2.Get_Month()) + 10000 * (d2.Get_Year());
		return number1 == number2;
	}

	const bool operator < (const Date &d2)
	{
		int number1 = this->Get_Day() + 100 * (this->Get_Month()) + 10000 * (this->Get_Year());
		int number2 = d2.Get_Day() + 100 * (d2.Get_Month()) + 10000 * (d2.Get_Year());
		return number1 < number2;
	}

	const bool operator > (const Date &d2)
	{
		int number1 = this->Get_Day() + 100 * (this->Get_Month()) + 10000 * (this->Get_Year());
		int number2 = d2.Get_Day() + 100 * (d2.Get_Month()) + 10000 * (d2.Get_Year());
		return number1 > number2;
	}
};

class Student
{
protected:
	string Name, SeName, Patronymic, GroupNumber;
	Date date;
	int flag;
public:
	string Get_Name() const
	{
		return this->Name;
	}

	string Get_SeName() const
	{
		return this->SeName;
	}

	string Get_Patronymic() const
	{
		return this->Patronymic;
	}

	string Get_GroupNumber() const
	{
		return this->GroupNumber;
	}

	Date Get_Date() const
	{
		return this->date;
	}

	void Put_Name(const string &Name)
	{
		this->Name = Name;
	}

	void Put_SeName(const string &SeName)
	{
		this->SeName = SeName;
	}

	void Put_Patronymic(const string &Patronymic)
	{
		this->Patronymic = Patronymic;
	}

	void Put_GroupNumber(const string &GroupNumber)
	{
		this->GroupNumber = GroupNumber;
	}

	void Put_Date(const Date &Date)
	{
		this->date = Date;
	}

	void Put_Flag(const int &flag1)
	{
		flag = flag1;
	}

	Student(string Name="", string SeName ="", string Patronymic = "", string GroupNumber = "", Date date = Date(0,0,0), int flag = 0)
	{
		this->Name = Name;
		this->SeName = SeName;
		this->Patronymic = Patronymic;
		this->GroupNumber = GroupNumber;
		this->date = date;
		this->flag = flag;
	}

	const bool operator == (const Student &st)
	{
		if (flag == 0)
			return this->Get_Name() == st.Get_Name();
		if (flag == 1)
			return this->Get_SeName() == st.Get_SeName();
		if (flag == 2)
			return this->Get_Patronymic() == st.Get_Patronymic();
		if (flag == 3)
			return this->Get_GroupNumber() == st.Get_GroupNumber();
		if (flag == 4)
			return this->Get_Date() == st.Get_Date();
	}

	const bool operator > (const Student &st)
	{
		if (flag == 0)
			return this->Get_Name() > st.Get_Name();
		if (flag == 1)
			return this->Get_SeName() > st.Get_SeName();
		if (flag == 2)
			return this->Get_Patronymic() > st.Get_Patronymic();
		if (flag == 3)
			return this->Get_GroupNumber() > st.Get_GroupNumber();
		if (flag == 4)
			return this->Get_Date() > st.Get_Date();
	}

	const bool operator < (const Student &st)
	{
		if (flag == 0)
			return this->Get_Name() < st.Get_Name();
		if (flag == 1)
			return this->Get_SeName() < st.Get_SeName();
		if (flag == 2)
			return this->Get_Patronymic() < st.Get_Patronymic();
		if (flag == 3)
			return this->Get_GroupNumber() < st.Get_GroupNumber();
		if (flag == 4)
			return this->Get_Date() < st.Get_Date();
	}


};



ostream& operator<<(ostream& os,const Date &date)
{
	os << date.Get_Day() << '/' << date.Get_Month() << '/' << date.Get_Year();
	return os;
}

istream& operator>>(istream& is, Date &date)
{

	int day, month, year;
	cout << "Enter the day" << endl;
	is >> day;
	cout << "Enter the month" << endl;
	is >> month;
	cout << "Enter the year" << endl;
	is >> year;
	date.Put_Day(day);
	date.Put_Month(month);
	date.Put_Year(year);
	return is;
}

ostream& operator<<(ostream& os,const Student &student)
{
	os << "Name: " << student.Get_Name() << endl;
	os << "SeName: " << student.Get_SeName() << endl;
	os << "Patronymic: " << student.Get_Patronymic() << endl;
	os << "Group: " << student.Get_GroupNumber() << endl;
	os << "Date of birth: ";
	Date date = student.Get_Date();
	os << date << endl;
	return os;
}

istream& operator>>(istream& is, Student &student)
{
	string name, sename, patronymic, group;
	Date date;
	cout << "Enter the name" << endl;
	is >> name;
	cout << "Enter the sename" << endl;
	is >> sename;
	cout << "Enter the patronymic" << endl;
	is >> patronymic;
	cout << "Enter the group number" << endl;
	is >> group;
	cout << "Enter the date of birth" << endl;
	is >> date;
	student.Put_Name(name);
	student.Put_SeName(sename);
	student.Put_Patronymic(patronymic);
	student.Put_GroupNumber(group);
	student.Put_Date(date);
	return is;
}