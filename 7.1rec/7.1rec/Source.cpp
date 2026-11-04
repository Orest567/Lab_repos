#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// 1. Рекурсивне створення матриці
void CreateRow(int** R, const int rowNo, const int colNo, const int colCount, const int Low, const int High)
{
    R[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1)
        CreateRow(R, rowNo, colNo + 1, colCount, Low, High);
}

void CreateRows(int** R, const int rowNo, const int rowCount, const int colCount, const int Low, const int High)
{
    CreateRow(R, rowNo, 0, colCount, Low, High);
    if (rowNo < rowCount - 1)
        CreateRows(R, rowNo + 1, rowCount, colCount, Low, High);
}

// 2. Рекурсивне виведення матриці
void PrintRow(int** R, const int rowNo, const int colNo, const int colCount)
{
    cout << setw(4) << R[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(R, rowNo, colNo + 1, colCount);
    else
        cout << endl;
}

void PrintRows(int** R, const int rowNo, const int rowCount, const int colCount)
{
    PrintRow(R, rowNo, 0, colCount);
    if (rowNo < rowCount - 1)
        PrintRows(R, rowNo + 1, rowCount, colCount);
    else
        cout << endl;
}

// 3. Рекурсивна заміна стовпчиків місцями
void ChangeRow(int** R, const int col1, const int col2, const int rowNo, const int rowCount)
{
    int tmp = R[rowNo][col1];
    R[rowNo][col1] = R[rowNo][col2];
    R[rowNo][col2] = tmp;

    if (rowNo < rowCount - 1)
        ChangeRow(R, col1, col2, rowNo + 1, rowCount);
}

// 4. Рекурсивне сортування стовпчиків (аналог бульбашки)
void SortPass(int** R, const int rowCount, const int j, const int colCount)
{
    if (j < colCount - 1)
    {
        if ((R[0][j] > R[0][j + 1]) ||
            (R[0][j] == R[0][j + 1] && R[1][j] > R[1][j + 1]) ||
            (R[0][j] == R[0][j + 1] && R[1][j] == R[1][j + 1] && R[2][j] > R[2][j + 1]))
        {
            ChangeRow(R, j, j + 1, 0, rowCount);
        }
        SortPass(R, rowCount, j + 1, colCount);
    }
}

void SortRows(int** R, const int rowCount, const int colCount, const int i)
{
    if (i < colCount - 1)
    {
        SortPass(R, rowCount, 0, colCount - i);
        SortRows(R, rowCount, colCount, i + 1);
    }
}

// 5. Рекурсивне обчислення та обнулення (Calc)
void CalcRow(int** R, const int rowNo, const int colNo, const int colCount, int& S, int& k)
{
    if (R[rowNo][colNo] > 0 || R[rowNo][colNo] % 3 != 0)
    {
        S += R[rowNo][colNo];
        k++;
        R[rowNo][colNo] = 0;
    }

    if (colNo < colCount - 1)
        CalcRow(R, rowNo, colNo + 1, colCount, S, k);
}

void CalcRows(int** R, const int rowNo, const int rowCount, const int colCount, int& S, int& k)
{
    CalcRow(R, rowNo, 0, colCount, S, k);
    if (rowNo < rowCount - 1)
        CalcRows(R, rowNo + 1, rowCount, colCount, S, k);
}

// 6. Рекурсивне звільнення пам'яті
void FreeRows(int** R, const int rowNo, const int rowCount)
{
    delete[] R[rowNo];
    if (rowNo < rowCount - 1)
        FreeRows(R, rowNo + 1, rowCount);
}

int main()
{
    srand((unsigned)time(NULL));

    const int rowCount = 7;
    const int colCount = 9;

    int Low = -12;
    int High = 37;

    // Створення динамічного масиву
    int** R = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        R[i] = new int[colCount];

    // Формування та вивід початкової матриці
    CreateRows(R, 0, rowCount, colCount, Low, High);
    cout << "Initial Matrix:" << endl;
    PrintRows(R, 0, rowCount, colCount);

    // Сортування та вивід
    SortRows(R, rowCount, colCount, 0);
    cout << "Sorted Matrix:" << endl;
    PrintRows(R, 0, rowCount, colCount);

    // Обчислення
    int S = 0;
    int k = 0;
    CalcRows(R, 0, rowCount, colCount, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl << endl;

    cout << "Matrix after Calc:" << endl;
    PrintRows(R, 0, rowCount, colCount);

    // Рекурсивне звільнення пам'яті
    FreeRows(R, 0, rowCount);
    delete[] R;

    return 0;
}