#include <iostream>

using namespace std;

//Not the actual task, just testing trenary operations
// Fucking slippery! Watch for some fucks
int main(){
    int number;
    cout << "Enter a whole number: ";
    cin >> number;
    // if the lower expression was like: (number % 2) the fucking thing wont work !!!!
    cout << ((number % 2 == 0) ? "Dank memes" : "Not dank memes") << endl;
    return 0;
}
