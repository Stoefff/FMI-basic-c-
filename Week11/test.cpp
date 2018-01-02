#include <iostream>

int myStrlen(char *& string){
    unsigned length = 0;
    while(*string != '\0'){
        string++;
        length++;
    }
    string -= length;
    std::cout << "Pointer at the end of the function: "<< &string << '\n' ;
    return length;
}

int main(){
    char * name = new (std::nothrow) char[16];
        if (!name){
            std::cerr << "Not allocated" << '\n';
            return -1;
        }
    std::cin.getline(name, 15);
    std::cout << "Pointer on allocation: "<< &name << '\n';
    std::cout << myStrlen(name) << '\n';
    delete[] name;
    return 0;
}
