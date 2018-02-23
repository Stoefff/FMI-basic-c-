/*
Примерна програма за употреба на масиви към курса УП (2017)
Вход на масив и намиране на най-малък елемент >= на средно аритметично
на числата в масива
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
        cin >> array[i];
    }

    double sum = 0;
    for (unsigned i = 0; i < n; ++i)
    {
        sum += array[i];
    }
    double avg = sum/n;

    // Какво да бъде началното приближение?
    int min = avg * n;
    for (unsigned i = 0; i < n; ++i)
    {
        if (array[i] >= avg && array[i] < min)
            min = array[i];
    }

    cout << avg << endl << min << endl;
    return 0;
}
