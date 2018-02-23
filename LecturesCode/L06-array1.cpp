/*
Примерна програма за употреба на масиви към курса УП (2017)
Вход на масив и изход в обратен ред
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

    cout << endl;

    // Забележете типа
    for (int i = n-1; i >= 0; --i)
    {
        cout << array[i] << " ";
    }

/*
    cout << endl;
    unsigned i = n;
    do
    {
        --i;
        cout << array[i] << " ";
    }while (i != 0);
*/
    cout << endl;
    return 0;
}
