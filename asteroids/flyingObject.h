#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include "velocity.h"
#include "point.h"

class FlyingObject
{
protected:
	Point point;
	Velocity velocity;
	bool alive;
	float lX;
	float rX;
	float tY;
	float bY;


public:
	// returns a point
	Point getPoint(){ return point; }
	// sets the point
	void setPoint(Point mPoint){ point = mPoint; }
	// returns the Velocity
	Velocity getVelocity(){ return velocity; }
	// sets the Velocity
	void setVelocity(Velocity mVelocity){ velocity = mVelocity; }
	// returns allive
	bool isAlive(){ return alive; }
	// sets alive to false
	void kill(){ alive = false; }
	// advances the program
	void advance();
	//Draws the Object
	virtual void draw(){}
	//Sets the Wrap
	void setWrap(float mLX, float mRX, float tY, float bY){ lX = mLX; rX = mRX; this->tY = tY, this->bY = bY;}



	FlyingObject();
	~FlyingObject();




};



#endif








