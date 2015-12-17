//Point2D.h µ„¿‡
#ifndef POINT2D
#define POINT2D

#include<Eigen\Dense>
using namespace Eigen;

class Point2D
{
private:
	double x;
	double y;

public:
	//Point2D(){};
	Point2D(double X = 0.0,double Y = 0.0){x = X; y = Y;}

	double getX(){return x;}
	double getY(){return y;}

	Vector2d  PTV();
	Point2D & operator+(const Point2D &);
	Point2D & operator-(const Point2D &);
	Point2D & operator=(const Point2D &);
};

#endif POINT2D