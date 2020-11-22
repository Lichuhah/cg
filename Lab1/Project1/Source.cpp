#include "Rectangle.h";
#include <iostream>

using namespace std;

////////////////////////////реализация класса Rectangle/////////////////////////////////////////

Rectangle::Rectangle() {
	Point temppoint;
	temppoint.x = 0;
	temppoint.y = 0;
	points[0] = temppoint;
	temppoint.x = 1;
	temppoint.y = 0;
	points[1] = temppoint;
	temppoint.x = 1;
	temppoint.y = 1;
	points[2] = temppoint;
	temppoint.x = 0;
	temppoint.y = 1;
	points[3] = temppoint;
	Side tempside;
	tempside.point0 = points[0];
	tempside.point1 = points[1];
	sides[0] = tempside;
	tempside.point0 = points[1];
	tempside.point1 = points[2];
	sides[1] = tempside;
	tempside.point0 = points[2];
	tempside.point1 = points[3];
	sides[2] = tempside;
	tempside.point0 = points[3];
	tempside.point1 = points[0];
	sides[3] = tempside;
}

Rectangle::Rectangle(Point point0in, Point point1in, Point point2in, Point point3in) {
	points[0] = point0in;
	points[1] = point1in;
	points[2] = point2in;
	points[3] = point3in;
	Side tempside;
	tempside.point0 = points[0];
	tempside.point1 = points[1];
	sides[0] = tempside;
	tempside.point0 = points[1];
	tempside.point1 = points[2];
	sides[1] = tempside;
	tempside.point0 = points[2];
	tempside.point1 = points[3];
	sides[2] = tempside;
	tempside.point0 = points[3];
	tempside.point1 = points[0];
	sides[3] = tempside;
}

Rectangle::~Rectangle() {

}

int Rectangle::sideLength(Side side) {
	int len;
	int temp;
	Point point0 = side.point0;
	Point point1 = side.point1;
	if (point0.x == point1.x) 
	{
		if (point0.y > point1.y) {
			len = point0.y - point1.y;
		}
		else {
			len = point1.y - point0.y;
		}
	}
	else 
	{
		if (point0.x > point1.x) {
			len = point0.x - point1.x;
		}
		else {
			len = point1.x - point0.x;
		}
	}
	return len;
}
 
int Rectangle::perimeter() {
	int per=0;
	for (int i = 0; i < 4; i++) {
		per += sideLength(sides[i]);
	}
	
	return per;
}

bool operator==(Rectangle rec1, Rectangle rec2) {
	if (rec1.perimeter() == rec2.perimeter()) {
		return true;
	}
	else {
		return false;
	}
}

bool Rectangle::operator|=(Rectangle rec1) {
	Side tempsidethis;
	Side tempsiderec;
	for (int i = 0; i < 4; i++) {
		tempsidethis = this->sides[i];
		for (int j = 0; j < 4; j++) {
			tempsiderec = rec1.sides[j];
			if (sideLength(tempsidethis) == sideLength(tempsiderec)) {
				if (tempsidethis.point0.x == tempsiderec.point1.x && tempsidethis.point0.y == tempsiderec.point1.y) {
					if (tempsidethis.point1.x == tempsiderec.point0.x && tempsidethis.point1.y == tempsiderec.point0.y) {
						cout <<"Совпадают стороны:" << i << "и" << j << endl;
						return true;
					}
				}
				if (tempsidethis.point0.x == tempsiderec.point0.x && tempsidethis.point1.y == tempsiderec.point1.y) {
					if (tempsidethis.point1.x == tempsiderec.point1.x && tempsidethis.point1.y == tempsiderec.point1.y) {
						cout << "Совпадают стороны:" << i << "и" << j << endl;
						return true;
					}
				}
			}
			else {
				cout << "Нет совпадающих сторон" << endl;
			}
		}
	}
	//cout << "Совпадающих сторон нет";
	return NULL;
}

Rectangle Rectangle::operator*(Rectangle rec1) {
	int side1=0, side2=0;
	Point point0, point1, point2, point3;
	Side tempsidethis;
	Side tempsiderec;
	for (int i = 0; i < 4; i++) {
		tempsidethis = this->sides[i];
		for (int j = 0; j < 4; j++) {
			tempsiderec = rec1.sides[j];
			if (sideLength(tempsidethis) == sideLength(tempsiderec)) {
				if (tempsidethis.point0.x == tempsiderec.point1.x && tempsidethis.point0.y == tempsiderec.point1.y) {
					if (tempsidethis.point1.x == tempsiderec.point0.x && tempsidethis.point1.y == tempsiderec.point0.y) {
						side1 = j;
					}
				}
				if (tempsidethis.point0.x == tempsiderec.point0.x && tempsidethis.point1.y == tempsiderec.point1.y) {
					if (tempsidethis.point1.x == tempsiderec.point1.x && tempsidethis.point1.y == tempsiderec.point1.y) {
						side1 = j;
					}
				}
			}
		}
	}
	switch (side1) {
	case 0: 
		point0.x = this->points[0].x;
		point0.y = this->points[0].y;
		point1.x = this->points[1].x;
		point1.y = this->points[1].y;
		point2.x = rec1.points[2].x;
		point2.y = rec1.points[2].y;
		point3.x = rec1.points[3].x;
		point3.y = rec1.points[3].y;
		break;
	case 1:
		point0.x = rec1.points[0].x;
		point0.y = rec1.points[0].y;
		point1.x = this->points[1].x;
		point1.y = this->points[1].y;
		point2.x = this->points[2].x;
		point2.y = this->points[2].y;
		point3.x = rec1.points[3].x;
		point3.y = rec1.points[3].y;
		break;
	case 2:
		
		point0.x = rec1.points[0].x;
		point0.y = rec1.points[0].y;
		point1.x = rec1.points[1].x;
		point1.y = rec1.points[1].y;
		point2.x = this->points[2].x;
		point2.y = this->points[2].y;
		point3.x = this->points[3].x;
		point3.y = this->points[3].y;
		break;
	case 3:
		
		point0.x = this->points[0].x;
		point0.y = this->points[0].y;
		point1.x = rec1.points[1].x;
		point1.y = rec1.points[1].y;
		point2.x = rec1.points[2].x;
		point2.y = rec1.points[2].y;
		point3.x = this->points[3].x;
		point3.y = this->points[3].y;
		break;
	}
	Rectangle temp(point0, point1, point2, point3);
	return temp;
}

void Rectangle::showpoints() {
	for (int i = 0; i < 4; i++) {
		cout << "" << i << ": x:" << points[i].x << " y:" << points[i].y<<endl;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	setlocale(LC_ALL, "Rus");
	system("color F0");
	cout << "Введите левую нижнюю точку:"<<endl;
	Point point1;
	cin >> point1.x;
	cin >> point1.y;
	cout << "Введите правую нижнюю точку:" << endl;
	Point point2;
	cin >> point2.x;
	cin >> point2.y;
	cout << "Введите правую верхнюю точку:" << endl;
	Point point3;
	cin >> point3.x;
	cin >> point3.y;
	cout << "Введите левую верхнюю точку:" << endl;
	Point point4;
	cin >> point4.x;
	cin >> point4.y;

	Rectangle rec(point1, point2, point3, point4);
	Rectangle recdefault;
	cout << "Точки прямоугольника по умолчанию:" << endl;
	recdefault.showpoints();
	cout << "Периметр прямоугольника по умолчанию:" << recdefault.perimeter() << endl;
	cout << "Точки вашего прямоугольника:" << endl;
	rec.showpoints();
	cout << "Периметр вашего прямоугольника:" << rec.perimeter() << endl;
	if (rec|= recdefault) {
		Rectangle recsum = rec * recdefault;
		cout << "Точки объединенного прямоугольника:" << endl;
		recsum.showpoints();
		cout << "Периметр объединенного прямоугольника:" << recsum.perimeter() << endl;
	}

	return 0;
}