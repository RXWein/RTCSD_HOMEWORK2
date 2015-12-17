//Robot.cpp
#include"Robot.h"
#include<iostream>
using namespace std;

Robot::Robot(vector<Frames>& fr,double link1,double link2
			 ,double the1,double the2):
			 linkage1(link1),linkage2(link2)
			 ,theta1(the1),theta2(the2)
{
	for(int i=0; i < fr.size(); i++)
		fra.push_back(fr[i]);
	/*if (fr.size() == 0)
	{
		Frames base(0.0,0.0,1.0,0.0,0.0,1.0);
		fra.push_back(base);
	}*/
}

void Robot::PTPMove(Frames & f,Point2D & p)
{
	Matrix2d temp;
	Matrix2d zeros(2,2);
	temp = inverSolution(linkage1,linkage2,f,p);
	if (temp != zeros)
		cout << "关节值： " <<endl << temp << endl;
	cout << endl;
}
void Robot::thetaToTCP(double th1,double th2)
{
	Vector2d temp;
	temp = directSolution(linkage1,linkage2,th1,th2);
	cout << "运动到的点坐标：" << endl << temp;
	cout << endl;
}