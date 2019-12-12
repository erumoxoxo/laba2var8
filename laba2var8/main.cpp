#include <iostream>
#include "List.h"

using namespace std;

TRAIN* add()
{
	char* name = new char[ssize];
	int time[2];
	int num;
	do{
		system("cls");
		cout << "����� �����������(2 ����� ����� ������): ";
		cin >> time[0] >> time[1];
		if (time[0] < 0 || time[1] < 0 || 23 < time[0] || 59 < time[1])
		{
			cout << "������: ������� �������� ��� ����� 0 - 23, ��� ����� 0 - 59";
			cout << "\n �������: " << time[0] << " " << time[1];
			system("pause");
			continue;
		}

		try{
			cout << "����� ������: ";
			cin >> num;
		}
		catch (...)
		{
			cin.clear();
			cout << "������: ������� ������������ �������� (������� �����)";
			system("pause");
			continue;
		}

		cout << "����� ����������: ";
		cin.get();
		cin.getline(name, ssize);
		break;
	} while (true);

	TRAIN* obj = new TRAIN(name, num, time);
	delete[] name;
	return obj;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int menu;
	List list;
	cout << "�������� ��������\n";
	cout << "0.�����\n";
	cout << "1.�������� ������\n";
	cout << "2.������� ������\n";
	cout << "3.������� ���� ������\n";
	cout << "4.����� ������� �� ������ ����������\n";
	cout << "\n����� ����: ";
	try{
		if (!(cin >> menu))
		{
			throw 't';
			cin.clear();
		}
		if (menu < 0 || 4 < menu)
			throw - 1;
	}
	catch (int)
	{
		cout << "������: ������� �������� �������� (������� 0-4)" << menu;
		system("pause");
	}
	catch (char)
	{
		cout << "������: ������� �������� �������� (������� �����)" << menu;
		system("pause");
	}

	while (menu){
		switch (menu)
		{
		case 1:
			list.push(add());
			break;
		case 2:
			cout << list;
			if (list.get_Size())
			{
				cout << "������� ����� ������ ��� ��������: ";
				cin >> menu;
				list.delet(menu);
			}
			else
				cout << "� ������ ��� �������!\n";
			break;
		case 3:
			cout << list;
			system("pause");
			break;
		case 4:
		{
			system("cls");
			cout << "������� �������� ������ ����������: ";
			cin.get();
			char* name = new char[ssize];
			cin.getline(name, ssize);
			list.search(name);
			system("pause");
		}
		default:
			break;
		}
		system("cls");
		cout << "�������� ��������\n";
		cout << "0.�����\n";
		cout << "1.�������� ������\n";
		cout << "2.������� ������\n";
		cout << "3.������� ���� ������\n";
		cout << "4.����� ������� �� ������ ����������\n";
		cout << "\n����� ����: ";
		try{
			if (!(cin >> menu))
			{
				throw 't';
				cin.clear();
			}
			if (menu < 0 || 4 < menu)
				throw - 1;
		}
		catch (int)
		{
			cout << "������: ������� �������� �������� (������� 0-5)" << menu;
			system("pause");
		}
		catch (char)
		{
			cout << "������: ������� �������� �������� (������� �����)" << menu;
			system("pause");
		}
	}
}