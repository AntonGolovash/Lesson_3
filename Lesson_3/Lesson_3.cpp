#include <iostream>
#include <sstream>
#include <string>
#include <ostream>
#include "Date.h"
using namespace std;

int main()
{
	Date date(3, 5, 2021);
	cout << date << endl;
	Date date1;

	date1 = date;
	cout << "Date1:" << endl;
	cout << date1 << endl;

	Date date3(31, 12, 2005);
	++date3;
	cout << date3 << endl;
}

