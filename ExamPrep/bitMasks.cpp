#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef unsigned int uint;

void printBits(uint num, uint mask = (1 << 31)) {
	if (mask == 1) {
		cout << (bool)(num & mask) << endl;		
	} else {
		cout << (bool)(num & mask);
		printBits(num, (mask >> 1));
	}
}

int main() {
	uint num;
	cout << "Enter whole positive number: ";
	cin >> num;

	printBits(num);

	int test; 
	cout << "Programs has ended: ";
	cin >> test;

	return 0;
}