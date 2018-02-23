/*
Примерна програма за употреба на двумерни масиви към курса УП (2017)
Вход на масив и намиране на сумата по редове и колони
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

int sumArray(int arr[], unsigned n)
{
    int sum = 0;
    for (unsigned i = 0; i < n; ++i)
        sum += arr[i];
    return sum;
}

int sumRow(int array[][MAX_SIZE],
           unsigned row,
           unsigned size)
{
    int sum = 0;
    for (unsigned i = 0; i < size; ++i)
        sum += array[row][i];
    return sum;
}

int sumCol(int array[][MAX_SIZE],
           unsigned col,
           unsigned size)
{
    int sum = 0;
    for (unsigned i = 0; i < size; ++i)
        sum += array[i][col];
    return sum;
}

int main()
{
    unsigned n, m;
    int matrix[MAX_SIZE][MAX_SIZE];

    n = readSize();
    m = readSize();
    read2DArray(matrix, n, m);

    cout << endl;
    print2DArray(matrix, n, m);

    for (unsigned i = 0; i < m; ++i)
    {
        cout << sumCol(matrix, i, n) << "  ";
    }
    cout << endl;
    return 0;
}
