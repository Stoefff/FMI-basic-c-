/*
Примерна програма за демонстрация на указатели към функции към курса УП (2017
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

char toUpper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

char toLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

typedef char (*funPtr)(char);


void processString(char* text, funPtr processor)
{
    while (*text)
    {
        *text = processor(*text);
        ++text;
    }
}


int sum(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int mul(int a, int b)
{
    return a*b;
}

int div(int a, int b)
{
    if (b)
        return a/b;
    return 0;
}

int mod(int a, int b)
{
    return a%b;
}
int eq(int a, int b)
{
    return a==b;
}

typedef int (*calcFun)(int, int);
char        oper[]      = {'+', '-', '*', '/', '%', '='};
calcFun     functions[] = {sum, sub, mul, div, mod, eq};
const int arraySize = sizeof(oper)/sizeof(oper[0]);

void calc(int a, int b, char operation)
{
    for (int i = 0; i < arraySize; ++i)
        if (oper[i] == operation)
            cout << functions[i](a, b);
}

char toZero(char c)
{
    return '0';
}

int accumulate(int a[], int n, int start, calcFun fun)
{
    for (int i = 0; i < n; ++i)
        start = fun(start, a[i]);
    return start;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
/*
    int arr[] = {1, 2, 3, 1, 5};
    cout << accumulate(arr, 5, 0, sum) << endl;
    cout << accumulate(arr, 5, 1, mul) << endl;
    cout << accumulate(arr, 5, arr[0], min) << endl;
*/
/*
    char text[] = "I like to point things. Even functions ;)";
    switch( rand()%3)
    {
        case 0:    processString(text, toUpper);
        break;
        case 1:    processString(text, toLower);
        break;
        case 2:    processString(text, toZero);
        break;
    }

    cout << text << endl;
*/
char c;
cin >> c;
    calc (3, 5, c);

    return 0;
}
