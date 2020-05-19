#pragma once

#include <iostream>

class Date {
public:
	enum Month {
		January = 1, February, March, April, May, June,
		July, August, September, October, November, December
	};

	Date(int year = 2020, Month month = January, int day = 1);

	int getYear();
	Month getMonth();
	int getDay();

	void setYear(int year);
	void setMonth(Month month);
	void setDay(int day);

	void print(std::ostream& out) const;

	Date operator-(const Date& other) const;

private:
	int year;
	Month month;
	int day;
};

std::ostream& operator<<(std::ostream& out, const Date& date);