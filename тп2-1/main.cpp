#include "Group.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(Marray<Group>& groups);
void changeObject(Marray<Group>& groups);
void deleteObject(Marray<Group>& groups);
void print(Marray<Group>& groups);
void searchObject(Marray<Group>& groups);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Marray<Group> groups;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 5);
		switch (method)
		{
		case 1:
			addObject(groups);
			break;
		case 2:
			changeObject(groups);
			break;
		case 3:
			deleteObject(groups);
			break;
		case 4:
			print(groups);
			break;
		case 5:
			searchObject(groups);
			break;
		case 0:

			isExit = true;
			break;
		}
	}

}

void printMenu() {
	cout << "1. �������� ������" << endl;
	cout << "2. �������� ������" << endl;
	cout << "3. ������� ������" << endl;
	cout << "4. ������� ������" << endl;
	cout << "5. ������� ������� �������� � ������ �����, ���� ������� ���� �������� ������ 4.0" << endl;
	cout << "0. �����" << endl;
	cout << "�������� ����� ����: ";
}

void addObject(Marray<Group>& groups) {
	Group group;
	group.inputFromConsole();
	groups += group;
	groups.sort();
}

void changeObject(Marray<Group>& groups) {
	if (groups.getSize() > 0) {
		print(groups);
		cout << "������� ����� ������ ��� ���������: ";
		groups[safeInput(1, groups.getSize()) - 1].change();
	}
	else
		cout << "������ ����� ����. ������ ��������\n";
	groups.sort();
}

void deleteObject(Marray<Group>& groups) {
	if (groups.getSize() > 0) {
		print(groups);
		cout << "������� ����� ������ ��� ��������: ";
		groups -= safeInput(1, groups.getSize()) - 1;
	}
	else
		cout << "������ ����� ����. ������ �������\n";
	groups.sort();
}

void print(Marray<Group>& groups) {
	if (groups.getSize() == 0)
		cout << "������ ����� ����.\n";
	else {
		cout << "������ �����\n";
		for (int i = 0; i < groups.getSize(); i++) {
			cout << i + 1 << ". ������\n";
			groups[i].printToConsole();
		}
	}
}

void searchObject(Marray<Group>& groups) {
	if (groups.getSize() == 0)
		cout << "������ ����� ����\n";
	else {
		bool isPrint = false;
		for (int i = 0; i < groups.getSize(); i++) {
			Marray<Student> students = groups[i].getStudents();
			for (int j = 0; j < students.getSize(); j++)
				if (students[j].getAverageMark() > 4.0) {
					isPrint = true;
					cout << groups[i].getNumber() << " " << students[j].getSecondName() << endl;
				}
		}
			
		if (!isPrint)
			cout << "��������� �� ������� ������ ������ 4.0 ���\n";
	}
}