/*
Примерна програма за демонстрация на аргументи на main функцията
и пренасочване на входа / изхода. Демонстрация към курса УП (2017
*/

#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::cin;

int main(int argc, const char* argv[])
{
    cout << argc << endl;

    for (int i = 0; i < argc; ++i)
        cout << argv[i] << endl;
    int x;
    cin >> x;
    cout << x << endl;
    std::cerr << "ERRor " << endl;
    return 0;
}
