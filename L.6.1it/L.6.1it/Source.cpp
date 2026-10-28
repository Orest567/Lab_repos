#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

void Create(int* b, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        b[i] = Low + rand() % (High - Low + 1);
    }
}

void Print(const int* b, const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(5) << b[i];
    }
    std::cout << std::endl;
}

int IsCriterionSatisfied(int number) {
    if (number % 2 == 0 && number <= 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int Count(const int* b, const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (IsCriterionSatisfied(b[i]) == 1) {
            count++;
        }
    }
    return count;
}

int Sum(const int* b, const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (IsCriterionSatisfied(b[i]) == 1) {
            sum += b[i];
        }
    }
    return sum;
}

void Zero(int* b, const int size) {
    for (int i = 0; i < size; i++) {
        if (IsCriterionSatisfied(b[i]) == 1) {
            b[i] = 0;
        }
    }
}

int main() {
    srand(time(0));

    const int SIZE = 24;
    const int LOW = -15;
    const int HIGH = 75;

    int b[SIZE];

    // 1. Формування та виведення початкового масиву
    Create(b, SIZE, LOW, HIGH);
    std::cout << "Original array:" << std::endl;
    Print(b, SIZE);

    // 2. Обчислення кількості та суми
    int count = Count(b, SIZE);
    int sum = Sum(b, SIZE);

    // 3. Заміна елементів нулями
    Zero(b, SIZE);

    // 4. Виведення результатів
    std::cout << "\nResults:" << std::endl;
    std::cout << "Count = " << count << std::endl;
    std::cout << "Sum   = " << sum << std::endl;

    // 5. Виведення модифікованого масиву
    std::cout << "\nModified array:" << std::endl;
    Print(b, SIZE);

    return 0;
}