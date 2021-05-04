#pragma once
#include <iostream>

using namespace std;

class TripInfo {
private:
	int freeSeat; // ���-�� ��������� ����
	const char* destination; // ����� ����������
	int hour, minute; //�����. ���� � ������
public:
	TripInfo() { //����������� ��� ���������� (�� ���������).
		freeSeat = -1;
		destination = "---";
		hour = -1;
		minute = -1;
	}
	TripInfo(int _freeSeat, const char* _destination, int _hour, int _minute) { //����������� � �����������: ���-�� ����, �����, �����
		freeSeat = _freeSeat;
		destination = _destination;
		hour = _hour;
		minute = _minute;
	}

	void inputInfo() { //���� ������ � ����������
		char* tempDest = new char[80];
		cout << "������� ����� ����������: "; cin.getline(tempDest, 80);
		destination = tempDest;

		cout << "������� ����� (������: ���� ������): "; cin >> hour; cin >> minute;
		cout << "������� ���-�� ��������� ����: "; cin >> freeSeat;
		cout << "\n������� � ���������� ������� ������!\n";
	}

	void inputInfo(int _freeSeat, const char* _destination, int _hour, int _minute) { // ���� ������ � �����������
		freeSeat = _freeSeat;
		destination = _destination;
		hour = _hour;
		minute = _minute;
	}

	void showInfo() {  //����� ����������
		cout << "���� � ����� ���������� " << destination <<
			" �� �������� ����������� " << hour << " : " << minute <<
			".\n����� " << freeSeat << " ��������� ����." << endl;
	}

	//���������� ����������. ������ ������������ ������.
	bool operator==(TripInfo& secondElement) {  //������������� �������� ���������. �� ���� ��������� ������ �� ������� ��� ���������.
		if (freeSeat != secondElement.freeSeat) return false; //���� �����-�� �������� ���������� �� ��������, ���������� false (�� �����)
		if (strcmp(destination, secondElement.destination)) return false;
		if (hour != secondElement.hour) return false;
		if (minute != secondElement.minute) return false;
		return true; //���� ��� �������� ������ ��������, ���������� true (�����)
	}

	bool operator!=(TripInfo& secondElement) {
		return !operator==(secondElement); //���������� �������� ��������� ���������. ! - ���������� ���������(��������)

	}

	//����������� �������� (get � set). ���������� ������ ���-�� ������

	void setFreeSeat(int value) { freeSeat = value; };
	void setDestination(const char* value) { destination = value; };
	void setHour(int value) { hour = value; };
	void setMinute(int value) { minute = value; };

	int getFreeSeat() { return freeSeat; };
	const char* getDestination() { return destination; };
	int getHour() { return hour; };
	int getMinute() { return minute; };

 };