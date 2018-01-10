#include <iostream>

using namespace std;

const int MAX_OFFSET = 256;

int main(){
    float matrix[MAX_OFFSET][MAX_OFFSET];
    int size = 0;

    cout << "Enter size of the matrix: " << endl;
    cin >> size;

    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cin >> matrix[i][j];
        }
    }
}
