#pragma once
#include "Date.h"

class Student {
public:
	Student(const char* name = "", int fn = 0, Date birthdate = Date(), float averageGrade = 0);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	void setName(const char* name);
	void setFN(int fn);
	void setBirthdate(Date birthdate);
	void setAverageGrade(float averageGrade);

	const char* getName();
	int getFN();
	Date getBirthDate();
	float getAverageGrade();

	int studentAge(const Date& referenceDate);

	void read(std::istream& in);
	void print(std::ostream& out) const;

private:
	char* name;
	int fn;
	Date birthdate;
	float averageGrade;

	void copyData(const Student& other);
	void clearData();
};

std::istream& operator>>(std::istream& in, Student& student);
std::ostream& operator<<(std::ostream& out, const Student& student);




