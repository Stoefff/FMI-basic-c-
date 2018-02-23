#include <iostream>
#include<ctime>
#include<random>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;

const char * exclams[] = { "SHOK", "Skandal", "Nechyvana naglost" };
const char * objects[] = { "Rqpa", "Baba", "Kmet", "Bager", "Sklad" };
const int isSubject[] = { 1, 1, 1, 1, 0 };
const char * actions[] = { "sgazi", "zadiga", "namiga na", "pracakva", "tarashi" };

size_t myStrlen(const char * str) {
	size_t size = 0;
	while (*str != '\0') {
		size++;
		str++;
	}
	return size;
}

char * myStrcpy(const char * source, char * destination) {
	int i = 0;
	while (source[i]) {
		destination[i] = source[i];
		i++;
	}
	return destination;
}

int myStrcom(const char * str1, const char * str2) {
	while (*str1 != '\0' && *str1 == *str2) {
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

char * myStrcat(const char * source, char * destination) {
	while (*source != '\0') { // not the standard definition but here works perfectly
		*destination++ = *source++;
	}
	return destination;
}


int main() {
	srand(time(0));
	size_t headingsCount;

	cout << "Enter number of headings: ";
	cin >> headingsCount;

	for (int i = 0; i < headingsCount; i++) {
		const char * eclamation = exclams[rand() % 3];
		int marksCount = 3 + (rand() % 8);
		int randSubject = rand() % 5;
		while (!isSubject[randSubject]) {
			randSubject = rand() % 5;
		}
		const char * subject = objects[randSubject];
		const char * action = actions[rand() % 5];
		const char * object = objects[rand() % 5];

		size_t headingSize = myStrlen(eclamation);
		headingSize += marksCount + 1; // +1 for the space
		headingSize += myStrlen(subject) + 1;
		headingSize += myStrlen(action) + 1;
		headingSize += myStrlen(object) + 1; // +1 for the zero terminator

		char * heading = new (std::nothrow) char[headingSize];
		if (!heading) {
			cout << "Allocation failure";
			return -1;
		}
		// not correct
		char * headingItterator = myStrcat(eclamation, heading);
		for (int i = 0; i < marksCount; i++) {
			*headingItterator++ = '!';
		}
		*headingItterator++ = ' ';
		headingItterator = myStrcat(subject, headingItterator);
		*headingItterator++ = ' ';
		headingItterator = myStrcat(action, headingItterator);
		*headingItterator++ = ' ';
		headingItterator = myStrcat(object, headingItterator);
		*headingItterator = '\0';

		cout << heading << endl;

		delete[] heading;
	}

	return 0;
}
