#include <iostream>

int main(){

    unsigned int getter, setter, number;
    unsigned mask = 1;
    bool value;

    std::cout << "Enter number: " << std::endl;
    std::cin >> number;

    std::cout << "Enter index to get value"  << std::endl;
    std::cin >> getter;

    std::cout << "Enter index to set value" << std::endl;
    std::cin >> setter;

    value = bool(number & (mask << getter));
//    number = number & (~(value << getter ) TODO: complete it
    return 0;
}
