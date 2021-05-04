#pragma once
#include "tripInfo.h"

class CoverTrip{
private:
	TripInfo* arrayTrip; //Указатель для массива объетов. Обьявление
	int numberOfRecords; //Кол-во элементов
	int currentIndex; //Номер текущего элемента
	void checkFullMass() {	//Проверка на наполненость массива. Сравниваем индекс последнего элемента с размерностью массива
		if (currentIndex == numberOfRecords) cout << "checkFullMass: Массив наполнен! " << endl;
	}
public:
	CoverTrip(int _numberOfRecords) { //Конструктор с параметром. Кол-вом элементов
		numberOfRecords = _numberOfRecords; //Обозначаем кол-во элементов
		arrayTrip = new TripInfo[numberOfRecords]; //Инициализируем элементы. Инициализация
	}
	void add(TripInfo& element) { //Добавление в массив элемента
		if (currentIndex < numberOfRecords) //Если мы в пределах массива
			arrayTrip[currentIndex++] = element; //Сохраням внешний аргумент в массив, после увеличив счетчик элементов
		checkFullMass();//Проверка на наполненость массива.
	}
	void add(int _freeSeat, const char* _destination, int _hour, int _minute) {//Добавление в массив элемента через его аргументы
		if (currentIndex < numberOfRecords)//Если мы в пределах массива
			arrayTrip[currentIndex++] = TripInfo(_freeSeat, _destination, _hour, _minute); //Сохраняем в массив анонимный элемент, созданный конструктором с параметрами класса tripInfo
		checkFullMass();//Проверка на наполненость массива.
	}
	void addKey() {
		if (currentIndex < numberOfRecords) {//Если мы в пределах массива
			TripInfo tempInfo;	//Создаем временный элемент
			tempInfo.inputInfo(); //Вызываем для него ввод с клавиатуры
			arrayTrip[currentIndex++] = tempInfo; //Сохраняем этот элемент
		}
		checkFullMass();//Проверка на наполненость массива.
	}
	void deleteElement(int number) {
		if ((number < currentIndex) && (number >= 0)) { //Если элемент с номером number находится в границах массива
			for (int i = number; i < currentIndex - 1; i++) //Цикл с выбранного элемента до последнего минус один
				arrayTrip[i] = arrayTrip[i + 1]; //Предыдущий становится следующим
			currentIndex--; //Уменьшаем счетчик элементов
			cout << "Элемент успешно удален." << endl;
		}
		else
			cout << "Элемент вне масива, повторите попытку." << endl;
	}
	void displayArray() {	//Вывод массива
		if (currentIndex != 0) { //Если массив не пустой
			for (int i = 0; i < currentIndex; i++) {
				cout << i + 1 << ". "; arrayTrip[i].showInfo();	
			}
		}
		else
			cout << "Массив пустой!" << endl;
	}
};
