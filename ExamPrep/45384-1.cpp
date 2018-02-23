/////////////////////////////////////////////////////////////
//
// Author: ����� �����
// FN: 45384
// Program: �����������
// Grade: 1
// Task: 1
// Variant: �
// Date: 13.02.2018
//

#include <iostream>
#include <string> // Vanaka said we can use the str functions

using std::cin;
using std::cout;
using std::endl;

size_t myStrlen(const char * str){
	size_t size = 0;
	while(*str != '\0'){
		size++;
	}
	return size;
}

void getWord(char * strItt, char * buffer, size_t & buffLen) {
	while (*strItt != '\t' && *strItt != ' ' && *strItt != '\0') { // != whitespace
		buffer[buffLen++] = *strItt;
		strItt++;
	}
	buffer[buffLen] = '\0'; // bug
}
//Big problems here
bool isContained(char * word, char ** dictionary, int wordsCount) {
	for (int i = 0; i < wordsCount; i++) {
		char * dicWord = dictionary[i];
/*		if (strcmp(dicWord, word) == 0) {
			return true;
		}  */
	}
	return false;
} // fucking die

void reverseWord(char * str, char * word, size_t wordLen) {
	wordLen--;
	while (wordLen >= 0) {
		*str = word[wordLen--];
		*str++;
	}
}

int main(){

	int test;

	int wordsCount;
	cout << "Enter dictionary size: ";
	cin >> wordsCount;

	char ** dictionary = new (std::nothrow) char*[wordsCount];

	for(int i = 0; i < wordsCount; i++){
		char buffer[40];
		cout << "Enter words: ";
		cin >> buffer;
		dictionary[i] = buffer;
	}


	cout << "Dank memes: " << dictionary[2][0] << endl;

	cin.ignore();

	char str[80];
	cout << "Enter a string: ";
	cin.getline(str, 80);

	char * strItt = str;

	while (*strItt != '\0'){ // not ending
		size_t wordLen = 0;
		char word[40];
		getWord(strItt, word, wordLen);

		if (wordLen > 1){
			if (isContained(word, dictionary, wordsCount) == true) {
				reverseWord(strItt, word, wordLen);
			}
		}
		strItt += wordLen;
		while(*strItt == '\t' || *strItt == ' '){ // != whitespace
			strItt++;
		}
	}

	cout << str << endl;

	delete[] dictionary;

	cin >> test;
	cout << "Test: " << test << endl;

	return 0;
}
