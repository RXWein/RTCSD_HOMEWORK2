//Frames.cpp
#include"Frames.h"
#include"math.h"
#include<cmath>
#include<iostream>
using namespace std;

#define pi 3.141592654

Frames::Frames(double px,double py,double vxx,double vxy,double vyx,double vyy)
	:originalPoint(px,py),XAxis(vxx,vxy),YAxis(vyx,vyy)
{
	
	if(XAxis.dot(YAxis) != 0.0)
	{
		cout << "输入的坐标轴不垂直！" << endl;
	}
}

//两坐标系之间的旋转矩阵
Matrix2d  Frames::rotation(Frames& fram)
{
	double s1;
	double c1;
	double theta;
	Matrix2d temp;
	if(fram.XAxis(0) !=0 && XAxis(0)!= 0)
		theta = atan(fram.XAxis(1)/fram.XAxis(0))-atan(XAxis(1)/XAxis(0));
	if(fram.XAxis(0) !=0 && XAxis(0)== 0)
	{
		if(XAxis(1)== 1)
			theta = atan(fram.XAxis(1)/fram.XAxis(0))- 90/180*pi;
		if(XAxis(1)== -1)
			theta = atan(fram.XAxis(1)/fram.XAxis(0))- 180/180*pi;
	}
	if(fram.XAxis(0) ==0 && XAxis(0)!= 0)
	{
		double k = atan(XAxis(1)/XAxis(0));
		if(fram.XAxis(1)== 1)
			theta = (double)90/180*pi - k;
		if(fram.XAxis(1)== -1)
			theta = (double)180/180*pi - atan(XAxis(1)/XAxis(0));
	}
	s1 = sin(theta);
	c1 = cos(theta);
	if(abs(s1) < 0.000000000000001)
		s1 = 0;
	if(abs(c1) < 0.000000000000001)
		c1 = 0;
	temp << c1,-s1,
			s1,c1;
	return temp;
}


//两坐标系之间的移动向量
Vector2d  Frames::move(Frames & fra)
{
	Vector2d temp;
	temp = fra.originalPoint.PTV()-originalPoint.PTV();
	return temp;
}

