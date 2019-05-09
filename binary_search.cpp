// binary_search.cpp : Defines the entry point for the console application.

#include <iostream>

#define MAX_ELEMENT 1000

int main(int argc, char** argv)
{
	srand(time(0));
	// размер массива
	int count = rand() % MAX_ELEMENT;

	// массив ключей основной таблицы
	int *k = new int[count];

	// массив записей основной таблицы
	int *r = new int[count];

	int key = 0;
	int total = 0;

	// задаем левую и правую границы поиска
	int left = 0;
	int right = count - 1;

	// сколько итераций затрачено
	int iter = 0;

	// найденный индекс элемента равен -1 (элемент не найден)
	int search = -1; 

	system("chcp 1251"); // перевод русского языка в консоли

	// Инициализация ключевых полей упорядоченными значениями
	k[0] = 8;
	for (int i = 1; i < count; ++i)
	{
		k[i] = k[i - 1] + rand() % 10;
		total = k[i];
	}

	// Ввод записей
	for (int i = 0; i < count; i++) 
	{
		r[i] = i * i;
		std::cout << i << ". k[" << i << "] = " << k[i] << ": r[" << i << "] = " << r[i] << '\n';
	}

	std::cout << "Ключ: ";
	key = k[rand() % count];
	std::cout << total << '\n';

	// пока левая граница не "перескочит" правую
	while (left <= right) 
	{
		iter++;
		int mid = (left + right) / 2; // ищем середину отрезка
		if (key == k[mid]) {  // если ключевое поле равно искомому
			search = mid;     // мы нашли требуемый элемент,
			break;            // выходим из цикла
		}

		if (key < k[mid])     // если искомое ключевое поле меньше найденной середины
			right = mid - 1;  // смещаем правую границу, продолжим поиск в левой части
		else                  // иначе
			left = mid + 1;   // смещаем левую границу, продолжим поиск в правой части
	}

	// если индекс элемента по-прежнему -1, элемент не найден
	if (search == -1)     
		std::cout << "Элемент не найден!" << '\n';
	// иначе выводим элемент, его ключ и значение
	else
		std::cout << search << ". key = " << k[search] << ". r[" << search << "] = " << r[search] << '\n';
		std::cout << "Итераций: " << iter << '\n';
		std::cout << "Ключ: " << key << '\n';
	
	return 0;
}

