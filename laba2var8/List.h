#pragma once
#include "TRAIN.h"
#include <iostream>

#pragma once

class List
{
private:
	class Node//элемент списка "данные + указатель на следующий"
	{
	public:
		Node * pNext_;//указатель 
		TRAIN* data_;//данные
		Node(TRAIN* data, Node* pNext = nullptr) : data_(data), pNext_(pNext) {}
	};

	Node *head_;
	int size_;


public:
	List();//конструктор
	void push(TRAIN* data);//добавление элемента
	void pop_front();//удаление первого
	void delet(int num);//удаление по номеру поезда
	void search(char* name);//поиск
	int get_Size() { return size_; };//возврат количества элементов
	friend std::ostream &operator<< (std::ostream &o, const List &obj);//вывод на экран, перегрузка <<
	void clear();//очистка списка
	~List();
};
