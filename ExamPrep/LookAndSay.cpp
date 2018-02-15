#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char * myStrcpy(const char * source, char * dest) {
	size_t i = 0;
	while (source[i] != '\0') {
		dest[i] = source[i];
		i++;
	}
	return dest;
}

char * resizeAndPopulate(char * oldStr , char sym, int symCount, int counter) {
	char * temp = new (std::nothrow) char[counter + 1];
	if (counter != 2) {
		myStrcpy(oldStr, temp);
	}
	temp[counter - 2] = symCount + '0';
	temp[counter - 1] = sym;
	temp[counter] = '\0';

	delete[] oldStr;

	return temp;

}

char * generateLookAndSay(int level) {
	char * str = new (std::nothrow) char[2];
	if (!str) {
		cout << "Memory allocation failure" << endl;
		return __nullptr;
	}

	str[0] = '1';
	str[1] = '\0';

	while (level != 1) {
		char * strItt = str;
		int counter = 0;
		char * temp = nullptr; // always stars with 2 elems; problem when 1 !!!
		while (*strItt != '\0') {
			int symCount = 1;
			while (*strItt == *(strItt + 1)) {
				strItt++;
				symCount++;
			}
			counter += 2;
			temp = resizeAndPopulate(temp, *strItt, symCount, counter);
			strItt++;
		}
		delete[] str;
		str = temp;
		level--;
	}
	return str;
}

int main() {

	int level;
	cout << "Enter level: " << endl;
	cin >> level;

	char * seq = generateLookAndSay(level);
	if (!seq) {
		return -1;
	}

	cout << seq << endl;

	delete[] seq;

	int test;
	cout << "End enter: " << endl;
	cin >> test;

	return 0;

}