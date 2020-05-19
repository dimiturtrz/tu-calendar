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

Student& StudentCollection::operator[](int index) {
	return data[index];
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
