#include "tripInfo.h"
#include "coverTrip.h"
#include <Windows.h>

//Функции для вызова тел лабораторных работ.
void labNumber1(); 
void labNumber2();
void labNumber3();

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//Вызов лабораторных работ
	labNumber1(); //Вызов фунции с содержимым 1 лабораторной работы. 
	labNumber2(); //Вызов фунции с содержимым 2 лабораторной работы. 
	labNumber3(); //Вызов фунции с содержимым 3 лабораторной работы. 
}

void labNumber1() {
	//Лабораторная работа номер 1.
	cout << "Начало работы первой лабораторной работы!" << endl;
	//Инициализация объекта класса при помощи конструктора с параметрами.
	TripInfo oneTrip(12, "Киров", 13, 13);
	oneTrip.showInfo(); //Вывод этого объекта

	const int n = 5;	//Размерность динамического массива объектов
	TripInfo* arrayTrips = new TripInfo[n]; //Инициализация динамического массива. 
												//Выделение памяти для n элементов, с присвоением значений по умолчанию

	//Заполнение массива
	arrayTrips[0].inputInfo(5, "Москва", 20, 15);
	arrayTrips[1].inputInfo(20, "Владивосток", 05, 12);
	arrayTrips[2].inputInfo(0, "Краснодар", 16, 45);
	arrayTrips[3].inputInfo(24, "Батайск", 18, 00);
	arrayTrips[4].inputInfo(1, "Казань", 11, 10);

	//Вывод массива
	cout << "\nМассив объектов:\n";
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". "; arrayTrips[i].showInfo();
	}
}

void labNumber2() {
	cout << "\n\nНачало работы второй лабораторной работы!" << endl;
	//Инициализация 3 объектов класса при помощи конструктора с параметрами.
	TripInfo first(12, "Киров", 13, 13);
	TripInfo second(12, "Киров", 13, 13);
	TripInfo thrid(0, "Москва", 10, 15);

	if (first == second) // first == thrid - false
		cout << "Объекты равны!" << endl;
	else
		cout << "Объектры отличаются!" << endl;
}

void labNumber3() {
	cout << "\n\nНачало работы третьей лабораторной работы!" << endl;
	const int k = 3; //Количество элементов массива в классе обертке
	TripInfo oneTrip(12, "Киров", 13, 13); //Некий объект класса для функции add

	CoverTrip coverTrip(k); //Вызов конструктора класса обертки с параметром - кол-во элементов
	coverTrip.add(20, "Владивосток", 05, 12); //Добавление по параметрам
	coverTrip.add(oneTrip); //Добавление по объекту класса tripInfo
	coverTrip.addKey(); //Добавление вводом с клавиатуры

	coverTrip.displayArray(); //Отобразить массив до удаления
	coverTrip.deleteElement(1); //Удалить элемент с номером 1. По факту второй, отсчет от нуля
	cout << "___________________________" << endl;
	coverTrip.displayArray(); //отобразить после удаления
}

