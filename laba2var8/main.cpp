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
		cout << "Время отправления(2 числа через пробел): ";
		cin >> time[0] >> time[1];
		if (time[0] < 0 || time[1] < 0 || 23 < time[0] || 59 < time[1])
		{
			cout << "Ошибка: введите значения для часов 0 - 23, для минут 0 - 59";
			cout << "\n Введено: " << time[0] << " " << time[1];
			system("pause");
			continue;
		}

		try{
			cout << "Номер поезда: ";
			cin >> num;
		}
		catch (...)
		{
			cin.clear();
			cout << "Ошибка: Введено неккоректное значение (введите число)";
			system("pause");
			continue;
		}

		cout << "Пункт назначения: ";
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
	cout << "Выберите действие\n";
	cout << "0.Выход\n";
	cout << "1.Добавить запись\n";
	cout << "2.Удалить запись\n";
	cout << "3.Вывести весь список\n";
	cout << "4.Поиск поездов по пункту назначения\n";
	cout << "\nПункт меню: ";
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
		cout << "Ошибка: Введено неверное значение (введите 0-4)" << menu;
		system("pause");
	}
	catch (char)
	{
		cout << "Ошибка: Введено неверное значение (введите цифру)" << menu;
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
				cout << "Введите номер поезда для удаления: ";
				cin >> menu;
				list.delet(menu);
			}
			else
				cout << "В списке нет записей!\n";
			break;
		case 3:
			cout << list;
			system("pause");
			break;
		case 4:
		{
			system("cls");
			cout << "Введите название пункта назначения: ";
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
		cout << "Выберите действие\n";
		cout << "0.Выход\n";
		cout << "1.Добавить запись\n";
		cout << "2.Удалить запись\n";
		cout << "3.Вывести весь список\n";
		cout << "4.Поиск поездов по пункту назначения\n";
		cout << "\nПункт меню: ";
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
			cout << "Ошибка: Введено неверное значение (введите 0-5)" << menu;
			system("pause");
		}
		catch (char)
		{
			cout << "Ошибка: Введено неверное значение (введите цифру)" << menu;
			system("pause");
		}
	}
}