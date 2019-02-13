#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class Lander
{
private:
	bool alive;
	bool landed;
	int fuel;
	Velocity velocity;
	Point point;
	float lX;
	float rX;


public:

	// sets the allive bool
	void setAlive(bool mAlive) { alive = mAlive; }
	// returns alive status
	bool isAlive() const { return alive; } 
	// sets landing
	void setLanded(bool mLanded){ landed = mLanded; }
	// tracks landing
	bool isLanded() const { return landed; } 
	// sets fuel avalible
	void setFuel(int mFuel){ fuel = mFuel; }
	// returns fuel
	int getFuel() const { return fuel; } 
	// returns ability to thrust
	bool canThrust();
	// sets velocity class
	void setVelocity(Velocity mVelocity){ velocity = mVelocity; }
	// returns Velocity class
	Velocity getVelocity() const { return velocity; } 
	// sets the point
	void setPoint(Point point){ this->point = point; }
	// returns the point
	Point getPoint() const { return point; } 
	// applys effects of gravity
	void applyGravity(float mGravity);
	// applies left thrust
	void applyThrustLeft(){ velocity.setDx(velocity.getDx() +.1);  fuel -= 1; }
	// applies right thrust
	void applyThrustRight(){ velocity.setDx(velocity.getDx() -.1); fuel -= 1; }
	// applies bottom thrust
	void applyThrustBottom();
	// advances the lander program
	void advance();
	// draws the lander
	void draw(){ drawLander(point); }
	//
	void setWrap(float mLX, float mRX){ lX = mLX; rX = mRX; }


// default constructor
Lander(){ alive = true; fuel = 0; landed = false;  velocity = Velocity();
			point = Point(); }



};

#endif