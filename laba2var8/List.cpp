#include "List.h"

//конструктор по умолчанию
List::List()
{
	//std::cout << "\n\n";
	size_ = 0;
	head_ = nullptr;
}

//добавление элемента в список
void List::push(TRAIN* data)
{
	if (head_ == nullptr)//если пусто, то делаем первым
	{
		head_ = new Node(data);
		size_++;
	}
	else//иначе ищем последний
	{
		Node *current = head_;
		Node *current_n = current->pNext_;

		if (current->data_->get_hours() > data->get_hours()
			|| (current->data_->get_hours() == data->get_hours()
				&& current->data_->get_minutes() >= data->get_minutes())) // сравниваем по часам, если они равны то сравнив по минутам
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

void List::delet(int num)//удаление элемента по номеру
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
	if (!current_n->pNext_)//если элемент последний в списке
	{
		current->pNext_ = nullptr;
		delete current_n;
	}
	else//если не последний
	{
		current->pNext_ = current_n->pNext_;
		delete current_n;
	}
	size_--;
}

//удаление первого элемента
void List::pop_front()
{
	Node *temp = head_;
	//std::cout << "\npop_front\n";
	if (head_->pNext_ != nullptr)
		head_ = head_->pNext_;

	delete temp;
	size_--;
}

//очистка всего списка
void List::clear()
{
	while (size_)
	{
		//std::cout << size_;
		pop_front();
	}
}

void List::search(char* name)//поиск и вывод
{
	Node *current = head_;
	while (current)
	{
		if (current->data_->comparison(name))
			current->data_->print();
		current = current->pNext_;
	}
}

std::ostream& operator<< (std::ostream& o, const List& obj)//перегрузка вывода
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

//деструктор
List::~List()
{
	std::cout << "\nДеструктор Kreeper\n";
	clear();
}