/*
* Програма - пример за for цикли - числова пирамида
* Курс УП - 10.2017
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    const int width = 3;
    cout << "n= ";
    cin >> n;

    for (int row = 1; row <= n; ++row)
    {
        //Извежда един ред от пирамидата - съставен от няколко компонента

        //Водещи празни позиции
        for (int i = 0; i < n - row; ++i)
        {
            cout << "   ";
        }
        //Нарастваща редица
        for (int num = 1; num < row; ++num)
        {
            cout.width(width);
            cout << num;
        }
        //Намаляваща редица
        for (int num = row; num > 0; --num)
        {
            cout.width(width);
            cout << num;
        }
        cout << endl;
    }
    return 0;
}
