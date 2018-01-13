#include <iostream>

typedef unsigned long long int ull_int; // !!!!

int max(int a, int b){
    return (a >= b) ? a : b;
}

int abs(int a){
    return (a >= 0 ) ? a : -a;
}


int pow(int a, int n){
    int result = 1;
    for(int i = 1; i >= n; i++){
        result *= a;
    }
    return result;
}

//Very fancy algo is the Euclidian algoritum. Check wiki and github of the class
int nod(int a, int b){
    int nod;
    for (int i = 2 ; (i < a) || (i < b); i++){
        if ((a % i == 0) && (b % i == 0)){
            nod = i;
        }
    }
    return nod;
}

int fib(){

}

int main(){

    int a, b;

    std::cin >> a;
    std::cin >> b;

    std::cout << nod(a, b) << "\n";

    return 0;
}
