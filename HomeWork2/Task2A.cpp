// Compiled with g++ 5.4.0 on Ubuntu 16.04 64 bit
#include <iostream>

const int MAX_OFFSET = 10;

bool checkSquare(int square[MAX_OFFSET][MAX_OFFSET], short size){
    int magicNumber = 0, otherDiagonalSum = 0;

    for (int i = 0, j = size-1; i < size; i++, j--){
        magicNumber += square[i][i];
        otherDiagonalSum += square[i][j];
    }

    if (magicNumber != otherDiagonalSum) { return false; }

    for (int i = 0; i < size; i++){
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < size; j++){
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if((rowSum != magicNumber) || (colSum != magicNumber)) { return false; }
    }
    return true;
}

int main(){
    short size;
    int square[MAX_OFFSET][MAX_OFFSET];

    std::cout << "Enter size of the square = ";
    std::cin >> size;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            std::cout << "Enter " << i+1 << " row, " << j+1 << " collume \n";
            std::cin >> square[i][j];
        }
    }
    /* Check entered square
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            std::cout <<  square[i][j] << " ";
        }
        std::cout << "\n";
    } */

    std::cout << ((checkSquare(square, size)) ? "True" : "False") << "\n";
    // Semergiev said that just passing square without the cast wont work because
    // the compiler tries to protect us from lossing the array size, but
    // because we pass size (< MAX_OFFSET with with the array is init), we
    // can work safe here

    return 0;
}
