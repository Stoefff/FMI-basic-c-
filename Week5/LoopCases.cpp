#include <iostream>

int main(){

    unsigned int n;
    std::cin >> n;
// Fucked up way to write for loop but it workes. The for must be easily red
    for(unsigned int i = 1, j = n - 1;
        i < n;
        ++i, --j){
        std::cout << n << " = " << i << " + " << j << "\n";
    }

    // how to brake to cin buffer
    unsigned int m = 100;
    do {
        std::cout << "Enter m" << "\n";
        // Buffer read keyboard input and ignores(counts as a whitespace) syms bellow 32 ASCII
        std::cin >> m; // Here we enter symbols
    } while (m > 50);


    return 0;
}
