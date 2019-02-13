#ifndef BULLET_H
#define BULLET_H
#include "flyingObject.h"
#include "point.h"
#include "uiDraw.h"

class Bullet: public FlyingObject
{
private:
	int frameCount;

public:
	void fire(Point point, float angle, Velocity mVelocity);
	virtual void draw(){ drawDot(getPoint()); }
	void count(){ frameCount++; }
	int getCount(){ return frameCount; }


	Bullet();


};

#endif