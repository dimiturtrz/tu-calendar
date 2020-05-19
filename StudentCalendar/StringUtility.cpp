#include "StringUtility.h"

int StringUtility::strlen(const char* str) {
	int len = 0;
	for (; str[len] != '\0'; ++len);
	return len;
}

void StringUtility::strcpy(char* destination, const char* source) {
	int len = 0;
	for (; source[len] != '\0'; ++len) {
		destination[len] = source[len];
	}
	destination[len] = '\0';
}
