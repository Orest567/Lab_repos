// L.7.2rec.cpp
// Лабораторна робота № 7.2.2
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 8

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// 1. Рекурсивне створення одного рядка
void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1)
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
}

// 2. Рекурсивне створення всіх рядків
void CreateRows(int** a, const int k, const int n, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < k - 1)
        CreateRows(a, k, n, Low, High, rowNo + 1);
}

// 3. Рекурсивний друк одного рядка
void PrintRow(int** a, const int rowNo, const int n, int colNo)
{
    cout << setw(5) << a[rowNo][colNo];
    if (colNo < n - 1)
        PrintRow(a, rowNo, n, colNo + 1);
    else
        cout << endl;
}

// 4. Рекурсивний друк усіх рядків
void PrintRows(int** a, const int k, const int n, int rowNo)
{
    PrintRow(a, rowNo, n, 0);
    if (rowNo < k - 1)
        PrintRows(a, k, n, rowNo + 1);
    else
        cout << endl;
}

// 5. Рекурсивний пошук максимуму у конкретному рядку
int SearchMaxInRow(int** a, const int rowNo, const int n, int colNo, int maxInRow)
{
    if (a[rowNo][colNo] > maxInRow)
        maxInRow = a[rowNo][colNo];

    if (colNo < n - 1)
        return SearchMaxInRow(a, rowNo, n, colNo + 1, maxInRow);
    else
        return maxInRow;
}

// 6. Рекурсивний перебір лише парних рядків (rowNo += 2) для пошуку minOfMax
void SearchMinOfMax(int** a, const int k, const int n, int rowNo, int& minOfMax)
{
    int currentMax = SearchMaxInRow(a, rowNo, n, 1, a[rowNo][0]);
    if (currentMax < minOfMax)
        minOfMax = currentMax;

    if (rowNo + 2 < k)
        SearchMinOfMax(a, k, n, rowNo + 2, minOfMax);
}

int main()
{
    srand((unsigned)time(NULL));

    int k, n;
    cout << "k (rows) = "; cin >> k;
    cout << "n (cols) = "; cin >> n;

    int Low = -10;
    int High = 50;

    // Виділення пам'яті під динамічний масив
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    // Рекурсивне формування та виведення
    CreateRows(a, k, n, Low, High, 0);
    cout << "Initial Matrix:" << endl;
    PrintRows(a, k, n, 0);

    int minOfMax;
    // Початкове значення: максимум з 0-го (першого парного) рядка
    int maxInRow0 = SearchMaxInRow(a, 0, n, 1, a[0][0]);
    minOfMax = maxInRow0;

    // Якщо є наступні парні рядки (індекс 2, 4...) — перевіряємо їх рекурсивно
    if (k > 2)
    {
        SearchMinOfMax(a, k, n, 2, minOfMax);
    }

    cout << "Minimum of maximums in even rows = " << minOfMax << endl;

    // Звільнення пам'яті
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}