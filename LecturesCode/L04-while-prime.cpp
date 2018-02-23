/*
* Програма - пример за while цикли - Проверка за просто число
* Курс УП - 10.2017
*/

#include <iostream>
#include <cmath>

using namespace std;
/*
int main()
{
    unsigned n;

    cout << "N= ";
    cin >> n;

    unsigned divisor = 2;
    while (divisor < n)
    {
        if (n % divisor == 0)
        {
            break;
        }
        ++divisor;
    }

    if (divisor == n)
    {
        cout << "prime" << endl;
    }
    else
    {
        cout << "Not prime" << endl;
    }
    return 0;
}

*/











int main()
{
    unsigned n = 2147483647;

    unsigned divisor = 3;
    if (n % 2 != 0)         // n е нечетно
    {
        while (divisor*divisor <= n)
        {
            if (n % divisor == 0)
            {
                break;
            }
            divisor += 2;
        }

        if (n % divisor != 0)
        {
            cout << "prime" << endl;
        }
        else
        {
            cout << "Not prime" << endl;
        }
    }
    else  // N е четно число
    {
        cout << "Not prime" << endl;
    }
    return 0;
}

