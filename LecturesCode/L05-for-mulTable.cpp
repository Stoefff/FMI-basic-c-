/*
* Програма - пример за for цикли - таблица за умножение
* Курс УП - 10.2017
*/

#include <iostream>

using namespace std;

int main()
{
    //Заглавния ред
    cout << "*| ";
    for (int i = 1; i < 10; ++i)
        cout << "\t" << i;
    cout << endl;

    //разделителна черта
    cout << "--";
    for (int i = 1; i < 10; ++i)
        cout << "--------";
    cout << endl;

    //Самата таблица ред по ред
    for (int a = 1; a < 10; ++a)
    {
        cout << a << "| ";
        for (int b = 1; b < 10; ++b)
        {
            cout << "\t" << a*b;
        }
        cout << endl;
    }
    return 0;
}
