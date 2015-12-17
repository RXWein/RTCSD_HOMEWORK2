//Robot.h »úÆ÷ÈËÀà
#ifndef ROBOT
#define ROBOT

#include<vector>	
#include"Solver.h"
using namespace std;


class Robot:Solver
{
public:
	Robot(){};
	Robot(vector<Frames> &fr,double link1 = 100,double link2 = 100,
		double the1=0,double the2 = 0);
	~Robot(){};

	void PTPMove(Frames &,Point2D &);
	void thetaToTCP(double,double);

	inline double getLink1(){return linkage1;}
	inline double getLink2(){return linkage2;}
	inline double getTheta1(){return theta1;}
	inline double getTheta2(){return theta2;}

private:
	vector <Frames> fra;
	double linkage1;
	double linkage2;
	double theta1;
	double theta2;
};




#endif ROBOT