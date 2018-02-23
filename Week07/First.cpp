#include <iostream>
#include <random>

#define MAX_OFFSET 1024

void task1(){
    int array[MAX_OFFSET];
    int number;

    std::cin >> number;

    for(int i = 0; i < number; i++){
        std::cin >> array[i];
    }

    for(int i = 0; i < number; i++){
        std::cout << array[i];
    }
}

void task2(){
    int array[MAX_OFFSET];
    int number;

    std::cin >> number;

    srand(0);

    for(int i = 0; i < number; i++){
        array[i] = ((rand() % 600) - 300);
    }

    for(int i = 0; i < number; i++){
        std::cout << array[i] << " ";
    }
}

void task3(){
    int array[MAX_OFFSET];
    int number;
    int sum = 0;
    int product = 1;

    std::cin >> number;

    for(int i = 0; i < number; i++){
        array[i] = ((rand() % 600) - 300);
    }

    for(int i = 0; i < number; i++){
        std::cout << array[i] << " ";
    }

    for(int i = 0; i < number; i++){
        sum += array[i];
    }

    for(int i = 0; i < number; i++){
        product *= array[i];
    }

    std::cout << "Sum = " << sum << "\n" ;
    std::cout << "Product = " << product << "\n" ;
}


void task4(){
    int array[MAX_OFFSET];
    int number;

    std::cin >> number;

    srand(0);

    for(int i = 0; i < number; i++){
        array[i] = ((rand() % 600) - 300);
    }

    for(int i = 0; i < number; i++){
        std::cout << array[i] << " ";
    }
}

int main(){

    task3();

    return 0;
}
