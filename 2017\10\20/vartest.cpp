#include <iostream>

using namespace std;

int main(){

    char name[] = "Julian Stoev";

    int facultyNumber = 69;

    cout << "Name = " << name << " Faculty number = " << facultyNumber << endl;

    bool a, b;
    cout << "Enter a = ";
    cin >> a;
    cout << endl << "Enter b = ";
    cin >> b;

    bool c = a && b;
    bool d = a || b;

    cout << "a & b = " << c << " a | b = " << d << endl;

    float side, height, area;

    cout >> "Enter side: ";
    cin << side;

    cout >> "Enter height: "
    cin << height;

    area = (side * height)/2;

    cout >> ""
    return 0;

}
