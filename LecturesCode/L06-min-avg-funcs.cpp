/*
Примерна програма за употреба на масиви и функции към курса УП (2017)
Вход на масив и намиране на най-малък елемент >= на средно аритметично
на числата в масива
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

unsigned readSize()
{
    unsigned n;
    do
    {
        cout << "N= ";
        cin >> n;
    }while (n == 0 || n > MAX_SIZE);
    return n;
}

void readArray(int array[], int size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        cout << "a[" << i << "]=";
        cin >> array[i];
    }
}

void printArray(int array[], int size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

//Прототип на функцията
int sumArray(int array[], int size);

double avgArray(int array[], int size)
{
    double sum = sumArray(array, size);
    return sum / size;
}

int sumArray(int array[], int size)
{
    int sum = 0;
    for (unsigned i = 0; i < size; ++i)
    {
        sum += array[i];
    }
    return sum;
}

int main()
{
    int array[MAX_SIZE];
    unsigned n = readSize();

    readArray(array, n);
    printArray(array, n);

    double avg = avgArray(array, n);

    int min = array[0];
    for (unsigned i = 0; i < n; ++i)
    {
        if (min < avg || (array[i] >= avg && array[i] < min))
            min = array[i];
    }

    cout << avg << endl << min << endl;
    return 0;
}
