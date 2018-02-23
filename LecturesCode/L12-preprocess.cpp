/*
Примерна програма за демонстрация на препроцесорни директиви.
Част от курса УП (2017)
*/

#include <iostream>
using namespace std;

#define POW 10
#define DEBUG

#define MIN(a, b) ((a)<(b)?(a):(b))

#ifdef DEBUG
#   define dbgPrint(fun, p1, p2) cout << fun"(" << p1 << ", " << p2 << ")" << endl
#else
#   define dbgPrint
#endif

double power(double x, unsigned n)
{
    dbgPrint("power", x, n);

    if (n == 0)
        return 1;

    double p2 = power(x, n/2);
    if (n%2 == 1)
        return x * p2 * p2;
    else
        return p2 * p2;
}

int main()
{
    cout << power(2, POW) << endl;
    return 0;
}
