#include "lander.h"

bool Lander::canThrust()
{ 
	if(fuel > 0) 
		return true; 
	else 
		return false; 
} 

void Lander::advance()
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

}

void Lander::applyThrustBottom()
{ 
	if (fuel >= 3)
	{
		velocity.setDy(velocity.getDy() +.3); 
		fuel -= 3; 
	}
}

void Lander::applyGravity(float mGravity)
{ 
	velocity.setDy(velocity.getDy() - .1);
}


