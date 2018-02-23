/*
Примерна програма за употреба на двумерни масиви към курса УП (2015)
Вход на масив и извеждане на зиг-заг по редове
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

void read2DArray(int array[][MAX_SIZE], unsigned n, unsigned m)
{
    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = 0; j < m; ++j)
        {
            cin >> array[i][j];
        }
    }
}

void print2DArray(int array[][MAX_SIZE], unsigned n, unsigned m)
{
    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = 0; j < m; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

// Извежда масив спрямо параметъра ltr (Left to Right)
void printArray(int array[], int size, bool ltr)
{
    if (ltr)
    {
        for (unsigned i = 0; i < size; ++i)
        {
            cout << array[i] << " ";
        }
    }
    else
    {
        for (int i = size-1; i >= 0; --i)
        {
            cout << array[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    unsigned n, m;
    int matrix[MAX_SIZE][MAX_SIZE];

    n = readSize();
    m = readSize();
    read2DArray(matrix, n, m);
    print2DArray(matrix, n, m);

    cout << endl;

    for (int i = 0; i < n; ++i)
    {
        printArray(matrix[i], m, i%2 == 0);
    }
    cout << endl;
    return 0;
}
