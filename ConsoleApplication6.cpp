#define _CRT_SECURE_NO_WARNINGS // Исправление ошибок fopen

#include <stdio.h>
#include <locale.h>
#include <windows.h> // Подключение библиотек
#include <time.h>

void customselectionSort(int array[], int n) { // Функция сортировки
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}

		int temp = array[i];
		array[i] = array[minIndex];
		array[minIndex] = temp;
	}
}

int main()
{
	int n; // Обозначение переменных
	int  MIN_VALUE;
	int  MAX_VALUE;

	setlocale(LC_ALL, "RUS"); // Локализация Русского языка

	printf("Введите нужное количество данных (n>0): ");
	scanf("%ld", &n); // Ввод кол-ва данных
	printf("\nВведите минимальное значение (максимальная разность 32500): ");
	scanf("%ld", &MIN_VALUE); // Ввод минимального значения данных
	printf("\nВведите максимальное значение: ");
	scanf("%ld", &MAX_VALUE); // Ввод максимального значения данных

	int* array = NULL;
	array = (int*)malloc(n * sizeof(int)); // Создание неотсортированного массива

	FILE* record = fopen("Data.txt", "w"); // Открытие файла

	if (record == NULL) {
		printf("Ошибка открытия файла.\n"); // Проверка на открытие файла
	}

	srand(time(NULL));

	for (int i = 0; i < n; i++) { // Цикл заполнения файла
		int number = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
		array[i] = number; // Заполнение неотсортированного массива
		fprintf(record, "%ld\n", number); // Запись данных в файл
	}

	fclose(record); // Закрытие файла

	clock_t start = clock(); // Запуск таймера

	customselectionSort(array, n); // Вызов функции сортировки

	clock_t end = clock(); // Остановка таймера

	double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Вычисление времени выполнения

	printf("Время выполнения программы: %.2f секунд\n", time_taken);

	FILE* sorted = fopen("Sorted.txt", "w"); // Открытие файла для записи отсортированных данных

	for (int i = 0; i < n; i++) { // Цикл заполнения отсортированного файла
		fprintf(sorted, "%ld\n", array[i]);
	}

	fclose(sorted); // Закрытие файла для записи отсортированных данных

	system("pause"); // Остановка программы

	free(array); // Высвобождение памяти

	return 0;
}
