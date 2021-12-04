#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ostream>
using namespace std;

class Date
{
public:
	Date();
	Date(int day, int month, int year);
	friend ostream& operator << (ostream& out, const Date& date);
	Date& operator= (const Date& right);
	Date& operator++ ();
private:
	int _day;
	int _month;
	int _year;
	void ShiftDate31();
};

