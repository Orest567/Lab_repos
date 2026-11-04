#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** R, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            R[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** R, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << R[i][j];
        cout << endl;
    }
    cout << endl;
}

void Change(int** R, const int col1, const int col2, const int rowCount)
{
    int tmp;
    for (int i = 0; i < rowCount; i++)
    {
        tmp = R[i][col1];
        R[i][col1] = R[i][col2];
        R[i][col2] = tmp;
    }
}

void Sort(int** R, const int rowCount, const int colCount)
{
    for (int j0 = 0; j0 < colCount - 1; j0++)
    {
        for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
        {
            if ((R[0][j1] > R[0][j1 + 1]) ||
                (R[0][j1] == R[0][j1 + 1] && R[1][j1] > R[1][j1 + 1]) ||
                (R[0][j1] == R[0][j1 + 1] && R[1][j1] == R[1][j1 + 1] && R[2][j1] > R[2][j1 + 1]))
            {
                Change(R, j1, j1 + 1, rowCount);
            }
        }
    }
}

void Calc(int** R, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (R[i][j] > 0 || !(R[i][j] % 3 == 0))
            {
                S += R[i][j];
                k++;
                R[i][j] = 0;
            }
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    const int Low = -12;
    const int High = 37;
    const int rowCount = 7;
    const int colCount = 9;

    int** R = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        R[i] = new int[colCount];

    Create(R, rowCount, colCount, Low, High);
    cout << "Pochatkova matrytsya R:";
    Print(R, rowCount, colCount);

    // 2. Впорядкування стовпчиків матриці за ключами: -> -> ->
    Sort(R, rowCount, colCount);
    cout << "Matrytsya R pislya sortuvannya stovpchykiv:";
    Print(R, rowCount, colCount);

    // 3. Обчислення суми, кількості елементів за критерієм та заміщення їх нулями
    int S = 0;
    int k = 0;
    Calc(R, rowCount, colCount, S, k);

    // 4. Виведення результатів та модифікованої матриці
    cout << "Suma elementiv (S) = " << S << endl;
    cout << "Kilkist' elementiv (k) = " << k << endl;
    cout << "Matrytsya R pislya obchyslen' ta obnulennya elementiv:";
    Print(R, rowCount, colCount);

    // Звільнення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] R[i];
    delete[] R;

    return 0;
}