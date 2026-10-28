#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* b, const int size, const int Low, const int High, int i = 0) {
    b[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1) {
        Create(b, size, Low, High, i + 1); 
    }
}

void Print(const int* b, const int size, int i = 0) {
    cout << setw(5) << b[i];
    if (i < size - 1) {
        Print(b, size, i + 1); 
    }
    else {
        cout << endl; 
    }
}

int IsCriterionSatisfied(int number) {
    if (number % 2 == 0 && number <= 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int Count(const int* b, const int size, int i = 0) {
    if (i >= size) {
        return 0; // Базовий випадок: вийшли за межі масиву
    }
    // Поточний елемент + результат для решти масиву
    return IsCriterionSatisfied(b[i]) + Count(b, size, i + 1);
}

int Sum(const int* b, const int size, int i = 0) {
    if (i >= size) {
        return 0;
    }
    if (IsCriterionSatisfied(b[i]) == 1) {
        return b[i] + Sum(b, size, i + 1);
    }
    else {
        return 0 + Sum(b, size, i + 1);
    }
}
// Рекурсивна заміна елементів нулями
void Zero(int* b, const int size, int i = 0) {
    if (i >= size) {
        return;
    }
    if (IsCriterionSatisfied(b[i])) {
        b[i] = 0; 
    }
    Zero(b, size, i + 1); // Переходимо до наступного елемента
}

int main() {
    srand(time(0));

    const int SIZE = 24;
    const int LOW = -15;
    const int HIGH = 75;

    int b[SIZE];

    // 1. Формування та виведення початкового масиву
    Create(b, SIZE, LOW, HIGH);
    cout << "Original array:" << endl;
    Print(b, SIZE);

    // 2. Обчислення кількості та суми
    int count = Count(b, SIZE);
    int sum = Sum(b, SIZE);

    // 3. Заміна елементів нулями
    Zero(b, SIZE);

    // 4. Виведення результатів
    cout << "Results:" << endl;
    cout << "Count = " << count << endl;
    cout << "Sum   = " << sum << endl;

    // 5. Виведення модифікованого масиву
    cout << "Modified array:" << endl;
    Print(b, SIZE);

    return 0;
}