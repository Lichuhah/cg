#include<ctime>
#ifndef  T_END_D
#define  T_END_D



class t_end_d
{
private:
	time_t* time;
public:
	t_end_d();//�� ���������

	t_end_d(const t_end_d& copy); //� ��������� ���� ������

	t_end_d(time_t timeZnach); //�����������

	~t_end_d();

	void OutTime(); //����� 


};
#endif