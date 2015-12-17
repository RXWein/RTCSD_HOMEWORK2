//Solver.h  Ω‚À„¿‡
#ifndef SOLVER
#define SOLVER

#include"Frames.h"

class Solver 
{
public:
	Solver(){};
	~Solver(){};
	Vector2d  directSolution(double link1,double link2,double th1,double th2);
	Matrix2d  inverSolution(double link1,double link2,Frames &, Point2D &);
private:

};




#endif SOLVER