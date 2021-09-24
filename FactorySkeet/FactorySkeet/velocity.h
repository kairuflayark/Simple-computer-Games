#ifndef VELOCITY_H
#define VELOCITY_H


class Velocity
{
private:
	float dx;
	float dy;

public:
	// sets change of x
	void setDx(float dx){ this->dx = dx; }
	// returns x
	float getDx() const { return dx; } 
	// sets change of y
	void setDy(float dy){ this->dy = dy; }
	// returns x
	float getDy() const { return dy; } 
	void addDy(float mDy){ setDy(getDy() + mDy); }
	void addDx(float mDx){ setDx(getDx() + mDx); }

// Constructors
Velocity(){ dx = 0; dy = 0;}
Velocity(float mDx, float mDy){ dx= mDx; dy = mDy;}

};
	
#endif













