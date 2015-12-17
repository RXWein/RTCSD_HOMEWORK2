//Solver.cpp
#include"Solver.h"
#include<iostream>
using namespace std;
#include<cmath>
#define pi 3.141592654

Vector2d Solver::directSolution(double link1,double link2,double th1,double th2)
{
	Vector2d temp;
	temp(0) = link1*cos(th1) + link2*cos(th1+th2);
	temp(1) = link1*sin(th1) + link2*sin(th1+th2);

	return temp;
}

Matrix2d  Solver::inverSolution(double link1,double link2,Frames &f,Point2D & p)
{
	Vector3d point;
	Vector2d result;	//p�ڻ�����ϵ�ϵ�����ֵ
	Vector2d moveF;		//����ϵf�뼫����ϵԭ��֮�������
	Matrix2d rota;		//����ϵf�������ϵ֮�����ת����
	Matrix3d T;			//����ϵf�������ϵ֮���ת������
	Matrix2d Theta;	//�ؽڽ�
	Vector2d temp;
	Frames base(0.0,0.0,1.0,0.0,0.0,1.0);

	//������ϵf�ĵ�pת����������
	rota = base.rotation(f);
	moveF = base.move(f);
	moveF = moveF.transpose();
	T << rota,moveF,
		0,0,1;
	temp = p.PTV();
	point << temp,1;
	point = point.transpose();
	point = T*point;
	result << point(0),point(1);

	//�жϵ��Ƿ����ҹ����ռ�
	double dis = sqrt(result.dot(result));
	if(dis>(link1+link2) || dis<(link1-link2))
	{
		Matrix2d zeros(2,2);
		cout << "����㲻�ڹ����ռ䣡"<< endl;
		return zeros;
	}

	//�󷴽�ؽ�ֵ
	else
	{
	double beita = atan2(result(1),result(0));
	double fi;
	double theta11,theta12,theta21,theta22;

	fi = acos((dis*dis+link1*link1-link2*link2)/(2*link1*dis));
	theta12 = acos((dis*dis-link1*link1-link2*link2)/(2*link1*link2))*180/pi;

	if(theta12<0)
		theta11 = (beita + fi)*180/pi;
	else 
		theta11 = (beita - fi)*180/pi;

	theta22 = -acos((dis*dis-link1*link1-link2*link2)/(2*link1*link2))*180/pi;

	if(theta22<0)
		theta21 = (beita + fi)*180/pi;
	else 
		theta21 = (beita - fi)*180/pi;
	Theta << theta11,theta12,
		theta21,theta22;
	return Theta;
	}
	
}