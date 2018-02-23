/*
    Примерна програма, демонстрираща функции.
    Пример за подаване по стойност
*/

#include <iostream>
using namespace std;

int min(int x, int y)
{
    if (x < y)
    {
        y = 0;
        cout << "min: " << x << " " << y << endl;
        return x;
    }
    else
    {
        x = 0;
        return y;
    }
}

void swap(int x, int y)
{
    cout << "swap: " << x << " " << y << endl;
    int help = x;
    x = y;
    y = help;
    cout << "swap: " << x << " " << y << endl;
}

int main()
{
    int a, b;
    cin >> a >> b;

//    cout << min(a, b) << endl;

//    cout << "main: " << a << " " << b << endl;
    swap(a, b);
    cout << "main: " << a << " " << b << endl;
    return 0;
}
