#include <iostream>
#include<ctime>
#include<random>

using std::cin;
using std::cout;
using std::endl;

size_t strlen(const char * str){
    size_t length = 0;
    while(*str != '\0'){
        length++;
        str++;
    }
    return length;
}

void printMistakes(size_t mistakes, size_t allowedMistakes){
    cout << "[" << mistakes << "/" << allowedMistakes << "] ";
}

void printHiddenWord(char * hiddenWord, size_t wordLength){
    for(int i = 0; i < wordLength; i++){
        cout << hiddenWord[i] << " ";
    }
}
void printHistory(char * history, size_t allowedMistakes){
    cout << " History: ";
    for(int i = 0; i < allowedMistakes; i++){
        cout << history[i] << " ";
    }
    cout << endl;
}

bool isGuessed(char * hiddenWord, size_t wordLength){
    for(int i = 0; i < wordLength; i++){
        if(hiddenWord[i] == '_') return FALSE;
    }
    return TRUE;
}

int main(){
    srand(time(0));
    const char * words[] = { “apple”, “orange”, “month”, “vehicle” };
    const unsigned int wordsCount = 4;
    size_t allowedMistakes = 5;
    size_t mistakes = 0;
    const char * word = words[rand() % wordsCount];
    size_t wordLength = strlen(word);
    bool guessed = false;
    char letter;
    bool letterGuessed = false;

    char * hiddenWord = new(std::nothrow) char[wordLength + 1];
    char * history = new(std::nothrow) char[allowedMistakes + 1];
    if((!hiddenWord)||(!history)){
        cout << "Allocation fail!" << endl;
        return -1;
    }
    char * historyPointer = history;

    for(int i = 0; i <= wordLength; i++){
        hiddenWord[i] = '_';
        if(i == wordLength) hiddenWord[i] == '\0';
    }

    cout << "Guess the word (max " << allowedMistakes << " mistales):" << endl;

    while((guessed == false)&&(allowedMistakes != mistakes)){
        printMistakes(mistakes, allowedMistakes);
        printHiddenWord(hidden_word, word_length);
        printHistory(history, allowedMistakes);
        cout << "Choose a letter: ";
        cin << letter;
        for(int i = 0; i < wordLength; i++){
            if(word[i] == letter){
                hiddenWord[i] = letter;
                letterGuessed = TRUE;
            }
        }
        if(letterGuessed == TRUE){
            cout << "OK " << endl;
        } else{
            mistakes++;
            cout << "No such letter: " << letter << endl;
        }
        *historyPointer = letter;
        historyPointer++;
        guessed = isGuessed();
        letterGuessed = FALSE;
    }

    if(guessed == true){
        cout << "You win!!!"
            <<endl
            << "The word was: "
            << word
            <<endl;
    }else{
        cout << "You lose :("
            << endl
            << "The word was: "
            << word
            <<endl;
    }

    delete [] hiddenWord;
    delete [] history;

    return 0;

}
