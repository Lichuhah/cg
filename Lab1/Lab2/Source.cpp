#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "t_end_d.h"
using namespace std;

////////////////Реализация класса t_end_d/////////////////////

t_end_d::t_end_d() {
	time = new time_t(0);
}
t_end_d::t_end_d(const t_end_d& copy) {
	time = new time_t(*copy.time);
}
t_end_d::t_end_d(time_t timeZnach) {
	
	time = new time_t(timeZnach);
}
t_end_d::~t_end_d() {
	delete time;
}
void t_end_d::OutTime() {
	char* t = ctime(time);
	cout << t;
}

/////////////////////////////////////////////////////////////

int main() {
	system("color F0");
	setlocale(LC_ALL, "Russian");
	cout << "Объект класса созданный с конструктором по умолчанию" << endl;
	t_end_d timeClass1;
	timeClass1.OutTime();
	
	cout << "Объект класса созданный с конструктором передачи даты" << endl;
	t_end_d timeClass2(time(0));
	timeClass2.OutTime();

	cout << "Объект класса созданный с конструктором копирования" << endl;
	t_end_d timeClass3(timeClass2);
	timeClass3.OutTime();
	
}