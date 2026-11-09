/*
Задание: Группа 6 ОиМП
Составить программу расчета площади объекта.
Описание объекта состоит из набора геометрических фигур:
1) Круг
2) Треугольник (правильный)
3) Квадрат
4) Прямоугольник
5) Узор 10 на 10
6) Шестиугольник (правильный)

Требования:
- Шаблон функции (sumAreas)
- Перегрузка функций (getArea)
- Массив указателей на функцию (handlers)
Фигуры не накладываются, выводить рисунок в консоль не нужно.
*/

#include <iostream>
#include <clocale>
#include <cmath>

// 1. Шаблон функции для суммирования площадей массива любого числового типа
template <typename T>
T sumAreas(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

// 2. Семейство перегруженных функций getArea под каждый тип фигуры

// Круг: S = pi * r^2
double getArea(double radius, double pi) {
    return pi * radius * radius;
}

// Правильный треугольник: S = (sqrt(3) / 4) * a^2
double getArea(int side) {
    return (std::sqrt(3.0) / 4.0) * side * side;
}

// Квадрат: S = a^2
double getArea(double side) {
    return side * side;
}

// Прямоугольник: S = a * b
double getArea(int height, int width) {
    return static_cast<double>(height * width);
}

// Узор 10х10: подсчет количества единиц (каждая дает площадь 1)
double getArea(int matrix[10][10]) {
    int countOnes = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (matrix[i][j] == 1) {
                countOnes++;
            }
        }
    }
    return static_cast<double>(countOnes);
}

// Правильный шестиугольник: S = (3 * sqrt(3) / 2) * a^2
double getArea(double side, int vertices) {
    return (side * side * 3.0 * std::sqrt(3.0)) / 2.0;
}

// 3. Подпрограммы ввода размеров без мусорных координат

double processCircle() {
    double radius;
    const double PI = 3.141592653589793;

    std::cout << "Введите радиус круга: ";
    std::cin >> radius;

    return getArea(radius, PI);
}

double processTriangle() {
    int side; // тип int обеспечивает вызов getArea(int side) для треугольника

    std::cout << "Введите длину стороны треугольника (целое число): ";
    std::cin >> side;

    return getArea(side);
}

double processSquare() {
    double side; // тип double обеспечивает вызов getArea(double side) для квадрата

    std::cout << "Введите сторону квадрата: ";
    std::cin >> side;

    return getArea(side);
}

double processRectangle() {
    int width, height;

    std::cout << "Введите ширину и высоту прямоугольника (целые числа): ";
    std::cin >> width >> height;

    return getArea(height, width);
}

double processPattern() {
    int matrix[10][10];

    std::cout << "Введите элементы матрицы 10х10 (0 или 1, всего 100 чисел):\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    return getArea(matrix);
}

double processHexagon() {
    double side;

    std::cout << "Введите длину стороны правильного шестиугольника: ";
    std::cin >> side;

    return getArea(side, 6);
}

// 4. Определение типа указателя на функцию и массива обработчиков
typedef double (*FigureFunc)();

FigureFunc handlers[] = {
    processCircle,
    processTriangle,
    processSquare,
    processRectangle,
    processPattern,
    processHexagon
};

int main() {
    setlocale(LC_ALL, ".UTF-8");

    int figureCount = 0;
    std::cout << "Из скольких фигур состоит объект? ";
    std::cin >> figureCount;

    if (figureCount <= 0) {
        std::cout << "Ошибка: число фигур должно быть больше нуля.\n";
        return 1;
    }

    // Динамический массив под площади каждой фигуры
    double* areas = new double[figureCount];

    for (int i = 0; i < figureCount; ++i) {
        std::cout << "\n--- Фигура #" << (i + 1) << " ---\n";
        std::cout << "1. Круг\n";
        std::cout << "2. Правильный треугольник\n";
        std::cout << "3. Квадрат\n";
        std::cout << "4. Прямоугольник\n";
        std::cout << "5. Узор 10х10\n";
        std::cout << "6. Шестиугольник\n";
        std::cout << "Выберите тип фигуры (1-6): ";

        int choice = 0;
        std::cin >> choice;

        if (choice < 1 || choice > 6) {
            std::cout << "Неверный пункт! Повторите ввод для этой фигуры.\n";
            --i;
            continue;
        }

        // Вызов функции ввода через массив указателей по индексу
        areas[i] = handlers[choice - 1]();
        std::cout << "-> Площадь текущей фигуры: " << areas[i] << "\n";
    }

    // Вызов шаблона функции для расчета общей суммы
    double totalArea = sumAreas(areas, figureCount);

    std::cout << "\n============================================\n";
    std::cout << "ОБЩАЯ ПЛОЩАДЬ ОБЪЕКТА: " << totalArea << "\n";
    std::cout << "============================================\n";

    delete[] areas;
    return 0;
}
