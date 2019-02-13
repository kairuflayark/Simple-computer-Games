#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include <cmath>

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "flyingObject.h"

class Ship: public FlyingObject
{
private:
	float angle;
	bool thrust;

public:

	// sets the allive bool
	void setAlive(bool mAlive) { alive = mAlive; }
	//
	float getAngle() const { return angle; }
	// returns alive status
	bool isAlive() const { return alive; } 
	// sets velocity class
	void setVelocity(Velocity mVelocity){ velocity = mVelocity; }
	// returns Velocity class
	Velocity getVelocity() const { return velocity; } 
	// sets the point
	void setPoint(Point point){ this->point = point; }
	// returns the point
	Point getPoint() const { return point; }

	void applyThrust();
	void setThrust(bool t){ thrust = t; }	
	void draw(){ drawShip(point, angle, thrust);}
	//Rotate Ship right
	void moveRight(){ angle -= ROTATE_AMOUNT; }
	void moveLeft(){ angle += ROTATE_AMOUNT; }
	// void advance();
	// void setWrap(float mLX, float mRX, float tY, float bY){ lX = mLX; rX = mRX; this->tY = tY, this->bY = bY;}


// default constructor
Ship(){ alive = true; velocity = Velocity(); point = Point(); angle = 0; thrust = false; }

};


// Put your Ship class here


#endif /* ship_h */
