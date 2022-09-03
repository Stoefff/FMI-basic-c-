#include <iostream>
using namespace std;
/*
Задача 3. Напишете програма, която въвежда от потребителя цяло, неотрицателно
число n и го съхранява в променлива от тип unsigned long. След това програмата
извежда на екрана най-голямото число, което може да се получи от цифрите в записа на
n.
*/
const size_t MAX_SIZE = 20;

void swap(unsigned long& first, unsigned long& second) {
    unsigned long temp;
    temp = first;
    first = second;
    second = temp;
}

void sortArray(unsigned long* array, size_t size) {
    bool changed = false;
    unsigned sorted = 0;
    do
    {
        changed = false;
        for (size_t i = size - 1; i > sorted; --i)
        {
            if (array[i] < array[i + 1]) {
                swap(array[i], array[i + 1]);
                changed = true;
            }
        }
        ++sorted;
    } while (changed);

}

void printArray(unsigned long* array, size_t counter) {
    for (size_t i = 0; i < counter; i++)
    {
        cout << array[i];
    }
    cout << endl;
}

void copyArray(unsigned long* dest, const unsigned long* source, size_t counter) {
    for (size_t i = 0; i < counter; i++)
    {
        dest[i] = source[i];
    }
}

void printBiggest(unsigned long input) {
    //save to array
    unsigned long buffer[MAX_SIZE];

    size_t counter = 0;
    while (input != 0)
    {
        buffer[counter] = input % 10;
        input /= 10;
        counter++;
    }

    cout << "Counter:" << counter << endl;

    unsigned long* array = new unsigned long[counter];

    if (!array) cerr << "Memory problem";

    copyArray(array, buffer, counter);

    //sortArray(array, counter);

    printArray(array, counter);
    printArray(buffer, counter);
    //sort array

    //print array
}
int main() {
    unsigned long input;
    cin >> input;
    printBiggest(input);

}