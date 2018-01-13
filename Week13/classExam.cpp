#include <iostream>
// Ivanaka did it with one function
bool digitChecker(int number, int digit){
    if (number == 0) return true;
    if ((number % 10) == digit){
        return false;
    } else return digitChecker(number / 10, digit);
}

bool checker(int number){
    if (number == 0) return true;
    int digit = number % 10;
    if (digitChecker(number / 10, digit) == true){
        return checker((number/10));
    } else return false;
}

int main(){
    int number;
    std::cin >> number;
    std::cout << (checker(number) ? "True" : "False") << "\n";
}
