#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

// Константы управляющих ANSI-последовательностей для оформления интерфейса
const char* RESET_COLOR = "\033[0m";
const char* COLOR_RED = "\033[91m"; // Выделение при необходимости перестановки
const char* COLOR_GREEN = "\033[92m"; // Выделение при правильном порядке
const char* COLOR_CYAN = "\033[96m"; // Цвет информационных надписей
const char* COLOR_GRAY = "\033[90m"; // Нейтральный цвет для пассивных элементов
const char* COLOR_GOLD = "\033[93m"; // Цвет итогового массива

// Очистка строки от курсора до правого края (предотвращает наложение старого текста)
const char* CLEAR_LINE = "\033[K";

// Функция приостановки выполнения потока на заданное количество миллисекунд
void delayMs(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

// Первичная полная очистка терминала и перевод курсора в левый верхний угол (1,1)
void initScreen() {
    std::cout << "\033[2J\033[H" << std::flush;
}

// Возврат курсора в начало без стирания всего буфера (исключает мерцание экрана)
void resetCursor() {
    std::cout << "\033[H" << std::flush;
}

// Отрисовка текущего состояния массива с подсветкой двух сравниваемых индексов
void drawArray(const int arr[], int size, int index1, int index2, const char* highlightColor) {
    std::cout << "Элементы: ";
    for (int i = 0; i < size; ++i) {
        if (i == index1 || i == index2) {
            // Вывод активных элементов с заливкой переданным цветом и квадратными скобками
            std::cout << highlightColor << "[" << arr[i] << "]" << RESET_COLOR << " ";
        }
        else {
            // Пассивные элементы выводятся нейтральным цветом
            std::cout << COLOR_GRAY << " " << arr[i] << " " << RESET_COLOR << " ";
        }
    }
    std::cout << CLEAR_LINE << "\n";
}

// Отрисовка статического кадра интерфейса
void renderFrame(const int arr[], int size, int pass, int totalPasses,
    int index1, int index2, const char* highlightColor,
    const std::string& statusMessage, int sortType) {
    resetCursor();

    std::cout << COLOR_CYAN << "======================== ВИЗУАЛИЗАЦИЯ СОРТИРОВКИ ПУЗЫРЬКОМ ========================" << RESET_COLOR << CLEAR_LINE << "\n";
    std::cout << "Режим: " << (sortType == 0 ? "По возрастанию" : "По убыванию")
        << " | Проход: " << pass << " из " << totalPasses << CLEAR_LINE << "\n";
    std::cout << COLOR_GRAY << "-----------------------------------------------------------------------------------" << RESET_COLOR << CLEAR_LINE << "\n";

    drawArray(arr, size, index1, index2, highlightColor);

    std::cout << COLOR_GRAY << "-----------------------------------------------------------------------------------" << RESET_COLOR << CLEAR_LINE << "\n";
    std::cout << "Статус: " << highlightColor << statusMessage << RESET_COLOR << CLEAR_LINE << "\n";
    std::cout << std::flush;
}

int main() {
    std::setlocale(LC_ALL, ".UTF-8");
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const int n = 15;
    int a[n];
    int original[n]; // Массив для сохранения исходного состояния

    // Заполнение массива случайными двузначными числами
    for (int i = 0; i < n; ++i) {
        a[i] = 10 + std::rand() % 90;
        original[i] = a[i]; // Резервное копирование
    }

    std::cout << "Выберите тип сортировки (0 - по возрастанию, 1 - по убыванию): ";
    int choice = 0;
    std::cin >> choice;
    while (choice < 0 || choice > 1) {
        std::cout << "Некорректный ввод. Введите 0 или 1: ";
        std::cin >> choice;
    }

    // Задержка анимации в миллисекундах (800 мс оптимально для плавного восприятия)
    const int stepDelay = 10;

    initScreen();

    // Алгоритм пузырьковой сортировки с пошаговой отрисовкой
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; ++j) {
            // Определение необходимости обмена в зависимости от выбранного режима
            bool needSwap = (choice == 0) ? (a[j] > a[j + 1]) : (a[j] < a[j + 1]);

            if (needSwap) {
                // Кадр 1: Подсветка элементов красным перед обменом
                renderFrame(a, n, i + 1, n - 1, j, j + 1, COLOR_RED,
                    "Порядок нарушен. Требуется перестановка!", choice);
                delayMs(stepDelay);

                // Физический обмен значений в памяти
                std::swap(a[j], a[j + 1]);
                swapped = true;

                // Кадр 2: Фиксация выполненного обмена на экране
                renderFrame(a, n, i + 1, n - 1, j, j + 1, COLOR_RED,
                    "Значения успешно поменяны местами.", choice);
                delayMs(stepDelay);
            }
            else {
                // Кадр: Подсветка элементов зеленым при корректном порядке
                renderFrame(a, n, i + 1, n - 1, j, j + 1, COLOR_GREEN,
                    "Порядок верный. Перестановка не требуется.", choice);
                delayMs(stepDelay);
            }
        }

        // Досрочный выход, если массив уже отсортирован
        if (!swapped) {
            break;
        }
    }

    // Итоговый вывод результатов после завершения сортировки
    initScreen();
    std::cout << COLOR_CYAN << "=============================== СОРТИРОВКА ЗАВЕРШЕНА ================================" << RESET_COLOR << CLEAR_LINE << "\n\n";

    std::cout << "Исходный массив:        ";
    for (int i = 0; i < n; ++i) {
        std::cout << original[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Отсортированный массив: " << COLOR_GOLD;
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << RESET_COLOR << "\n\n";

    return 0;
}
