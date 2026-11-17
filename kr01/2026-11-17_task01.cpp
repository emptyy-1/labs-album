/* 1 Написать функцию для сжатия отсортированного по невозрастанию массива, оставив каждое число ровно1 раз. Массив предать в функцию с помощью указателя. Дополнительного массива не использовать.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int compressArray(int* arr, int n) {
	if (n <= 0) {
		return 0;
	}
	int k = 1;

	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[k - 1]) {
			arr[k] = arr[i];
			k++;
		}
	}

	return k;
}

int main(void) {

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	srand((unsigned int)time(NULL));

	const int N = 10;

	int arr[N];

	arr[0] = rand() % 21 + 10;
	for (int i = 1; i < N; i++) {
		arr[i] = arr[i - 1] - (rand() % 4);
	}

	printf("Исходный массив: ");
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	int new_n = compressArray(arr, N);

	printf("Новая длина: %d\n", new_n);
	printf("Сжатый массив: ");
	for (int i = 0; i < new_n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}