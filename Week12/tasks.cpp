#include <iostream>

typedef unsigned int uint;

int factorLikeTail(int num) {
    if(num == 1){
        return 1;
    }
    return num * factorLikeTail(num - 1);
}

bool isPrime(int num, int i = 2){
    if(num == i){
        return true;
    }
    if ((num % i) == 0){
        return false;
    }
    return isPrime(num, i+1);
}

void printBits(int number, uint mask = 1){
    if(mask < (1 << 31)){
        printBits(number, mask << 1);
        std::cout << bool(number & mask);
    }
}


int main(){ 

    int number = 0;
    std::cin >> number;

    std::cout << factorLikeTail(number) << "\n";

    std::cout << (isPrime(number) ? "True" : "False") << "\n";

    printBits(number);

    return 0;
}
