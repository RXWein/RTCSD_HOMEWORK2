//Point2D.cpp
#include "Point2D.h"

Point2D & Point2D::operator+(const Point2D & p)
{
	Point2D temp(x+p.x,y+p.y);
	return temp;
}

Point2D & Point2D::operator-(const Point2D & p)
{
	Point2D temp(x-p.x,y-p.y);
	return temp;
}

Point2D & Point2D::operator=(const Point2D & p)
{
	Point2D temp(p.x,p.y);
	return temp;
}

Vector2d  Point2D::PTV()
{
	Vector2d temp;
	temp(0) = getX();
	temp(1) = getY();
	return temp;
}