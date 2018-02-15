#include <iostream>
using std::cin;
using std::cout;

void replace(char * str, char x, char y){
    if(*str != '\0'){
        if(*str == x){
            *str = y;
        }
        replace(++str, x, y);
    }
}
int main(){

    char x, y;

    char * str = new (std::nothrow) char[64];
    if (!str){
        cout << "Allocation fail";
        return -1;
    }

    cin >> x;
    cin >> y;
    cin >> str;

    replace(str, x, y);

    cout << str << std::endl;

    delete [] str;

    return 0;
}
