#include <iostream>
#include <cmath>
#include <windows.h>

int main() {
    setlocale(LC_ALL, ".UTF-8");

    double x = 0.0;
    int k = 0;

    while (true) {
        std::cout << "Введите x: ";
        if (std::cin >> x) {
            break;
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: некорректный ввод x. Попробуйте снова.\n";
    }

    while (true) {
        std::cout << "Введите натуральное k (для точности 10^-k): ";
        if (std::cin >> k && k > 0) {
            break;
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка: k должно быть натуральным числом (k > 0). Попробуйте снова.\n";
    }

    if (std::abs(x) > 25.0) {
        std::cout << "Предупреждение: при |x| > 25 возможна потеря точности из-за ограничений типа double.\n";
    }

    double epsilon = 1.0;
    for (int i = 0; i < k; i++) {
        epsilon = epsilon / 10.0;
    }

    double sum = 0.0;
    double term = 1.0;
    double n = 2.0; 
    int count = 0;

    while (std::abs(term) >= epsilon) {
        sum = sum + term;
        count++;

        term = -term * (x * x) / ((n - 1.0) * n);
        n = n + 2.0;
    }

    double standard = std::cos(x);
    double diff = std::abs(sum - standard);

    std::cout << "\n--- Результаты ---\n";
    std::cout << "Вычислено слагаемых:   " << count << '\n';
    std::cout << "Сумма ряда Тейлора:    " << sum << '\n';
    std::cout << "Табличный cos(x):      " << standard << '\n';
    std::cout << "Разность (погрешность): " << diff << '\n';

    return 0;
}
