#include <iostream>
#include <cmath>

using namespace std;

int main(){

    float v;
    float EPS = 0.0001; //Approximation of the float value needed

    cout << "Enter value of V: " << endl;
    cin >> v;

    cout << "Value of U: ";

    if ((v - 4.0) <= EPS){
        if ((v - 2) > EPS){
            cout << v + 4 << endl;
        } else if ((v - 1) <= EPS) {
            cout << pow(v, 2) << endl; // 2-kata e stepenta ako tr da smenqsh
        } else {
            cout << "Function undefined in this region" << endl;
        }
    }  else {
        cout << v - 1 << endl;
    }
}
