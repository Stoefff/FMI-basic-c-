/*
    Примерна програма, демонстрираща функции.
    Намира първите N прости числа
*/

#include <iostream>
using namespace std;

bool isPrime(unsigned n)
{
    // Най-малкото просто число е 2
    if (n < 2)
    {
        return false;
    }

    // Две е единственото четно просто число
    if (n % 2 == 0)
    {
        return n == 2;
    }

    for (int div = 3; div*div <= n; div += 2)
    {
        if (n % div == 0)
        {
            return false;
        }
    }

    return true;
}

void nPrimes(int n)
{
    int num = 1;
    int count = 0;

    while (count < n)
    {
        if (isPrime(num))
        {
            cout << count+1 << " : " << num << endl;
            ++count;
        }
        ++num;
    }
}

int main()
{
    int n;

    cin >> n;
    nPrimes(n);

    return 0;
}
