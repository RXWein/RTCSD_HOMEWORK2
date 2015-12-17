//Frames.h ����ϵ��
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
	Matrix2d  rotation(Frames &);	//������ϵ֮�����ת����
	Vector2d  move(Frames &);		//������ϵ֮����ƶ�����

private:
	Point2D originalPoint;
	Vector2d XAxis;
	Vector2d YAxis;
};

#endif Frame