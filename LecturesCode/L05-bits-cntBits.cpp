/*
* Програма - пример за побитови операции - брой единични битове
* Курс УП - 10.2017
*/

#include <iostream>

using namespace std;

int main()
{
    unsigned n;
    cin >> n;
    if (!cin)
    {
        return 1;
    }

    int cnt = 0;

    unsigned m = 1 << (sizeof(unsigned) << 3) - 1;
    while (m != 0)
    {
        cout << (!!(n & m));
        m >>= 1;
    }
    cout << endl;


    for (unsigned mask = 1; mask != 0; mask <<= 1)
    {
        if (n & mask)
            ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
