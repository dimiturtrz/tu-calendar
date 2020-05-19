#include "Student.h"
#include "StringUtility.h"

Student::Student(const char* name, int fn, Date birthdate, float averageGrade): 
	name(nullptr), fn(fn), birthdate(birthdate), averageGrade(averageGrade) {
	setName(name);
}

Student::Student(const Student& other): name(nullptr) {
	copyData(other);
}

Student& Student::operator=(const Student& other) {
	if (&other == this) {
		return *this;
	}

	copyData(other);
}

Student::~Student() {
	clearData();
}

void Student::setName(const char* name) {
	delete[] this->name;
	this->name = new char[StringUtility::strlen(name) + 1];
	StringUtility::strcpy(this->name, name);
}

void Student::setFN(int fn) {
	this->fn = fn;
}

void Student::setBirthdate(Date birthdate) {
	this->birthdate = birthdate;
}

void Student::setAverageGrade(float averageGrade) {
	this->averageGrade = averageGrade;
}

const char* Student::getName() {
	return name;
}

int Student::getFN() {
	return fn;
}

Date Student::getBirthDate() {
	return birthdate;
}

float Student::getAverageGrade() {
	return averageGrade;
}

int Student::studentAge(const Date& referenceDate) {
	return (referenceDate - birthdate).getYear();
}

void Student::print(std::ostream& out) const {
	out << name << " " << fn << " " << birthdate << " " << averageGrade;
}

void Student::copyData(const Student& other) {
	setName(other.name);
	setFN(other.fn);
	setBirthdate(other.birthdate);
	setAverageGrade(other.averageGrade);
}

void Student::clearData() {
	delete[] name;
	name = nullptr;
}

std::ostream& operator<<(std::ostream& out, const Student& student) {
	student.print(out);
	return out;
}
