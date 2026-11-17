/*2 Написать функцию для поиска минимального элемента среди тех, которые лежат ниже главной и ниже побочной диагонали матрицы.Указатель на матрицу и размерность передать пераметрами.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Принимает указатель на начало матрицы и её размерность n
int findMinBelowDiagonals(int* mat, int n) {
    int minVal = 0;
    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Ниже главной (i > j) И ниже побочной (i + j > n - 1)
            if (i > j && i + j > n - 1) {
                int current = mat[i * n + j];

                if (!found || current < minVal) {
                    minVal = current;
                    found = true;
                }
            }
        }
    }

    if (!found) {
        printf("В матрице %dx%d нет элементов ниже обеих диагоналей.\n", n, n);
    }

    return minVal;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    srand((unsigned int)time(NULL));

    const int N = 5;
    int mat[N][N];

    // Заполняем матрицу случайными двузначными числами (от 10 до 99)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = rand() % 90 + 10;
        }
    }

    // Печатаем матрицу ровными столбцами (%4d выделяет 4 символа под число)
    printf("Матрица %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }

    // Передаём указатель на первый элемент матрицы и размерность
    int minElem = findMinBelowDiagonals(&mat[0][0], N);

    if (N >= 3) {
        printf("\nМинимальный элемент ниже главной и побочной диагоналей: %d\n", minElem);
    }

    return 0;
}
