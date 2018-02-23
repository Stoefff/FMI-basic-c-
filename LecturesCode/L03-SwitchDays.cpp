/*
* Програма - пример за switch с пропадане - брой дни в месец
* Курс УП - 10.2017
*/

#include <iostream>
using namespace std;

int main()
{
    unsigned month;

    do
    {
        cout << "month: ";
        cin >> month;
    }while (month < 1 || month > 12);

    unsigned days = 0;
    switch (month)
    {
    default:
        days += 1;
    case 4: case 6: case 9: case 11:
        days += 2;
    case 2:
        days += 28;
    }

    cout << "days: " << days << endl;
    return 0;
}
