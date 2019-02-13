#include "bullet.h"
#include <cmath>

#define BULLET_SPEED 5.0
float angle = 60.0;

/********************************************
* fires the Bullet
********************************************/
void Bullet::fire(Point point, float angle, Velocity mVelocity)
{
	float fDy = BULLET_SPEED * (cos(M_PI / 180.0 * angle));
	float fDx = BULLET_SPEED * (-sin(M_PI / 180.0 * angle));

	setVelocity(mVelocity);
	velocity.addDx(fDx);
	velocity.addDy(fDy);

	setPoint(point);

}

/********************************************
* default constructor
********************************************/
Bullet::Bullet()
{
	frameCount = 0; 
}

