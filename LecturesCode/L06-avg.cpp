/*
Примерна програма за употреба на масиви към курса УП (2017)
Вход на масив и намиране на средно аритметично на числата в него
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int main()
{
    unsigned n;
    int array[MAX_SIZE];

    do
    {
        cout << "N= ";
        cin >> n;
    }while (n == 0 || n > MAX_SIZE);

    for (unsigned i = 0; i < n; ++i)
    {
        cout << "a[" << i << "]=";
        cin >> array[i];
    }

    double sum = 0;

    for (unsigned i = 0; i < n; ++i)
    {
        sum += array[i];
    }
    cout << sum/n << endl;
    return 0;
}
