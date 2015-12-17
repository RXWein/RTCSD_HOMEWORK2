//Frames.h 坐标系类
#ifndef Frame
#define Frame

#include"Point2D.h"

class Frames
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
	Frames(){};
	Frames(double,double,double,double,double,double);
	~Frames(){};
	Matrix2d  rotation(Frames &);	//两坐标系之间的旋转矩阵
	Vector2d  move(Frames &);		//两坐标系之间的移动向量

private:
	Point2D originalPoint;
	Vector2d XAxis;
	Vector2d YAxis;
};

#endif Frame