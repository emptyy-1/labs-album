#include <iostream>
#include <cstring>  

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // Задаем символьные массивы с запасом по размеру
    char B[1000]; // Текст
    char A[100];  // Искомое слово

    cout << "Введите текст (массив Б):\n";
    // Используем cin.getline, иначе обычный cin оборвется на первом же пробеле
    cin.getline(B, 1000);

    cout << "Введите искомое слово (массив А): ";
    cin.getline(A, 100);


    int lenB = strlen(B);
    int lenA = strlen(A);

    // Проверка: слово не может быть длиннее самого текста
    if (lenA == 0 || lenA > lenB) {
        cout << "Количество вхождений: 0\n";
        return 0;
    }

    int count = 0;

    // 3. Алгоритм поиска подстроки
    // Внешний цикл бежит по тексту B.
    // Ограничение (lenB - lenA), так как дальше слово физически не поместится.
    for (int i = 0; i <= lenB - lenA; i++) {
        bool match = true;

        // Внутренний цикл сравнивает символы слова A с текущим фрагментом текста B
        for (int j = 0; j < lenA; j++) {
            if (B[i + j] != A[j]) {
                match = false; // Нашли несовпадение — выходим из сравнения
                break;
            }
        }

        // Если все символы совпали, увеличиваем счетчик
        if (match) {
            count++;
        }
    }

    cout << "\nКоличество вхождений слова \"" << A << "\" в текст: " << count << '\n';

    return 0;
}