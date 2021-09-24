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
	void advance(){ point.addX(velocity.getDx()); point.addY(velocity.getDy()); }
	//Draws the Object
	virtual void draw(){}



	FlyingObject();
	~FlyingObject();




};



#endif








