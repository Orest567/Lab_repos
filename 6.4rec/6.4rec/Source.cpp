#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Формування масиву (рекурсивно)
void CreateRec(double* a, const int size, const double Low, const double High, int i = 0) {
    if (i >= size) {
        return;
    }
    a[i] = Low + (double)rand() / RAND_MAX * (High - Low);
    CreateRec(a, size, Low, High, i + 1);
}

// 2. Виведення масиву (рекурсивно)
void PrintRec(const double* a, const int size, int i = 0) {
    if (i >= size) {
        cout << endl;
        return;
    }
    cout << setw(8) << fixed << setprecision(2) << a[i];
    PrintRec(a, size, i + 1);
}

// 1.1. Індекс мінімального елемента (рекурсивно)
int IndexOfMinRec(const double* a, const int size, int i = 1, int minIndex = 0) {
    if (i >= size) {
        return minIndex;
    }
    if (a[i] < a[minIndex]) {
        minIndex = i;
    }
    return IndexOfMinRec(a, size, i + 1, minIndex);
}

// Допоміжна функція пошуку першого від'ємного
int FindFirstNegRec(const double* a, const int size, int i = 0) {
    if (i >= size) {
        return -1;
    }
    if (a[i] < 0) {
        return i;
    }
    return FindFirstNegRec(a, size, i + 1);
}

// Допоміжна функція пошуку другого від'ємного
int FindSecondNegRec(const double* a, const int size, int firstNeg, int i) {
    if (i >= size) {
        return -1;
    }
    if (a[i] < 0) {
        return i;
    }
    return FindSecondNegRec(a, size, firstNeg, i + 1);
}

// Допоміжна функція обчислення суми між елементами
double SumBetweenRec(const double* a, int firstNeg, int secondNeg, int i) {
    if (i >= secondNeg) {
        return 0.0;
    }
    return a[i] + SumBetweenRec(a, firstNeg, secondNeg, i + 1);
}

// 1.2. Сума елементів між 1-м та 2-м від'ємними (рекурсивно)
double SumBetweenNegativeRec(const double* a, const int size) {
    int firstNeg = FindFirstNegRec(a, size);
    if (firstNeg == -1) {
        return 0.0;
    }

    int secondNeg = FindSecondNegRec(a, size, firstNeg, firstNeg + 1);
    if (secondNeg == -1 || secondNeg - firstNeg <= 1) {
        return 0.0;
    }

    return SumBetweenRec(a, firstNeg, secondNeg, firstNeg + 1);
}

// Допоміжна функція для копіювання елементів за умовою
void FillTempRec(const double* a, double* temp, const int size, int condLess, int& index, int i = 0) {
    if (i >= size) {
        return;
    }

    if (condLess == 1) {
        if (abs(a[i]) <= 1.0) {
            temp[index++] = a[i];
        }
    }
    else {
        if (abs(a[i]) > 1.0) {
            temp[index++] = a[i];
        }
    }

    FillTempRec(a, temp, size, condLess, index, i + 1);
}

// Допоміжна функція для копіювання масиву назад
void CopyBackRec(double* a, const double* temp, const int size, int i = 0) {
    if (i >= size) {
        return;
    }
    a[i] = temp[i];
    CopyBackRec(a, temp, size, i + 1);
}

// 2. Перегрупування масиву (|a[i]| <= 1 першими) (рекурсивно)
void RearrangeRec(double* a, const int size) {
    double* temp = new double[size];
    int index = 0;

    // Спочатку елементи |a[i]| <= 1.0 (передаємо 1)
    FillTempRec(a, temp, size, 1, index);

    // Потім елементи |a[i]| > 1.0 (передаємо 0)
    FillTempRec(a, temp, size, 0, index);

    // Перезапис назад у початковий масив та очищення
    CopyBackRec(a, temp, size);
    delete[] temp;
}

int main() {
    srand((unsigned)time(0));

    int n;
    cout << "Enter n (array size): ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    double* a = new double[n];
    const double LOW = -5.0;
    const double HIGH = 5.0;

    CreateRec(a, n, LOW, HIGH);

    cout << "\nInitial Array:" << endl;
    PrintRec(a, n);

    int minIdx = IndexOfMinRec(a, n);
    cout << "\nIndex of minimum element = " << minIdx << " (Value = " << a[minIdx] << ")" << endl;

    double sum = SumBetweenNegativeRec(a, n);
    cout << "Sum between 1st and 2nd negative elements = " << sum << endl;

    RearrangeRec(a, n);

    cout << "\nModified Array (|a[i]| <= 1 first):" << endl;
    PrintRec(a, n);
    delete[] a;
    a = nullptr;

    return 0;
}