/* В группе обучается 11 студентов. Программа должна считывать итоговые оценки (от 0 до 10), 
введённые пользователем с клавиатуры, сохранять их в массив и определять
количество учащихся, сдавших экзамен на отлично. Если число отличников равно 0, вывод надписи: группа не обучаема! */

#include <iostream>
#include <clocale>
 
int main() {
    
	std::setlocale(LC_ALL, "Russian");

	int students[11];
	int count = 0;

	std::cout << "Введите 11 оценок:\n ";

	for (int i = 0; i < 11; i = i + 1) {
		std::cin >> students[i];

		while (students[i] < 0 || students[i] > 10) {
			std::cout << "Ошибка! Оценка от 0 до 10. Попробуйте ещё раз.\n";
			std::cin >> students[i];
		}
	}
	
	for (int i = 0; i < 11; i = i + 1) {
		if (students[i] == 10) {
			count = count + 1;
		}
	}

	std::cout << "Число отличников: " << count; '\n';

	if (count == 0) {
		std::cout << "\tГруппа необучаема!";
	}

	return 0;
}