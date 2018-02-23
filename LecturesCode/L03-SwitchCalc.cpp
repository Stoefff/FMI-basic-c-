/*
* Програма - пример за switch - калкулатор
* Курс УП - 10.2017
*/

#include <iostream>
using namespace std;

int main()
{
    int x, y;
    char operation; // +, -, * или /

    cout << "X = ";
    cin >> x;
    cout << "Y = ";
    cin >> y;

    cout << "Operation: ";
    cin >> operation;

    int result;
    switch(operation)
    {
    case '+':
        result = x+y;
        break;
    case '-':
        result = x-y;
        break;
    case '*':
        result = x*y;
        break;
    case '/':
        if (y != 0)
        {
            result = x/y;
        }
        else
        {
            cout << "Can not divide by 0!" << endl;
            return 1;
        }
        break;
    default:
        cout << "Unknown operation!" << endl;
        return 1;
    }

    cout << x << operation << y << '=' << result << endl;
    return 0;
}
