#include <iostream>

using std::cin;
using std::cout;
using std::endl;

size_t myStrlen(char * str) {
	size_t size = 0;
	while (*str != '\0') {
		str++;
		size++;
	}
	return size;
}

char * myStrcpy(const char * source, char * dest) {
	int i = 0;
	while (source[i]) {
		dest[i] = source[i];
		i++;
	}
	// maybe add TERMINATOR zero
	return dest;
}

int myStrcom(const char * str1, const char * str2) {
	while ((*str1 != '\0') && (*str2 != '\0') && *str1 == *str2) {
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

char * myStrcat(const char * source, char * dest) {
	size_t destSize = myStrlen(dest);
	while (*source != '\0') {
		dest[destSize++] = *source++;
	}
	// maybe add TERMINATOR zero
	return dest;

}

int main() {
	int wordCount;

	cout << "Enter number of words: ";
	cin >> wordCount;

	char ** dictionary = new (std::nothrow) char*[wordCount];
	if (!dictionary) {
		cout << "Allocation failure";
		return -1;
	}

	for (int i = 0; i < wordCount; i++) {
		char buffer[40];
		cin >> buffer;
		dictionary[i] = buffer;
	}

	int rows, columns;

	cout << "Enter rows of matrix: ";
	cin >> rows;
	cout << "Enter columns of matrix: ";
	cin >> columns;

	//char matrix[rows][colums];

	return 0;
}