/*
Примерна програма за демонстрация на алгоритми върху масиви към курса УП (2017)
Минимален и максимален елемент.
Вмъкване и премахване на елемент в масив.
Филтриране на масив.
Сортиране: пряка селекция, вмъкване, мехурче
Търсене: Линейно, двоично. Намирне на регион.
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;


// Прочита размера на масив. Подсигурява той да е в интеравла [1, MAX_SIZE]
unsigned readSize()
{
    unsigned n;
    do
    {
        cout << "N= ";
        cin >> n;
    }while (n == 0 || n > MAX_SIZE);
    return n;
}


// Прочита от клавиатурата подаден масив. Размера на масива се подава в size
void readArray(int array[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        cin >> array[i];
    }
}


// Извежда на екрана подаден масив. Размера на масива се подава в size
void printArray(int array[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


// Намира минималния елемент в масив. Връща стойността на този елемент
int minElement(int array[], unsigned size)
{
    // начално приближение
    int min = array[0];
    for (unsigned i = 1; i < size; ++i)
    {
        if (array[i] < min)     // ако намерим по-добър
            min = array[i];     // запомняме него
    }
    return min;
}


// Намира минималния елемент в масив. Връща индекса на този елемент
unsigned minIndex(int array[], unsigned size)
{
    // начално приближение
    unsigned min = 0;
    for (unsigned i = 1; i < size; ++i)
    {
        if (array[i] < array[min])  // ако намерим по-добър
            min = i;                // запомняме него
    }
    return min;
}


// Намира минималния елемент в част от масив с размер size.
// Частта започва от индекс from.
// Връща индекса на елемента
unsigned minFrom(int array[], unsigned from, unsigned size)
{
    unsigned min = from;
    for (unsigned i = from + 1; i < size; ++i)
    {
        if (array[i] < array[min])
            min = i;
    }
    return min;
}


// Премахва всички отрицателни елементи от масив.
// Връща броя на останалите елементи
// Работи върху входния масив
unsigned filterNegative(int array[], unsigned size)
{
    unsigned read = 0,  // индекс за четене в масива
             write = 0; // индекс за запис в масива
    for (read = 0; read < size; ++read)
    {
        if (array[read] >= 0)
        {
            array[write] = array[read];
            ++write;
        }
    }
    return write;
}


// Добавя елемента X на позиция index в масив.
// Запазва реда на останалите елементи.
// Връща true ако индекса е валиден и false иначе.
bool insertAt(int array[], unsigned index, int x, unsigned n)
{
    // проверка за валидност
    if (index > n)
    {
        cerr << "Bad position!" << endl;
        return false;
    }

    // изтегля елементите назад за да освободи мястото index
    for (unsigned i = n; i > index; i)
        array[i] = array[i-1];

    // и добавя елемента
    array[index] = x;
    return true;
}


// Вмъква елемент в масив на позиция index.
// Не запазва относителния ред на елементите.
// Връща true ако индекса е валиден и false иначе.
bool insertAtDirect(int array[], unsigned index, int x, unsigned n)
{
    // проверка за валидност
    if (index > n)
    {
        cerr << "Bad position!" << endl;
        return false;
    }

    array[n] = array[index];
    array[index] = x;
    return true;
}


// Премахва елемент в масив от позиция index.
// Запазва реда на останалите елементи.
// Връща true ако индекса е валиден и false иначе.
bool deleteAt(int array[], unsigned index, unsigned n)
{
    // проверка за валидност
    if (index >= n)
    {
        cerr << "Bad position!" << endl;
        return false;
    }

    // премества елементите напред за да запълнят мястото index
    for (int i = index; i < n-1; ++i)
        array[i] = array[i+1];
    return true;
}


// Премахва елемент в масив от позиция index.
// Не запазва относителния ред на елементите.
// Връща true ако индекса е валиден и false иначе.
bool deleteAtDirect(int array[], unsigned index, unsigned n)
{
    // проверка за валидност
    if (index > n)
    {
        cerr << "Bad position!" << endl;
        return false;
    }
    array[index] = array[n-1];
    return true;
}


// Вмъква елемент в СОРТИРАН възходящо масив array.
// Масива трябва да остане сортиран,
void insertSorted(int array[], int x, unsigned size)
{
    int i = size;

    // Изтегля назад елементите по-големи от X за да му направи място
    while (i > 0 && array[i-1] > x)
    {
        array[i] = array[i-1];
        --i;
    }

    // накрая поставя елемента на освободеното място
    array[i] = x;
}


// Разменя два елемента на масив посредством трети междинен
void swap(int arr[], unsigned i, unsigned j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}


// Сортиране с пряка селекция.
// Използва помощни функции за минимален и размяна
void selectionSort(int array[], unsigned size)
{
    for(unsigned i = 0; i < size-1; ++i)
    {
        int m = minFrom(array, i, size);
        swap(array, m, i);
    }
}


// Сортиране с вмъкване.
// Използва помощна функция за вмъкване
void insertionSort(int array[], unsigned size)
{
    for (unsigned i = 1; i < size; ++i)
        insertSorted(array, array[i], i);
}


// Сортиране по метода на мехурчето
void bubbleSort(int array[], unsigned size)
{
    bool changed = false;       // Дали сме правили размяна при последното минаване
    unsigned sorted = 0;
    do
    {
        changed = false;        // маркираме, че не сме разменяли
        // и проверяваме всички двойки съседни елементи
        for (unsigned i = size-1; i > sorted; --i)
        {
            if (array[i] < array[i-1])      // ако не са в правилния ред
            {
                swap(array, i, i-1);        // подреждаме ги
                changed = true;             // и маркираме размяна
            }
        }
        ++sorted;                           // отбелязваме коя част вече е сортирана
    }while (changed);
}


// Последователно търсене
// Връща индекса на X или -1 ако не се среща
int search(int array[], int x, unsigned size)
{
    for(unsigned i = 0; i < size; ++i)
    {
        if (array[i] == x)
            return i;
    }
    return -1;
}


// Двоично търсене.
// Масивът ЗАДЪЛЖИТЕЛНО е сортиран
// Връща индекса на X или -1 ако не се среща
int binarySearch(int array[], int x, unsigned size)
{
    // лява и дясна граница за търсене
    unsigned left = 0, right = size;

    // Докато интервалът за търсене не е празен
    while (left < right)
    {
        // намираме средата
        unsigned middle = (left + right) / 2;

        if (array[middle] == x)     // ако сме намерили елемнета
            return middle;          // връщаме позицията му

        if (array[middle] < x)      // Ако средният елемент е по-малък
            left = middle + 1;      // отрязваме отляво
        else
            right = middle;         // иначе отрязваме отдясно
    }
    return -1;                      // елемента не е намерен
}

// Намира и извежда интервал от равни на X елементи в масива array.
// Пример за използване на двоично търсене и полезността му ;)
void findRange(int array[], int x, unsigned size)
{
    unsigned left = 0, right = size;

    while (left < right)
    {
        unsigned middle = (left + right) / 2;
        if (array[middle] < x)
            left = middle + 1;
        else
            right = middle;
    }
    if (array[left] != x)
        return;

    int lb = left;

    right = size;
    while (left < right)
    {
        unsigned middle = (left + right) / 2;
        if (array[middle] <= x)
            left = middle + 1;
        else
            right = middle;
    }
    int rb = left;

    cout << "[" << lb << ", " << rb << "]" << endl;
}


int main()
{
    int array[MAX_SIZE];
    unsigned n = readSize();

    readArray(array, n);
    printArray(array, n);

    n = filterNegative(array, n);
    printArray(array, n);

    return 0;
}
