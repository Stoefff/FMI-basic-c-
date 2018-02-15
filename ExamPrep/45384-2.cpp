/////////////////////////////////////////////////////////////
//
// Author: Юлиан Стоев
// FN: 45384
// Program: Информатика
// Grade: 1
// Task: 1
// Variant: А
// Date: 13.02.2018
//

#include <iostream>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;

typedef unsigned int uint;

size_t myStrlen(const char * str){ // Recursive strlen
	if(*str == '\0'){
		return 0;
	} else {
		return 1 + myStrlen(++str);
	}
}

size_t DigitPrefixLengh(const char* str){
	char currSym = *str;
	if((currSym >= '0')&&(currSym <= '9')){ // Duno
		return 1 + DigitPrefixLengh(++str);
	} else {
		return 0;
	}
}

unsigned int myPowRecc(uint num, size_t pow){
	if(pow == 0){
		return 1;
	} else {
		return num*(myPowRecc(num, --pow));
	}
}

uint ToInt(const char* str, size_t len){
	if(*str == '\0'){ // Not nessecery, just in case
		return 0;
	} else {
		uint currNum = *str - '0'; // Gets the int
		if(len > 1 ){
			//cout << "Current number times len: " << (uint)(currNum * myPowRecc(10, len)) << endl;
			return ((uint)(currNum * myPowRecc(10, len))) + ToInt(++str, --len);
		} else { return currNum; }
	}
}

void getNumbers(char * str, uint * numbers, size_t & numCount) {
	while (*str != '\0'){
		if ((*str >= '0') && (*str <= '9')) {
			size_t len = DigitPrefixLengh(str);
			if (len  < 10) {
				numbers[numCount++] = ToInt(str, len);
			}
			str += (len - 1);
		}
		str++;
	}
}

int main(){
	char str[80];
	uint numbers[80];
	size_t numCount = 0;
	uint numSum = 0;

	cout << "Enter string: ";
	cin.getline(str, 80);

	cout << "Entered string: " <<  str << endl;

	//cout << "Degital Prefix Length: " << DigitPrefixLengh(str) << endl;
	//cout << "To int: " << ToInt(str, myStrlen(str)) <<endl;

	getNumbers(str, numbers, numCount);

	cout << "Numbers found: " << numCount << endl;
	for (int i = 0; i < numCount; i++) {
		cout << numbers[i] << endl;
		numSum += numbers[i];
	}
	cout << "Sum of all the numbers: " << numSum << endl;

	int test;
	cin >> test;
	cout << test << endl;

	return 0;
}