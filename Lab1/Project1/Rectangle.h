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
	Rectangle(); //конструтор по умолчанию
	Rectangle(Point point0in, Point point1in, Point point2in, Point point3in); //конструктор с передачей параметров
	~Rectangle(); //деструктор
	int sideLength(Side side); //вычисление длины стороны
	int perimeter(); //вычисление периметра
	Rectangle operator* (Rectangle rec1); //объединение прямоугольников
	friend bool operator== (Rectangle rec1, Rectangle rec2); //проверка на равенство периметров
	bool operator|= (Rectangle rec1); //проверка на наличие совпадающих сторон
	void showpoints();//показать точки прямоугольника

private:

	Point points[4]; //коллекция точек прямоугольника
	Side  sides[4]; //коллекция сторон прямоугольника
};