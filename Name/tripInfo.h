#pragma once
#include <iostream>

using namespace std;

class TripInfo {
private:
	int freeSeat; // Кол-во свободных мест
	const char* destination; // Пункт назначения
	int hour, minute; //Время. Часы и минуты
public:
	TripInfo() { //Конструктор без параметров (по умолчанию).
		freeSeat = -1;
		destination = "---";
		hour = -1;
		minute = -1;
	}
	TripInfo(int _freeSeat, const char* _destination, int _hour, int _minute) { //Конструктор с параметрами: кол-во мест, пункт, время
		freeSeat = _freeSeat;
		destination = _destination;
		hour = _hour;
		minute = _minute;
	}

	void inputInfo() { //Ввод данных с клавиатуры
		char* tempDest = new char[80];
		cout << "Введите пункт назначения: "; cin.getline(tempDest, 80);
		destination = tempDest;

		cout << "Введите время (формат: часы минуты): "; cin >> hour; cin >> minute;
		cout << "Введите кол-во свободных мест: "; cin >> freeSeat;
		cout << "\nЭлемент с клавиатуры успешно введен!\n";
	}

	void inputInfo(int _freeSeat, const char* _destination, int _hour, int _minute) { // Ввод данных с параметрами
		freeSeat = _freeSeat;
		destination = _destination;
		hour = _hour;
		minute = _minute;
	}

	void showInfo() {  //Вывод информации
		cout << "Рейс в пункт назначения " << destination <<
			" со временем отправления " << hour << " : " << minute <<
			".\nИмеет " << freeSeat << " свободных мест." << endl;
	}

	//Перегрузка операторов. Вторая лабораторная работа.
	bool operator==(TripInfo& secondElement) {  //Перегруженный оператор сравнения. На вход принимает ссылку на элемент для сравнения.
		if (freeSeat != secondElement.freeSeat) return false; //Если какое-то значение переменных не сходится, вохвращаем false (не равны)
		if (strcmp(destination, secondElement.destination)) return false;
		if (hour != secondElement.hour) return false;
		if (minute != secondElement.minute) return false;
		return true; //Если все элементы прошли проверку, возвращаем true (равны)
	}

	bool operator!=(TripInfo& secondElement) {
		return !operator==(secondElement); //Возвращаем обратный результат равенства. ! - логическое отрицание(инверсия)

	}

	//Именованные свойства (get и set). Требование третей лаб-ой работы

	void setFreeSeat(int value) { freeSeat = value; };
	void setDestination(const char* value) { destination = value; };
	void setHour(int value) { hour = value; };
	void setMinute(int value) { minute = value; };

	int getFreeSeat() { return freeSeat; };
	const char* getDestination() { return destination; };
	int getHour() { return hour; };
	int getMinute() { return minute; };

 };