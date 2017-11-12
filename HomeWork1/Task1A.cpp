// Compiled with g++ 5.4.0 on Ubuntu 16.04 64 bit
#include <iostream>

int main(){

    int leftNeighbor = 0, rightNeighbor = 0, currentNumber = 0;
    long lenghtOfSaw;
    bool isSaw = true;

    std::cout << "Enter size of the saw (number of numbers you want to enter):" << '\n';
    std::cin >> lenghtOfSaw;

    for(long i = 0; i < lenghtOfSaw; i++){
        std::cout << "Enter the " << i + 1 << " number:" << '\n';
        std::cin >> rightNeighbor;
        if(i == 0){
            leftNeighbor = rightNeighbor;
            continue;
        }
        if(i == 1){
            currentNumber = rightNeighbor;
            continue;
        }
        if( !( ((leftNeighbor >= currentNumber)&&(rightNeighbor >= currentNumber)) ||
         ((leftNeighbor <= currentNumber)&&(rightNeighbor <= currentNumber)) ) ){
            isSaw = false;
            break; // Armqnov said that we can end io like that
        }
        leftNeighbor = currentNumber;
        currentNumber = rightNeighbor;
    }

    std::cout << (isSaw ? "yes" : "no") << '\n';
    return 0;
}
