

#include "flyingObject.h"

void FlyingObject::advance()
{
	point.setX(point.getX() + velocity.getDx());
	if (point.getX() >= rX)
		{
		point.setX(lX + 1);
		}
	if (point.getX() <= lX)
		{
		point.setX(rX - 1);
		}
	point.setY(point.getY() + velocity.getDy());
	if (point.getY() >= tY)
		{
		point.setY(bY + 1);
		}
	if (point.getY() <= bY)
		{
		point.setY(tY - 1);
		}

}




	/********************************************
	* default constructor
	********************************************/
	FlyingObject::FlyingObject()
	{
		alive = true;
		point = Point();
		velocity = Velocity();
		lX = 0;
		rX = 0;
		tY = 0;
		bY = 0;


	}

	/********************************************
	* default destructor
	********************************************/
	FlyingObject::~FlyingObject()
	{

		
	}