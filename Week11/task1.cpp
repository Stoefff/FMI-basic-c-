#include <iostream>

bool isAlpha(char & sym){
    return (sym >= 'a' && sym <= 'z') ||
            (sym >= 'A' && sym <= 'Z' )
            ? true : false;
}

bool isDigit(char sym){
    return (sym >= '0' && sym <= '1') ? true : false;
}

void toUpper(char * str){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 'a' - 'A';
        }
    }
}

void toLower(char * str){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 'a' - 'A';
        }
    }
}

void changeSpSymbol(char * str, char changeThis, char changeWithThat){
    for(int i = 0; str[i] != '\0'; i++){
        if (str[i] == changeThis){
            str[i] = changeWithThat;
        }
    }
}

int atoi(const char * str){
    size_t size = 0;
    int result = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(!isDigit(str[i])) {
                return -1;
        }
        size++;
    }

    int pow10 = 1;
    for(int i = size-1; i >= 0; i--){
        result += pow10*(str[i] - '0');
        pow10 *= 10;
    }
    return result;
    //Paco solution is starting from pow of 10 of lenght - 1
}

bool isPolinrom(const char * str){
    size_t size = 0;
    for(int i = 0; str[i] != '\0'; i++){
        size++;
    }
    for(int i = 0, j = size - 1; i < (size/2); i++, j++){
        if(str[i]!=str[j]) return false;
    }
    return true;
}

int main(){

    return 0;
}
