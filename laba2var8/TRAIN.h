#pragma once
#include <iostream>

#pragma once

const int size = 30;//длина названия пункта назначения

class TRAIN
{
private:
	char* name_;//название пункта назначения
	int number_;//номер поезда
	int* time_;//время отправления
	void copy(char*, char*);//функция копирования строк в конструкторе и set

public:
	TRAIN();
	TRAIN(char*, int, int*);
	TRAIN(const TRAIN&);

	char* get_name();
	int get_number();
	int get_hours();
	int get_minutes();

	void set_name(char*);
	void set_number(int);
	void set_time(int*);

	bool comparison(char* name);//сопоставление переданного названия и названия объекта
	void print();
	friend std::ostream &operator<< (std::ostream &o, const TRAIN &obj);//вывод на экран, перегрузка <<
	~TRAIN();
};
