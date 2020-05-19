// StudentCalendar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Date.h"
#include "Student.h"
#include "StudentCollection.h"

using namespace std;

int main() {
	ifstream testFileStream("../test.txt");

	StudentCollection studentCollection;
	testFileStream>> studentCollection;
	cout << studentCollection;

	testFileStream.close();
}
