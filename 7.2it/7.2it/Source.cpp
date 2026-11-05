// Lab_07_2_1.cpp
// Лабораторна робота № 7.2.1
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 8

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Створення динамічної матриці
void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Форматне виведення матриці
void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// Пошук найменшого з максимальних елементів парних рядків
bool SearchMinOfMaxEvenRows(int** a, const int k, const int n, int& minOfMax)
{
    bool firstEvenRowFound = false;

    // Крок 2: переглядаємо лише парні рядки (0, 2, 4...)
    for (int i = 0; i < k; i += 2)
    {
        int maxInRow = a[i][0];

        // Пошук максимуму у поточному рядку i
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] > maxInRow)
                maxInRow = a[i][j];
        }

        // Порівняння знайденого максимуму з загальним minOfMax
        if (!firstEvenRowFound)
        {
            minOfMax = maxInRow;
            firstEvenRowFound = true;
        }
        else if (maxInRow < minOfMax)
        {
            minOfMax = maxInRow;
        }
    }

    return firstEvenRowFound;
}

int main()
{
    srand((unsigned)time(NULL));

    int k, n;
    cout << "k (rows) = "; cin >> k;
    cout << "n (cols) = "; cin >> n;

    int Low = -10;
    int High = 50;

    // Створення масиву вказівників
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    cout << "Initial Matrix:" << endl;
    Print(a, k, n);

    int minOfMax;
    if (SearchMinOfMaxEvenRows(a, k, n, minOfMax))
    {
        cout << "Minimum of maximums in even rows = " << minOfMax << endl;
    }
    else
    {
        cout << "There are no even rows in matrix!" << endl;
    }

    // Звільнення пам'яті
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}