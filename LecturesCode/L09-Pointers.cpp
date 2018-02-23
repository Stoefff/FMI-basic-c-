/*
Примерна програма за демонстрация на указатели към курса УП (2017)
Функции с параметри по адрес.
Сортиране с пряка селекция.
Намиране на най-малък и най-голям елемент в масив.
Първи пример за динамична памет.
*/

#include <iostream>
#include <cstdlib>
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
void readArray(int* array, unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        cin >> array[i];
    }
}

// Генерира масив с произволни данни.
void generateArray(int* array, unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        array[i] = rand() % 1000;
    }
}

// Извежда на екрана подаден масив. Размера на масива се подава в size
// Забележете, че параметъра се подава като константа
void printArray(const int* array, unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


// Намира минималния елемент в масив. Връща указател към него
int* minElement(int* array, unsigned size)
{
    // начално приближение
    int* min = array;
    for (unsigned i = 1; i < size; ++i)
    {
        if (array[i] < *min)     // ако намерим по-добър
            min = array + i;     // запомняме него
    }
    return min;
}


// Разменя две числа, подадени по адрес
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


// Сортиране с пряка селекция.
// Използва помощни функции за минимален и размяна
void selectionSort(int* array, unsigned size)
{
    for(unsigned i = 0; i < size-1; ++i)
    {
        // разменя i-тия елемент с минималния
        // чрез указатели към тях
        swap(array+i, minElement(array+i, size-i));
    }
}

// Намира указатели към минималния и максималния елемент в масив
// Понеже трябва да се върнат две неща (два указателя)
// резултатът се връща чрез указателни аргументи.
// Този резултат е указатели, така че имаме два двойни указателя - аргументи
void minMaxPtr(int* arr, unsigned size, int** min, int** max)
{
    *min = arr;     // Инициализираме указателя за минимум да сочи към първия елемент
    *max = arr;     // също и този за максимум

    // Декларираме указател към края на масива и вървим елемент по елемент докато не го достигнем
    for (int* end = arr+size; arr < end; ++arr)
    {
        if (*arr < **min) *min = arr;       // Ако сочим стойност по-малка от тази, която сочи минимума запомняме указателя
        if (*arr > **max) *max = arr;       // съотевтно и за максимума
    }
}


// Функция, която намира стойностите на минималния и максималния елемент в масив.
// И двете се връщат през аргументи - т.е. подаваме изходните аргументи по адрес
void minMax(int* arr, unsigned size, int* min, int* max)
{
    // Използваме вече написаната функция и за целта дефинираме два помощни указателя
    int *minPtr, *maxPtr;
    // Извикваме функцията
    minMaxPtr(arr, size, &minPtr, &maxPtr);

    // И извличаме стойностите от указателите в  параметрите
    *min = *minPtr;
    *max = *maxPtr;
}


// Прототип на функция, която заделя масив в динамичната памет
// след това преброява четните елементи и създава нов масив само от тях.
// Основна цел е да демонстрира поведението на динамичната памет.
void filterArray();


int main()
{
    filterArray();
/*

    int array[MAX_SIZE];
    unsigned n = readSize();

    generateArray(array, n);
    printArray(array, n);
    int min, max;
    minMax(array, n, &min, &max);
    cout << min << endl << max << endl;

    selectionSort(array, n);

    printArray(array, n);
    */
    return 0;
}


// Функция, която чете число - размер на масив,
// заделя динамична памет за този масив и генерира случайни числа в него.
int* readArrayDynamic(unsigned * size)
{
   unsigned n;
   cin >> n;

   int * arr = new(nothrow) int[n];
   if (!arr)
   {
       return NULL;
   }

   generateArray(arr, n);
   *size = n;
   return arr;
}


// Функция, която заделя масив в динамичната памет
// след това преброява четните елементи и създава нов масив само от тях.
// Основна цел е да демонстрира поведението на динамичната памет.
void filterArray()
{
    unsigned n;
    int* data = readArrayDynamic(&n);       // създаваме динамичен масив с произволни данни
    if (!data)                              // Проверка за успех
    {
        cerr << "No memory!" << endl;
        return;
    }

    //printArray(data, n);
    system("pause");                        // Тук погледнете колко памет има заделена

    // Броим четните елементи, чрез указател
    int cnt = 0;
    for (int* iter = data; iter < data + n; ++iter)
    {
        if (*iter % 2 == 0)
            ++cnt;
    }

    // Заделяме памет за новия масив (само от четните).
    int * result = new(nothrow) int[cnt];
    if (!result)        // проверка за успех
    {
        delete[] data;  // ако не е успешно трябва да изчистим след себе си
        cerr << "No memory for copy!" << endl;
        return;
    }

    // копираме четните елементи отново чрез указатели:
    // Един за четене от началния масив и един за запис в новия
    for (int *read = data, *write = result; read < data + n; ++read)
    {
        if (*read % 2 == 0)
            *write++ = *read;       // * е по-ниско приоритетна от ++ и затова първо присвояваме стойността, след това променяме указателя
    }
    system("pause");     // Отново проверяваме как сме с паметта - сега имаме двата масива
    delete[] data;       // Изчистваме началния масив

    //printArray(data, cnt);
    system("pause");     // Пак проверка - сега сме само с копието
    delete[] result;     // и изчистваме и него
}

