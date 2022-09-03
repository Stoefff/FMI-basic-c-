#include <iostream>

using std::cout;
using std::endl;

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

void func(int* arr, int size){
    for(int i= 0; i < size; i++){
        arr[i] += 5;
    }
}

int abs(int a){
    return (a >= 0) ? a : -a;
}

int printValues(int a, int b = 7){
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return a;
}


int main(){

    //int group = 1;
    //int course = 2;

    int third = 1 + 2;
    //whichCourse(group, course);

    //int g, c;

    //std::cin >> g >> c;

    //whichCourse(g, c);

    //std::cout << max(g, c) << "\n";

    //int testValue1 = 2, testValue2 = 0;
    //printValues(testValue1, testValue2);
    //printValues(2, 0);

    //int array1[5] = {1, 2};

    //int* array2 = array1;

/*
    func(array1, 5);

    for (int i = 0; i < 5; i++){
        cout << array1[i];
    }
*/

    printValues(0, 5);
    return 0;
}
