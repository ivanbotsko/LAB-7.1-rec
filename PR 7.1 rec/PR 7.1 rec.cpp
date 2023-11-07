// Lab_7_1.cpp
// Боцко Іван Віталійович
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 4

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** s, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** s, const int rowCount, const int colCount);
void Sort(int** s, const int rowCount, const int colCount);
void Change(int** s, const int row1, const int row2, const int colCount);
void Calc(int** s, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    const int Low = 9;
    const int High = 61;

    const int rowCount = 7;
    const int colCount = 6;

    int** s = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        s[i] = new int[colCount];

    Create(s, rowCount, colCount, Low, High);
    Print(s, rowCount, colCount);
    Sort(s, rowCount, colCount);
    Print(s, rowCount, colCount);

    int S = 0;
    int k = 0;

    Calc(s, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(s, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] s[i];
    delete[] s;
    return 0;
}

void Create(int** s, const int rowCount, const int colCount, const int Low, const int High)
{
    if (rowCount > 0)
    {
        Create(s, rowCount - 1, colCount, Low, High);
        if (colCount > 0)
        {
            s[rowCount - 1][colCount - 1] = Low + rand() % (High - Low + 1);
            Create(s, rowCount, colCount - 1, Low, High);
        }
    }
}

void Print(int** s, const int rowCount, const int colCount)
{
    if (rowCount > 0)
    {
        Print(s, rowCount - 1, colCount);
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << s[rowCount - 1][j];
        cout << endl;
    }
    else
    {
        cout << endl;
    }
}

void Sort(int** s, const int rowCount, const int colCount)
{
    if (rowCount > 1)
    {
        for (int i0 = 0; i0 < rowCount - 1; i0++)
            if ((s[i0][0] < s[i0 + 1][0]) || (s[i0][0] == s[i0 + 1][0] && s[i0][1] < s[i0 + 1][1]) || (s[i0][0] == s[i0 + 1][0] && s[i0][1] == s[i0 + 1][1] && s[i0][3] > s[i0 + 1][3]))
                Change(s, i0, i0 + 1, colCount);
        Sort(s, rowCount - 1, colCount);
    }
}

void Change(int** s, const int row1, const int row2, const int colCount)
{
    if (colCount > 0)
    {
        int tmp = s[row1][colCount - 1];
        s[row1][colCount - 1] = s[row2][colCount - 1];
        s[row2][colCount - 1] = tmp;
        Change(s, row1, row2, colCount - 1);
    }
}

void Calc(int** s, const int rowCount, const int colCount, int& S, int& k)
{
    if (rowCount > 0)
    {
        if (colCount > 0)
        {
            if (!(s[rowCount - 1][colCount - 1] % 2 == 1 && (rowCount - 1) + (colCount - 1) % 7 != 0))
            {
                S += s[rowCount - 1][colCount - 1];
                k++;
                s[rowCount - 1][colCount - 1] = 0;
            }
            Calc(s, rowCount, colCount - 1, S, k);
        }
        else
        {
            Calc(s, rowCount - 1, colCount, S, k);
        }
    }
}
