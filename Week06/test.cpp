#include <iostream>

int main(){
    unsigned int number;
    unsigned int mask = (1 << 31);
    std::cin >> number;
    for(int i = 31; i >= 0; i--){
        std::cout << (bool(number & mask));
        mask >>= 1;
    }
    std::cout << std::endl;
    mask++;
    return 0;

}

//10101010101010101010101
//&
//10000000000000000000000
//=
//10000000000000000000000
