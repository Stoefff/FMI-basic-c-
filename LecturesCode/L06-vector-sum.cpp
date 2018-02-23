/*
Примерна програма за употреба на масиви и функции към курса УП (2017)
Въвежда два масива и извежда тяхната векторна сума
*/

#include <iostream>
using namespace std;

unsigned readSize(unsigned maxSize)
{
    unsigned n;
    do
    {
        cout << "N= ";
        cin >> n;
    }while (n == 0 || n > maxSize);
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

/* Извежда масив, очква положителен размер!
*/
void printArray(int array[], size_t size)
{
    cout << array[0];
    for (unsigned i = 1; i < size; ++i)
    {
        cout << ", " << array[i];
    }
    cout << endl;
}

/*
    намира покомпонентан сума на a1 и a2.
    Записва резултата в result
    Очаква размера им да е еднакъв и в result
    да има достатъчно място за резултата.
*/
void vectorSum(int a1[], int a2[], int result[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        result[i] = a1[i] + a2[i];
    }
}

int main()
{
    const int MAX_SIZE = 100;

    int a[MAX_SIZE], b[MAX_SIZE];
    unsigned n = readSize(MAX_SIZE);

    readArray(a, n);
    readArray(b, n);

    printArray(a, n);
    printArray(b, n);

    int c[MAX_SIZE];
    vectorSum(a, b, c, n);

    printArray(c, n);
    return 0;
}
