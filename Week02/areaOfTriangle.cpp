#include <iostream>
#include <cmath>

using namespace std;

void areaByHeight(){

    float side, height, area;

    cout << "Enter side: ";
    cin >> side;
    cout << "Enter height: ";
    cin >> height;

    area = (side * height)/2;

    cout << "Area of triangle is: " << area << endl;

}

void areaBySides(){

    float side1, side2, side3, semiPer, area;

    cout << "Enter side one: ";
    cin >> side1;
    cout << "Enter side two: ";
    cin >> side2;
    cout << "Enter side three : ";
    cin >> side3;

    semiPer = (side1 + side2 + side3)/2;
    area = sqrt(semiPer * (semiPer - side1) * (semiPer - side2) * (semiPer - side3));

    cout << "Area of triangle is: " << area << endl;
}

int main(){

    unsigned short option;

    cout << "Choose way for calculating:\nEnter \"1\" for side with height and side.\n"
        "Enter \"2\" for three sides" << endl;
    cin >> option;

    switch (option) {
        case 1: areaByHeight(); break;
        case 2: areaBySides(); break;
    }

    return 0;
}
