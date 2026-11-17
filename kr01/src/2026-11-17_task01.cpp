/*
1. Написать функцию для сжатия отсортированного по невозрастанию массива,
оставив каждое число ровно 1 раз. Массив передать в функцию с помощью указателя.
Дополнительного массива не использовать.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>

// Сжимает отсортированный массив на месте и возвращает новую логическую длину
int compressArray(int* arr, int n) {
    if (n <= 0) {
        return 0;
    }

    // k — индекс для записи следующего уникального числа (элемент 0 всегда уникален)
    int k = 1;

    for (int i = 1; i < n; ++i) {
        // Сравниваем текущий элемент с последним записанным в сжатую часть
        if (arr[i] != arr[k - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }

    return k;
}

int main() {
    std::setlocale(LC_ALL, ".UTF-8");
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const int N = 10;
    int arr[N];

    // Генерируем невозрастающую последовательность (вычитание 0 создает дубликаты)
    arr[0] = std::rand() % 21 + 10;
    for (int i = 1; i < N; ++i) {
        arr[i] = arr[i - 1] - (std::rand() % 4);
    }

    std::cout << "Исходный массив: ";
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    // Имя массива преобразуется в указатель на его первый элемент
    int new_n = compressArray(arr, N);

    std::cout << "Новая длина: " << new_n << '\n';
    // Выводим только первые new_n элементов, игнорируя остаток памяти в хвосте
    std::cout << "Сжатый массив: ";
    for (int i = 0; i < new_n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
