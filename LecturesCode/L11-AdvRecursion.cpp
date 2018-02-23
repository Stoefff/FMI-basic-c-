/*
�������� �������� �� ������������ �� ��-������ ���������� ������ ��� ����� �� (2017).
    �������� ����
    ����� �����������
    ������� � ������� - ��� �� ��� � ��������
*/

#include <iostream>
#include <cstdlib>
using namespace std;

/////////////////////////////////////////////
//������� �� �������� � ���������� ����

// ������� �� ����������� �� ������ �������.
void move(int from, int to)
{
    cout << "�������� ���� �� " << from << " �� " << to << endl;
}

// ���������� �������, �������� ��������
// �������� ���� ��������� �� ��� �� ��� ����� ������ �� �� �������� ������
// ����� � ���� �� ��������� � ���
void hanoiRec(int from, int to, int n)
{
    if (n > 0)
    {
        int middle = 6 - from - to;
        hanoiRec(from, middle, n-1);
        move (from, to);
        hanoiRec(middle, to, n-1);
    }
}

// ������ �������
void hanoi(int n)
{
    hanoiRec(1, 3, n);
}

/////////////////////////////////////////////

// ������� �� ����� �����������.
double power(double x, unsigned n)
{
    if (n == 0)
        return 1;

    double p2 = power(x, n/2);
    if (n%2 == 1)
        return x * p2 * p2;
    else
        return p2 * p2;
}


//////////////////////////////////////////////////////////////////////////////////////////
//  ������� �� �������� �� �������� ��� �� ��� �����
// ��� ������ � �������� ���������� ���� ������� �� �����.
// �������� 0 �������� ��������� ������, �������� != 0 �����������.

const int SIZE = 10;            // ���������� ������ �� ���������
int lab[SIZE][SIZE] =           // ������ ������� �������� ���� ������������� �� ��������
{
    {0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}
};

int dx[] = {0,  1,  0, -1};     // ���������� �� X
int dy[] = {1,  0, -1,  0};     // ���������� �� Y
//  ������ �� ������ - �������� ���� ������ ������
// � ���������� � ������ ������ �� �������� (scope)
const int numMoves = sizeof(dx)/sizeof(dx[0]);

//  �������� ���������� �� �����
// ������ � �� �� �� ������� ��������� ���� ��������� �� ����������
int g_endX, g_endY;

bool hasPathRec(int x, int y)
{
    //  �������� �������:
    // ����� �����:
    if (x == g_endX && y == g_endY)
        return true;

    // ����� ���������:
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)   // �������� �� ��������� �� ������
        return false;
    if (lab[x][y] != 0)                             // ��� ��� ������� � ����������� ������
        return false;

    lab[x][y] = 2;
    // ���� �������� ���������� �� ������� ��� ��� ������ �������� ������
    bool hasPath = false;
    for (int direction = 0; !hasPath && direction < numMoves; ++direction)
    {
        hasPath = hasPathRec(x + dx[direction], y + dy[direction]);
    }
    return hasPath;
}

bool hasPath(int startX, int startY, int endX, int endY)
{
    g_endX = endX;
    g_endY = endY;
    return hasPathRec(startX, startY);
}


//////////////////////////////////////////////////////////////////////////////////////////
int main()
{
/*
    system("chcp 1251");
    hanoi(10);
*/
/*
    for (int i = 0; i <= 10; ++i)
        cout << power(2, i) << endl;
*/
    cout << boolalpha << hasPath(0, 0, 0, 9) << endl;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << lab[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
