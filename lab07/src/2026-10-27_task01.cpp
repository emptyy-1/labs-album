#include <iostream>
#include <clocale>
#include <cmath> // Подключена для std::sqrt(3.0)

// 1. ТРЕБОВАНИЕ: ШАБЛОН ФУНКЦИИ
// Универсальная функция для суммирования элементов массива любого числового типа
template <typename T>
T sumAreas(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

// 2. ТРЕБОВАНИЕ: ПЕРЕГРУЗКА ФУНКЦИЙ 
// Одно имя getArea, но строго уникальные наборы аргументов под каждую фигуру

// 1. Квадрат: целая сторона (int)
double getArea(int side) {
    return static_cast<double>(side * side);
}

// 2. Правильный треугольник: дробная сторона (double)
// Формула: (sqrt(3) / 4) * a^2
double getArea(double side) {
    return (std::sqrt(3.0) / 4.0) * side * side;
}

// 3. Прямоугольник: целые ширина и высота (int, int)
double getArea(int width, int height) {
    return static_cast<double>(width * height);
}

// 4. Круг: дробные радиус и число Пи (double, double)
// Формула: pi * r^2
double getArea(double radius, double pi) {
    return pi * radius * radius;
}

// 5. Правильный шестиугольник: сторона и число вершин = 6 (double, int)
// Формула: 6 равносторонних треугольников -> (3 * sqrt(3) / 2) * a^2
double getArea(double side, int vertices) {
    return (3.0 * std::sqrt(3.0) / 2.0) * side * side;
}

// 6. Узор 10х10: двумерный массив (int[10][10])
// Подсчет количества единиц по условию ТЗ
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

// ФУНКЦИИ-ОБРАБОТЧИКИ ВВОДА
// Считывают координаты (по ТЗ) и размеры, затем вызывают нужный getArea

double processCircle() {
    int x, y;
    double radius;
    const double PI = 3.141592653589793;

    std::cout << "Введите координаты центра (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите радиус круга: ";
    std::cin >> radius;

    return getArea(radius, PI);
}

double processTriangle() {
    int x, y;
    double side;

    std::cout << "Введите координаты вершины (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите сторону правильного треугольника: ";
    std::cin >> side;

    return getArea(side);
}

double processSquare() {
    int x, y;
    int side;

    std::cout << "Введите координаты угла (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите сторону квадрата (целое число): ";
    std::cin >> side;

    return getArea(side);
}

double processRectangle() {
    int x, y;
    int width, height;

    std::cout << "Введите координаты угла (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите ширину и высоту (целые числа): ";
    std::cin >> width >> height;

    return getArea(width, height);
}

double processPattern() {
    int x, y;
    int matrix[10][10];

    std::cout << "Введите координаты угла узора (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите матрицу 10х10 (100 чисел: 0 или 1):\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    return getArea(matrix);
}

double processHexagon() {
    int x, y;
    double side;

    std::cout << "Введите координаты центра (x y): ";
    std::cin >> x >> y;
    std::cout << "Введите сторону правильного шестиугольника: ";
    std::cin >> side;

    return getArea(side, 6);
}

// 3. МАССИВ УКАЗАТЕЛЕЙ НА ФУНКЦИИ

// Синоним типа: указатель на функцию без аргументов, возвращающую double
typedef double (*FigureFunc)();

// Массив из 6 указателей, инициализированный адресами функций
FigureFunc handlers[] = {
    processCircle,     // handlers[0] -> пункт 1
    processTriangle,   // handlers[1] -> пункт 2
    processSquare,     // handlers[2] -> пункт 3
    processRectangle,  // handlers[3] -> пункт 4
    processPattern,    // handlers[4] -> пункт 5
    processHexagon     // handlers[5] -> пункт 6
};

// ТОЧКА ВХОДА В ПРОГРАММУ

int main() {
    setlocale(LC_ALL, ".UTF-8");

    int figureCount = 0;
    std::cout << "Из скольких фигур состоит объект? ";
    std::cin >> figureCount;

    if (figureCount <= 0) {
        std::cout << "Ошибка: число фигур должно быть больше нуля.\n";
        return 1;
    }

    // Динамический массив под площади
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

        int choice;
        std::cin >> choice;

        if (choice < 1 || choice > 6) {
            std::cout << "Неверный пункт! Повторите ввод фигуры.\n";
            --i;
            continue;
        }

        // Вызов функции через массив указателей
        areas[i] = handlers[choice - 1]();
        std::cout << "-> Посчитанная площадь фигуры: " << areas[i] << "\n";
    }

    // Вызов шаблона функции
    double totalArea = sumAreas(areas, figureCount);

    std::cout << "\n============================================\n";
    std::cout << "ОБЩАЯ ПЛОЩАДЬ ОБЪЕКТА: " << totalArea << "\n";
    std::cout << "============================================\n";

    // Очистка динамической памяти
    delete[] areas;

    return 0;
}
