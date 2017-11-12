// Compiled with g++ 5.4.0 on Ubuntu 16.04 64 bit
#include <iostream>

int main(){

    unsigned int number;
    unsigned int mask = (1 << 31);
    char sequenceLength = 0;
    bool sequenceDigit = 1;

    std::cout << "Enter a positive number with max 9 digits:" << "\n";
    std::cin >> number;

    if (number == 0){
        std::cout << "0" << "\n";
    }

    while ((number & mask) == 0){
        mask >>= 1;
    }

    while ((mask > 0) || (sequenceLength > 1)) {
        if (((bool)(number & mask) == sequenceDigit) && (mask != 0)){
            sequenceLength++;
            mask >>= 1;
        } else if (sequenceLength != 1) {
            if (mask == 0){
                mask = 1 << (sequenceLength - 1);
            } else {
                mask <<= sequenceLength;
            }
            for (int i = 1; i <= sequenceLength ; i++){
                if (i % 2 == 0){
                    if (sequenceDigit == 1){
                        number = number & ~mask;
                    } else {
                        number = number | mask;
                    }
                }
                mask >>= 1;
            }
            sequenceLength = 1;
        } else {
            sequenceDigit = number & mask;
            mask >>= 1;
        }
    }

    std::cout << number << "\n";

    return 0;
}
