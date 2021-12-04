#include "Date.h"

ostream& operator << (ostream& out, const Date& date)
{
    out << "dd:mm:yyyy\n";
    if (date._day < 10 && date._day > 0)
        out << "0" + to_string(date._day) << ":";
    if (date._day >= 10)
        out << date._day << ":";
    if (date._month < 10 && date._month > 0)
        out << "0" + to_string(date._month) << ":";
    if (date._month >= 10)
        out << date._month << ":";
    if (date._year >= 2000)
        out << to_string(date._year);
    return out;
}

Date::Date()
{
    _day = 1;
    _month = 1;
    _year = 2000;
    cout << "Constructor default:\t" << endl;
}

Date::Date(int day, int month, int year)
{
    _day = day;
    _month = month;
    _year = year;
}

Date& Date::operator= (const Date& right)
{
    cout << "Operator = \t" << endl;
    if (this == &right)
        return *this;
    _day = right._day;
    _month = right._month;
    _year = right._year;

    return *this;
}

Date& Date::operator++()
{
    cout << "Operator ++ prefix" << endl;
    ++_day;
    _month++;
    +_year;
    ShiftDate31();
    return *this;
}

void Date::ShiftDate31()
{
    if (_day <= 1)
        while (_day <= 1) { _day += 31; _month--; }
    if (_month <= 1)
        while (_month <= 1) { _month += 12; _year--; }
    if (_day >= 31)
        while (_day >= 31) { _day -= 31; _month++; }
    if (_month >= 12)
        while (_month >= 12) { _month -= 12; _year++; }
    if (_day <= 0) _day = 1;
    if (_month <= 0) _month = 1;
    if (_year <= 2000) _year = 2000;
}
