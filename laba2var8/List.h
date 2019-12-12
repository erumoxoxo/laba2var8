#pragma once
#include "TRAIN.h"
#include <iostream>

#pragma once

class List
{
private:
	class Node//������� ������ "������ + ��������� �� ���������"
	{
	public:
		Node * pNext_;//��������� 
		TRAIN* data_;//������
		Node(TRAIN* data, Node* pNext = nullptr) : data_(data), pNext_(pNext) {}
	};

	Node *head_;
	int size_;


public:
	List();//�����������
	void push(TRAIN* data);//���������� ��������
	void pop_front();//�������� �������
	void delet(int num);//�������� �� ������ ������
	void search(char* name);//�����
	int get_Size() { return size_; };//������� ���������� ���������
	friend std::ostream &operator<< (std::ostream &o, const List &obj);//����� �� �����, ���������� <<
	void clear();//������� ������
	~List();
};
