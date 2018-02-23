/*
* Програма за решаване на квадратно уравнение
* Курс УП - 10.2017
*/

#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1E-9;    // Епсилон грешка

int main()
{
    double a, b, c;

    /* Вход на данните */
    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    cout << "c = ";
    cin >> c;

    if (abs(a) < eps)           // уравнението не е квадратно
    {
        if (abs(b) < eps)       // изразът не зависи от X
        {
            if (abs(c) < eps)   // тъждествена 0
            {
                cout << "All numbers are solutions." << endl;
            }
            else                // невалиден израз
            {
                cout << "No solution." << endl;
            }
        }
        else                    // уравнението е линейно
        {
            double X = -c/b;
            cout << "The eqation " << b << "x + " << c << " = 0"
                 << " has single root: " << X << endl;
        }
    }
    else                        // уравнението е квадратно
    {
        double D = b*b - 4*a*c;
        if (D < 0)              // отрицателна дискриминанта
        {
            cout << "The equation has no real roots!" << endl;
        }
        else if (D > 0)         // положителна дискириминанта
        {
            double X1, X2;
            X1 = (-b + sqrt(D)) / (2*a);
            X2 = -X1 - b/a; // формула на Вийет
            cout << "The eqation " << a << "x^2 + " << b << "x + " << c << " = 0"
                 << " has two roots: " << X1 << " and " << X2 << endl;
        }
        else                    // дискиринантата е 0
        {
            double X = -b/(2*a);
            cout << "The eqation " << a << "x^2 + " << b << "x + " << c << " = 0"
                 << " has one double root: " << X << endl;
        }
    }
    return 0;
}
