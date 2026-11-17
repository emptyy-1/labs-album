/*
2. Написать функцию для поиска минимального элемента среди тех, которые лежат
ниже главной и ниже побочной диагонали матрицы. Указатель на матрицу и размерность
передать параметрами.
*/

#include <iostream>
#include <iomanip> // Для std::setw (ровный табличный вывод)
#include <cstdlib>
#include <ctime>
#include <windows.h>

// Принимает линейный указатель на начало матрицы и её размерность n
int findMinBelowDiagonals(int* mat, int n) {
    int minVal = 0;
    bool found = false;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Ниже главной (i > j) И ниже побочной (i + j > n - 1)
            if (i > j && i + j > n - 1) {
                // Построчная индексация двумерного массива через одномерный сдвиг
                int current = mat[i * n + j];

                if (!found || current < minVal) {
                    minVal = current;
                    found = true;
                }
            }
        }
    }

    if (!found) {
        std::cout << "В матрице " << n << "x" << n << " нет элементов ниже обеих диагоналей.\n";
    }

    return minVal;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const int N = 5;
    int mat[N][N];

    // Заполняем матрицу случайными двузначными числами (от 10 до 99)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            mat[i][j] = std::rand() % 90 + 10;
        }
    }

    // Печатаем матрицу ровными столбцами (setw(4) выделяет 4 знакоместа под число)
    std::cout << "Матрица " << N << "x" << N << ":\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(4) << mat[i][j];
        }
        std::cout << '\n';
    }

    // Передаём указатель на первый элемент матрицы и размерность
    int minElem = findMinBelowDiagonals(&mat[0][0], N);

    // В матрицах меньше 3x3 область ниже обеих диагоналей пуста
    if (N >= 3) {
        std::cout << "\nМинимальный элемент ниже главной и побочной диагоналей: " << minElem << '\n';
    }

    return 0;
}
