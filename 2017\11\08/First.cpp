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

    return 0;
}
