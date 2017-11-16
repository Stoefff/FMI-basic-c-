#include <iostream>

void whichCourse(int gr, int qs){

    std::cout << "My group: " << gr
        << "\nMy course: " << qs << "\n";
}


//Valid sytax wtf
int max(int a, int b){

    if(a > b)
        return a;
    return b;
}

int abs(int a){

    return (a >= 0) ? a : -a;

}
int main(){

    whichCourse(1, 4);

    int g, c;

    std::cin >> g >> c;

    whichCourse(g, c);

    std::cout << max(g, c) << "\n";

    return 0;
}
