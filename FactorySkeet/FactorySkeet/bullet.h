#ifndef BULLET_H
#define BULLET_H
#include "flyingObject.h"
#include "point.h"
#include "uiDraw.h"

class Bullet: public FlyingObject
{

public:
	void fire(Point point, float angle);
	virtual void draw(){ drawDot(getPoint()); }


	Bullet();


};

#endif