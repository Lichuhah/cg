#include<ctime>
#ifndef  T_END_D
#define  T_END_D



class t_end_d
{
private:
	time_t* time;
public:
	t_end_d();//по умолчанию

	t_end_d(const t_end_d& copy); //с передачей сист времеи

	t_end_d(time_t timeZnach); //копирование

	~t_end_d();

	void OutTime(); //вывод 


};
#endif