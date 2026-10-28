#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// --- Звичайні функції ---

// Формування масиву int
void Create(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

// Виведення масиву int
void Print(const int* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(6) << a[i];
    }
    cout << endl;
}

// Звичайна функція обчислення суми додатних елементів
int Sum(const int* a, const int size) {
    int s = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > 0) {
            s += a[i];
        }
    }
    return s;
}

// --- Шаблонні функції ---

// Шаблонне виведення масиву
template <typename T>
void Print(const T* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(6) << a[i];
    }
    cout << endl;
}

// Шаблонна функція обчислення суми додатних елементів
template <typename T>
T Sum(const T* a, const int size) {
    T s = T(); // Ініціалізація нульовим значенням для типу T
    for (int i = 0; i < size; i++) {
        if (a[i] > 0) {
            s += a[i];
        }
    }
    return s;
}

int main() {
    srand((unsigned)time(0));

    const int SIZE = 10;
    const int LOW = -10;
    const int HIGH = 10;

    // 1. Опрацювання звичайною функцією
    int a[SIZE];
    Create(a, SIZE, LOW, HIGH);
    cout << "Array a (int):" << endl;
    Print(a, SIZE);

    int s1 = Sum(a, SIZE);
    cout << "Sum (Ordinary function) = " << s1 << endl << endl;

    // 2. Опрацювання шаблонною функцією (int)
    int s2 = Sum<int>(a, SIZE);
    cout << "Sum<int> (Template)     = " << s2 << endl << endl;

    // 3. Опрацювання шаблонною функцією (double)
    double b[SIZE] = { -2.5, 3.1, -0.4, 5.2, -8.0, 1.5, 0.0, -1.2, 4.4, -3.3 };
    cout << "Array b (double):" << endl;
    Print<double>(b, SIZE);

    double s3 = Sum<double>(b, SIZE);
    cout << "Sum<double> (Template)  = " << s3 << endl;

    return 0;
}