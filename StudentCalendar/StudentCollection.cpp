#include "StudentCollection.h"

StudentCollection::StudentCollection() : data(), size(0), capacity(10) {
	data = new Student[capacity];
}

StudentCollection::StudentCollection(const StudentCollection& other): data(nullptr) {
	copyData(other);
}

StudentCollection& StudentCollection::operator=(const StudentCollection& other) {
	if (this == &other) {
		return *this;
	}

	copyData(other);
	return *this;
}

StudentCollection::~StudentCollection() {
	clearData();
}

void StudentCollection::append(const Student& newStudent) {
	if (size + 1 > capacity) {
		expand();
	}

	data[size++] = newStudent;
}

int StudentCollection::getSize() const {
	return size;
}

Student& StudentCollection::operator[](int index) {
	return data[index];
}

void StudentCollection::read(std::istream& in) {
	int studentCount = 0;
	in >> studentCount;
	reserve(studentCount * 2);
	size = studentCount;
	for (int i = 0; i < size; ++i) {
		in >> data[i];
	}
}

void StudentCollection::print(std::ostream& out) const {
	Date today(2020, Date::Month::March, 19);
	for (int i = 0; i < size; ++i) {
		int studentAge = data[i].studentAge(today);
		if (studentAge >= 18 && studentAge <= 26) {
			out << data[i]<< std::endl;
		}
	}
}

void StudentCollection::copyData(const StudentCollection& other) {
	clearData();

	capacity = other.capacity;
	size = other.size;
	data = new Student[capacity];
	for (int i = 0; i < size; ++i) {
		data[i] = other.data[i];
	}
}

void StudentCollection::clearData() {
	delete[] data;
}

void StudentCollection::expand() {
	capacity *= 2;
	Student* newData = new Student[capacity];
	for (int i = 0; i < size; ++i) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}

void StudentCollection::reserve(int newCapacity) {
	if (newCapacity < capacity) {
		return;
	}

	capacity = newCapacity;
	Student* newData = new Student[capacity];
	for (int i = 0; i < size; ++i) {
		newData[i] = data[i];
	}
}

std::istream& operator>>(std::istream& in, StudentCollection& studentCollection) {
	studentCollection.read(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const StudentCollection& studentCollection) {
	studentCollection.print(out);
	return out;
}
