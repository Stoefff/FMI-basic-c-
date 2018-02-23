/*
* Програма - пример за while цикли - Брой делители
* Курс УП - 10.2017
*/

#include <iostream>

using namespace std;

int main()
{
    unsigned n;

    cout << "N= ";
    cin >> n;

    unsigned divisor = 1;
    unsigned count = 0;

    while (divisor <= n)
    {
        if (n % divisor == 0)       // за всяко число, което е делител
        {
            count += 1;             // увеличаваме броя
        }
        /* може да се напише и така:
           count += (n % divisor == 0);
           но е по-грозно, макар и по-кратко
        */
        divisor = divisor + 1;
    }

    cout << "Number of divisors: " << count << endl;
    return 0;
}
