#pragma once

#include "Student.h"

class StudentCollection {
public:
	StudentCollection();
	StudentCollection(const StudentCollection& other);
	StudentCollection& operator=(const StudentCollection& other);
	~StudentCollection();

	void append(const Student& other);

	int getSize() const;

	Student& operator[](int index);

	void read(std::istream& in);
	void print(std::ostream& out) const;

private:
	Student* data;
	int size;
	int capacity;

	void copyData(const StudentCollection& other);
	void clearData();

	void expand();
	void reserve(int newCapacity);
};

std::istream& operator>>(std::istream& in, StudentCollection& studentCollection);
std::ostream& operator<<(std::ostream& out, const StudentCollection& studentCollection);

