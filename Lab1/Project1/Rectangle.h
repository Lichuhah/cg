#pragma once

struct Point {
	int x;
	int y;
};

struct Side {
	Point point0;
	Point point1;
};

class Rectangle{
public:
	Rectangle(); //���������� �� ���������
	Rectangle(Point point0in, Point point1in, Point point2in, Point point3in); //����������� � ��������� ����������
	~Rectangle(); //����������
	int sideLength(Side side); //���������� ����� �������
	int perimeter(); //���������� ���������
	Rectangle operator* (Rectangle rec1); //����������� ���������������
	friend bool operator== (Rectangle rec1, Rectangle rec2); //�������� �� ��������� ����������
	bool operator|= (Rectangle rec1); //�������� �� ������� ����������� ������
	void showpoints();//�������� ����� ��������������

private:

	Point points[4]; //��������� ����� ��������������
	Side  sides[4]; //��������� ������ ��������������
};