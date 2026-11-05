#include "pch.h"
#include "CppUnitTest.h"

#define main f_main
#include "../7.1rec/Source.cpp" 
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRecursive
{
    TEST_CLASS(UnitTestRecursive)
    {
    public:

        TEST_METHOD(TestCalcRowsRecursive)
        {
            // Готуємо тестову матрицю 2x2
            const int rowCount = 2;
            const int colCount = 2;

            int** R = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                R[i] = new int[colCount];

            // Заповнюємо тестовими даними:
            // R[0][0] = 5  (додатне -> підходить)
            // R[0][1] = -3 (від'ємне і кратне 3 -> НЕ підходить)
            // R[1][0] = -4 (від'ємне, але НЕ кратне 3 -> підходить)
            // R[1][1] = 0  (не > 0 і кратне 3 -> НЕ підходить)
            R[0][0] = 5;
            R[0][1] = -3;
            R[1][0] = -4;
            R[1][1] = 0;

            int S = 0;
            int k = 0;

            // Викликаємо рекурсивну функцію CalcRows
            CalcRows(R, 0, rowCount, colCount, S, k);

            // 1. Перевіряємо суму: 5 + (-4) = 1
            Assert::AreEqual(1, S);

            // 2. Перевіряємо кількість підхожих елементів: 2
            Assert::AreEqual(2, k);

            // 3. Перевіряємо, чи підхожі елементи обнулилися
            Assert::AreEqual(0, R[0][0]);
            Assert::AreEqual(0, R[1][0]);

            // 4. Перевіряємо, чи неподхожі елементи залишилися без змін
            Assert::AreEqual(-3, R[0][1]);
            Assert::AreEqual(0, R[1][1]);

            // Звільняємо пам'ять через рекурсивну функцію FreeRows
            FreeRows(R, 0, rowCount);
            delete[] R;
        }
    };
}