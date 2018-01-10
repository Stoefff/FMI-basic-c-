#include <iostream>
#include <cmath>

using namespace std;

int main(){

    float v;
    float u;

    cout << "Enter value of V: " << endl;
    cin >> v;

    if ( (v <= 4) && (v > 2) ){ // Ако v е по-малко или равно от 4 !! И !! по-голямо от 2
        u = v + 4;
    }
    if (v > 4){
        u = v - 1;
    }
    if (v <= 1){
        u = pow(v, 2);
    }
    if ( (v > 1) && (v <= 2) ){ // Ако видиш условието между 1 и 2 не е казано какво да се прави за тва така съм го писал
        cout << "Function undefined in this region" << endl;
        return 0;
    }

    cout << "Value of U: " << u << endl;
    return 0;
}
