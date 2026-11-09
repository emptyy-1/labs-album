#include <iostream>
#include <cstdlib> 
#include <ctime>   

using std::cin;
using std::cout;
using std::flush;

// Размеры холста
const int CANVAS_H = 20; // 20 строк в высоту
const int CANVAS_W = 60; // 60 символов в ширину

int main() {
    setlocale(LC_ALL, ".UTF-8");

    // Инициализируем генератор случайных чисел текущим временем
    srand(time(NULL));

    int n = 0;
    cout << "Введите количество прямоугольников (до 25): ";
    cin >> n;

    // Ограничение на ввод
    while (n < 1 || n > 25) {
        cout << "Ошибка: число должно быть в диапазоне от 1 до 25!\n";
        cout << "Введите количество прямоугольников (до 25): ";
        cin >> n;
    }

    // 1. Создаем холст и заполняем его нулями 
    int canvas[CANVAS_H][CANVAS_W];
    for (int y = 0; y < CANVAS_H; y++) {
        for (int x = 0; x < CANVAS_W; x++) {
            canvas[y][x] = 0;
        }
    }

    // 2. Набор ANSI-кодов фоновых цветов (12 ярких цветов)
    int colors[12] = { 41, 42, 43, 44, 45, 46, 101, 102, 103, 104, 105, 106 };

    // 3. Генерируем прямоугольники и сразу наносим их на холст
    for (int i = 0; i < n; i++) {
        // Случайный размер: ширина от 4 до 18, высота от 2 до 8
        int w = 4 + rand() % 15;
        int h = 2 + rand() % 7;

        // Координаты рассчитываются так, чтобы фигура не вылезла за край
        int startX = rand() % (CANVAS_W - w + 1);
        int startY = rand() % (CANVAS_H - h + 1);

        // Случайный цвет из массива colors
        int currentColor = colors[rand() % 12];

        // Закрашиваем область. Если ячейка уже была закрашена, она перезапишется!
        for (int y = startY; y < startY + h; y++) {
            for (int x = startX; x < startX + w; x++) {
                canvas[y][x] = currentColor;
            }
        }
    }

    // Очищаем экран перед показом
    cout << "\033[2J\033[H" << flush;

    // 4. Отрисовываем получившийся холст
    for (int y = 0; y < CANVAS_H; y++) {
        for (int x = 0; x < CANVAS_W; x++) {
            if (canvas[y][x] == 0) {
                // Пустая клетка (серая точка на темном фоне)
                cout << '.';
            }
            else {
                // Цветной блок пробела
                cout << "\033[" << canvas[y][x] << "m \033[0m";
            }
        }
        cout << '\n';
    }

    return 0;
}
