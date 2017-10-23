#include <iostream>

using namespace std;

int main(){

    bool a, b;

    cout << "Enter a = ";
    cin >> a;

    cout << endl << "Enter b = ";
    cin >> b;

    bool c = a && b;
    bool d = a || b;


    cout << "a & b = " << c << " a | b = " << d << endl;
    return 0;

}
