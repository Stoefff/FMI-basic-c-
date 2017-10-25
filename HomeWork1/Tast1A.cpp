// Compiled with g++ 5.4.0 on Ubuntu 16.04
#include <iostream>

using namespace std;

int main(){

    int leftNeighbor = 0, rightNeighbor = 0, currentNumber = 0;
    long lenghtOfSaw;
    bool isSaw = true;


    cout << "Enter size of the saw(Number of numbers you want to enter)" << endl;
    cin >> lenghtOfSaw;

    if(lenghtOfSaw == 0){
        cout << "yes" << endl;
        return 0;
    }

    for(long i = 0; i <= lenghtOfSaw; i++){
        cout << "Enter the " << i + 1 << " number:" << endl;
        cin >> rightNeighbor;
        if(i>1){
            currentNumber = rightNeighbor;
            if( !( ((leftNeighbor >= currentNumber)&&(rightNeighbor >= currentNumber)) ||
             ((leftNeighbor <= currentNumber)&&(rightNeighbor <= currentNumber)) ) ){
                isSaw = false;
            }
        }
        currentNumber = leftNeighbor;
    }

    return 0;
}
