#pragma once
#include "tripInfo.h"

class CoverTrip{
private:
	TripInfo* arrayTrip; //��������� ��� ������� �������. ����������
	int numberOfRecords; //���-�� ���������
	int currentIndex; //����� �������� ��������
	void checkFullMass() {	//�������� �� ������������ �������. ���������� ������ ���������� �������� � ������������ �������
		if (currentIndex == numberOfRecords) cout << "checkFullMass: ������ ��������! " << endl;
	}
public:
	CoverTrip(int _numberOfRecords) { //����������� � ����������. ���-��� ���������
		numberOfRecords = _numberOfRecords; //���������� ���-�� ���������
		arrayTrip = new TripInfo[numberOfRecords]; //�������������� ��������. �������������
	}
	void add(TripInfo& element) { //���������� � ������ ��������
		if (currentIndex < numberOfRecords) //���� �� � �������� �������
			arrayTrip[currentIndex++] = element; //�������� ������� �������� � ������, ����� �������� ������� ���������
		checkFullMass();//�������� �� ������������ �������.
	}
	void add(int _freeSeat, const char* _destination, int _hour, int _minute) {//���������� � ������ �������� ����� ��� ���������
		if (currentIndex < numberOfRecords)//���� �� � �������� �������
			arrayTrip[currentIndex++] = TripInfo(_freeSeat, _destination, _hour, _minute); //��������� � ������ ��������� �������, ��������� ������������� � ����������� ������ tripInfo
		checkFullMass();//�������� �� ������������ �������.
	}
	void addKey() {
		if (currentIndex < numberOfRecords) {//���� �� � �������� �������
			TripInfo tempInfo;	//������� ��������� �������
			tempInfo.inputInfo(); //�������� ��� ���� ���� � ����������
			arrayTrip[currentIndex++] = tempInfo; //��������� ���� �������
		}
		checkFullMass();//�������� �� ������������ �������.
	}
	void deleteElement(int number) {
		if ((number < currentIndex) && (number >= 0)) { //���� ������� � ������� number ��������� � �������� �������
			for (int i = number; i < currentIndex - 1; i++) //���� � ���������� �������� �� ���������� ����� ����
				arrayTrip[i] = arrayTrip[i + 1]; //���������� ���������� ���������
			currentIndex--; //��������� ������� ���������
			cout << "������� ������� ������." << endl;
		}
		else
			cout << "������� ��� ������, ��������� �������." << endl;
	}
	void displayArray() {	//����� �������
		if (currentIndex != 0) { //���� ������ �� ������
			for (int i = 0; i < currentIndex; i++) {
				cout << i + 1 << ". "; arrayTrip[i].showInfo();	
			}
		}
		else
			cout << "������ ������!" << endl;
	}
};
