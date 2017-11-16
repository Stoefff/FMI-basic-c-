#include <iostream>

using namespace std;

int main() {

    unsigned int a, b, c;
    cout << "Enter the 1 number" << endl;
    cin >> a;
    cout << "Enter the 2 number" << endl;
    cin >> b;
    cout << "Enter the 3 number" << endl;
    cin >> c;

    if(a >= b){
        if (a >= c){
            if (b >= c){
                cout << a << b << c << endl;
            } else {
                cout << a << c << b << endl;
            }
        } else {
            cout << c << a << b << endl;
        }
    } else if (b >= c){
        if(a >= c){
            cout << b << a << c << endl;
        } else {
            cout << b << c << a << endl;
        }
    } else {
        cout << c << b << a << endl;
    }
    
    return 0;
}
