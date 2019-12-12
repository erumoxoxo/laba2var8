#pragma once
#include <iostream>

#pragma once

const int size = 30;//����� �������� ������ ����������

class TRAIN
{
private:
	char* name_;//�������� ������ ����������
	int number_;//����� ������
	int* time_;//����� �����������
	void copy(char*, char*);//������� ����������� ����� � ������������ � set

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

	bool comparison(char* name);//������������� ����������� �������� � �������� �������
	void print();
	friend std::ostream &operator<< (std::ostream &o, const TRAIN &obj);//����� �� �����, ���������� <<
	~TRAIN();
};
