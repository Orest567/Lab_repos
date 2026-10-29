#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Формування масиву випадковими дійсними числами
void Create(double* a, const int size, const double Low, const double High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + (double)rand() / RAND_MAX * (High - Low);
    }
}

// 2. Форматне виведення масиву
void Print(const double* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(8) << fixed << setprecision(2) << a[i];
    }
    cout << endl;
}

// 1.1. Номер (індекс) мінімального елемента масиву
int IndexOfMin(const double* a, const int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (a[i] < a[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// 1.2. Сума елементів між першим і другим від'ємними елементами
double SumBetweenNegative(const double* a, const int size) {
    int firstNeg = -1;
    int secondNeg = -1;

    for (int i = 0; i < size; i++) {
        if (a[i] < 0) {
            if (firstNeg == -1) {
                firstNeg = i;
            }
            else if (secondNeg == -1) {
                secondNeg = i;
                break;
            }
        }
    }

    if (firstNeg == -1  secondNeg == -1  secondNeg - firstNeg <= 1) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = firstNeg + 1; i < secondNeg; i++) {
        sum += a[i];
    }

    return sum;
}

// 2. Модифікація масиву зі збереженням відносного порядку
void Rearrange(double* a, const int size) {
    double* temp = new double[size];
    int index = 0;

    for (int i = 0; i < size; i++) {
        if (abs(a[i]) <= 1.0) {
            temp[index++] = a[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (abs(a[i]) > 1.0) {
            temp[index++] = a[i];
        }
    }

    for (int i = 0; i < size; i++) {
        a[i] = temp[i];
    }

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

    Create(a, n, LOW, HIGH);
    cout << "\nInitial Array:" << endl;
    Print(a, n);

    int minIdx = IndexOfMin(a, n);
    cout << "\nIndex of minimum element = " << minIdx << " (Value = " << a[minIdx] << ")" << endl;

    double sum = SumBetweenNegative(a, n);
    cout << "Sum between 1st and 2nd negative elements = " << sum << endl;

    Rearrange(a, n);
    cout << "\nModified Array (|a[i]| <= 1 first):" << endl;
    Print(a, n);

    delete[] a;
    a = nullptr;

    return 0;
}