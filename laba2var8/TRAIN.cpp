#include "TRAIN.h"
#include <iomanip>


TRAIN::TRAIN() : name_(new char[ssize]), number_(0), time_(new int[2]) {}

TRAIN::TRAIN(char* name, int number, int* time) : name_(new char[ssize]), number_(number), time_(new int[2]) 
{
	copy(name_, name);
	*time_ = *time;
	*(time_ + 1) = *(time + 1);
}

TRAIN::TRAIN(const TRAIN& obj) : name_(new char[ssize]), number_(obj.number_), time_(new int[2])
{
	copy(name_, obj.name_);
	*time_ = obj.time_[0];
	*(time_ + 1) = obj.time_[1];
}

void TRAIN::copy(char* str1, char* str2)
{
	for (int i = 0; i < ssize; i++)
		*(str1 + i) = *(str2 + i);
}

char* TRAIN::get_name(){
	return name_;
}

int TRAIN::get_number(){
	return number_;
}

int TRAIN::get_hours(){
	return time_[0];
}

int TRAIN::get_minutes(){
	return time_[1];
}

void TRAIN::set_name(char* name){
	copy(name_, name);
}

void TRAIN::set_number(int number){
	number_ = number;
}

void TRAIN::set_time(int* time){
	*time_ = *time;
	*(time_ + 1) = *(time + 1);
}

bool TRAIN::comparison(char* name)
{
	int i = 0;
	do	{
		if (!(*(name_ + i) == *(name + i)))
			return 0;
		i++;
	} while (*(name + i) != '\0');
	return 1;
}

std::ostream& operator<< (std::ostream& o, const TRAIN& obj)//????? ???
{
	using namespace std;
	cout << setw(2) << obj.time_[0] << " " << setw(2) << obj.time_[1] << "  ";
	cout << obj.name_ << setw(20);
	cout << obj.number_ << setw(5);
	cout << endl;
	return o;
}

void TRAIN::print()
{
	using namespace std;
	cout << setw(2) << time_[0] << " " << setw(2) << time_[1] << "  ";
	cout << name_ << setw(20);
	cout << number_ << setw(5);
	cout << endl;
}

TRAIN::~TRAIN()
{
}