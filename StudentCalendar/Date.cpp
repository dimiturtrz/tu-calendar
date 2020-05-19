#include "Date.h"

Date::Date(int year, Month month, int day): year(year), month(month), day(day) {}

int Date::getYear() {
	return year;
}

Date::Month Date::getMonth() {
	return month;
}

int Date::getDay() {
	return day;
}

void Date::setYear(int year) {
	this->year = year;
}

void Date::setMonth(Month month) {
	this->month = month;
}

void Date::setDay(int day) {
	this->day = day;
}

void Date::print(std::ostream& out) const {
	out << day<< "/"<< month<< "/"<< year;
}

Date Date::operator-(const Date& other) const {
	int year = this->year - other.year;
	int month = this->month - other.month;
	int day = this->day - other.day;

	if (day < 0) {
		day += 30;
		--month;
	}

	if (month < 0) {
		month += 12;
		--year;
	}

	return Date(year, Month(month), day);
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
	date.print(out);
	return out;
}
