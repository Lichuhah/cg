#include<iostream>
using namespace std;

class GeomPr {
private:
	int a0, q;
public:
	void set(int counta, int countq) {
		a0 = counta;
		q = countq;
	}

	int Elementi(int num) {
		int Element;
		int qi=1;
		for (int i = 0; i < num; i++) {
			qi *= q;
		}
		Element = a0 * qi;
		return Element;
	}
};

int main() {

	system("color F0");
	setlocale(LC_ALL, "Russian");
	GeomPr Progr;

	cout << "������� ������ ������� ���������� � ���������" << endl;
	int counta, countq;
	cin >> counta >> countq;
	Progr.set(counta, countq);

	cout << "������� ������� ������� ����������" << endl;
	int num;
	cin >> num;
	cout<<endl<<num<<"-�� ������� ����������: "<<Progr.Elementi(num);
}

