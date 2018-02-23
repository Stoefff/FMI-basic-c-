/*
Примерна програма за демонстрация на изброен тиш към курса УП (2017).
*/

#include <iostream>
using namespace std;

enum
{
    BEGIN,
    ONE,
    TWO,
    FIVE = 5,
    SIX,
    ZERO = 0
};
void print()
{
    cout << ZERO << " " << ONE << " "
         <<  TWO << " " << SIX << endl;
}
enum ColorType
{
    C_UNKNOWN = -1,
	C_BLACK,
    C_RED,
    C_GREEN,
    C_PINK,
    C_BLUE,
    C_WHITE,
    C_COUNTER
};

const char* const names[] =
{
    "Black",
    "Red",
    "Green",
    "Pink",
    "Blue",
    "White"
};

int printColor(ColorType c)
{
    switch (c)
    {
        case C_BLACK:   cout << c << " Cherno" << " " << names[c] << endl; break;
        case C_BLUE:    cout << c << " Sinjo" << " " << names[c]<< endl; break;
        case C_GREEN:   cout << c << " Zeleno" << " " << names[c]<< endl; break;
        case C_RED:     cout << c << " Cherveno" << " " << names[c]<< endl; break;
        case C_WHITE:   cout << c << " Bjalo" << " " << names[c]<< endl; break;
        case C_PINK:    cout << c << " Rozowo" << " " << names[c]<< endl; break;
        default:        cout << c << " Neizvestno" << endl;
    }
}

void testCounting()
{
    for (int c = C_UNKNOWN+1; c < C_COUNTER; c+=1)
        printColor((ColorType)c);
}

int main()
{
//    print();
    testCounting();
    return 0;
}
