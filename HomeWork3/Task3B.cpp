// Compiled with g++ 5.4.0 on Ubuntu 16.04 64 bit
// Using "g++ -std=c++11 Bitmap.cpp" so the header could compile
#include <iostream>
#include<ctime>
#include<random>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;

const char * words[] = { "apple", "orange", "month", "vehicle" };
const unsigned int wordsCount = 4;
const size_t allowedMistakes = 5;

size_t strlen(const char * str) {
	size_t length = 0;
	while (*str != '\0') {
		length++;
		str++;
	}
	return length;
}

void printMistakes(size_t mistakes) {
	cout << "[" << mistakes << "/" << allowedMistakes << "] ";
}

void printHiddenWord(char * hiddenWord, size_t wordLength) {
	for (int i = 0; i < wordLength; i++) {
		cout << hiddenWord[i] << " ";
	}
}
void printHistory(char * history, size_t historyLength) {
	cout << " History: ";
	for (int i = 0; i < historyLength; i++) {
		cout << history[i] << " ";
	}
	cout << endl;
}

bool isGuessed(char * hiddenWord, size_t wordLength) {
	for (int i = 0; i < wordLength; i++) {
		if (hiddenWord[i] == '_') return false;
	}
	return true;
}

int main() {
	srand(time(0));
	size_t mistakes = 0;
	const char * word = words[rand() % wordsCount];
	size_t wordLength = strlen(word);
	size_t historyLength = allowedMistakes + wordLength;
	bool guessed = false;
	char letter;
	bool letterGuessed = false;

	char * hiddenWord = new(std::nothrow) char[wordLength + 1];
	char * history = new(std::nothrow) char[historyLength + 1];
	if ((!hiddenWord) || (!history)) {
		cout << "Allocation fail!" << endl;
		return -1;
	}

	char * historyPointer = history;

	for (int i = 0; i <= wordLength; i++) {
		hiddenWord[i] = '_';
		if (i == wordLength) hiddenWord[i] = '\0';
	}

	cout << "Guess the word (max " << allowedMistakes << " mistales):" << endl;

	while ((guessed == false) && (allowedMistakes != mistakes)) {
		printMistakes(mistakes);
		printHiddenWord(hiddenWord, wordLength);
		printHistory(history, historyLength);
		cout << "Choose a letter: ";
		cin >> letter;
		for (int i = 0; i < wordLength; i++) {
			if (word[i] == letter) {
				hiddenWord[i] = letter;
				letterGuessed = true;
			}
		}
		if (letterGuessed == true) {
			cout << "OK " << endl << endl;
		}
		else {
			mistakes++;
			cout << "No such letter: " << letter << endl << endl;
		}
		*historyPointer = letter;
		historyPointer++;
		guessed = isGuessed(hiddenWord, wordLength);
		letterGuessed = false;
	}
	if (guessed == true) {
		cout << "You win!!!" << endl
			<< "The word was: " << word << endl;
	}
	else {
		cout << "You lose :(" << endl
			<< "The word was: " << word << endl;
	}

	delete[] hiddenWord;
	delete[] history;

	return 0;
}
