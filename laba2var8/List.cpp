#include "List.h"

//����������� �� ���������
List::List()
{
	//std::cout << "\n\n";
	size_ = 0;
	head_ = nullptr;
}

//���������� �������� � ������
void List::push(TRAIN* data)
{
	if (head_ == nullptr)//���� �����, �� ������ ������
	{
		head_ = new Node(data);
		size_++;
	}
	else//����� ���� ���������
	{
		Node *current = head_;
		Node *current_n = current->pNext_;

		if (current->data_->get_hours() > data->get_hours()
			|| (current->data_->get_hours() == data->get_hours()
				&& current->data_->get_minutes() >= data->get_minutes())) // ���������� �� �����, ���� ��� ����� �� ������� �� �������
		{
			current = new Node(data);
			current->pNext_ = head_;
			head_ = current;
			size_++;
		}
		else
		{
			while (current->pNext_ != 0)
				if (current_n->data_->get_hours() > data->get_hours()
					|| (current_n->data_->get_hours() == data->get_hours()
						&& current->data_->get_minutes() >= data->get_minutes()))
				{
					current->pNext_ = new Node(data);
					current = current->pNext_;
					current->pNext_ = current_n;
					size_++;
					return;
				}
				else
				{
					current = current_n;
					if (current_n->pNext_ != 0)
						current_n = current_n->pNext_;
				}
			current->pNext_ = new Node(data);
			current = current->pNext_;
			current->pNext_ = current_n;
			size_++;
		}
	}
}

void List::delet(int num)//�������� �������� �� ������
{
	if (head_ == nullptr)
		return;
	int count = 0;
	Node *current = head_;
	Node *current_n = head_;
	if (num == current->data_->get_number())
	{
		pop_front();
		return;
	}
	while (num != current_n->data_->get_number())
	{
		current = current_n;
		if (current->pNext_ != 0)
			current_n = current->pNext_;
		count++;

	}
	if (!current_n->pNext_)//���� ������� ��������� � ������
	{
		current->pNext_ = nullptr;
		delete current_n;
	}
	else//���� �� ���������
	{
		current->pNext_ = current_n->pNext_;
		delete current_n;
	}
	size_--;
}

//�������� ������� ��������
void List::pop_front()
{
	Node *temp = head_;
	//std::cout << "\npop_front\n";
	if (head_->pNext_ != nullptr)
		head_ = head_->pNext_;

	delete temp;
	size_--;
}

//������� ����� ������
void List::clear()
{
	while (size_)
	{
		//std::cout << size_;
		pop_front();
	}
}

void List::search(char* name)//����� � �����
{
	Node *current = head_;
	while (current)
	{
		if (current->data_->comparison(name))
			current->data_->print();
		current = current->pNext_;
	}
}

std::ostream& operator<< (std::ostream& o, const List& obj)//���������� ������
{
	int count = 1;
	List::Node *current = obj.head_;
	while (current != 0)
	{
		current->data_->print();
		current = current->pNext_;
	}
	return o;
}

//����������
List::~List()
{
	std::cout << "\n���������� Kreeper\n";
	clear();
}