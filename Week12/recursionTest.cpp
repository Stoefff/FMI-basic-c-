#include <iostream>

void recursionPrint(int iter){
    if(iter < 10){
        std::cout << "Hello World + " << iter << " \n";
        iter++;
        recursionPrint(iter);
    }
}

int sum(int number, int result = 0){ // if result is not passed, default is 0 !!
    if(number <= 0)
        return result;
    return sum(number-1, result + number);
}

int main(){
    int iter = 0;
    recursionPrint(iter);

    return 0;
}
