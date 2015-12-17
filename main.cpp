//���Գ���

#include"Robot.h"
#include <iostream>
using namespace std;

int main()
{
	Point2D p(90,92);	//Ҫ�˶�����Ŀ�������
	Point2D p1(500,1305);
	vector<Frames> robotFrames;
	Frames WF(0.0,0.0,1.0,0.0,0.0,1.0);	//��������ϵ
	robotFrames.push_back(WF);
	Frames J1(0.0,0.0,1.0,0.0,0.0,1.0);	//�ؽ�1����ϵ
	robotFrames.push_back(J1);
	Frames J2(200.0,0.0,1.0,0.0,0.0,1.0);	//�ؽ�2����ϵ
	robotFrames.push_back(J2);
	Frames TCP(200.0,150.0,0.0,1.0,-1.0,0.0);	//��������ϵ
	robotFrames.push_back(TCP);

	vector<int> b;
	for(int i = 0; i< 5;i++)
		b.push_back(i);
	//��������ϵ
	Frames TF1(1.0,1.0,0.8,0.6,-0.6,0.8);
	Frames TF2(1.0,2.0,0.0,1.0,-1.0,0.0);

	Robot myrobot(robotFrames,200.0,150.0,0.0,90.0);

	myrobot.PTPMove(WF,p);
	myrobot.PTPMove(J1,p);
	myrobot.PTPMove(J2,p);
	myrobot.PTPMove(TF1,p);
	myrobot.PTPMove(TF2,p);
	myrobot.PTPMove(TCP,p);

	myrobot.PTPMove(WF,p1);
	myrobot.PTPMove(J1,p1);
	myrobot.PTPMove(J2,p1);
	myrobot.PTPMove(TF1,p1);
	myrobot.PTPMove(TF2,p1);
	myrobot.PTPMove(TCP,p1);

	system("pause");
 	return 1;
}