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
//Recursion with bit mask most likely to be on the exams
//Implemented with tail recursion
int countZeroBits(int number, uint mask = (1 << 31)){
    if (mask == 1){
        if((bool)(number & mask) == 0){
            return 1;
        } else {
            return 0;
        }
    }
    if (bool(number & mask) == 0){
        return countZeroBits(number, mask >> 1) + 1;
    } else {
        return countZeroBits(number, mask >> 1);
    }
}


int main(){

    int number = 0;
    std::cin >> number;

    std::cout << factorLikeTail(number) << "\n";

    std::cout << (isPrime(number) ? "True" : "False") << "\n";

    printBits(number);

    std::cout << "Number of zereos: " << countZeroBits(number) << "\n";

    return 0;
}
