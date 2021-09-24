#include "bullet.h"
#ifndef M_PI
   #define M_PI 3.14159265358979323846
#endif




#define BULLET_SPEED 10.0
float angle = 60.0;

/********************************************
* fires the Bullet
********************************************/
void Bullet::fire(Point point, float angle)
{
	float dx = BULLET_SPEED * (-cos(M_PI / 180.0 * angle));
	float dy = BULLET_SPEED * (sin(M_PI / 180.0 * angle));

	setVelocity(Velocity(dx, dy));
	setPoint(point);

}

/********************************************
* default constructor
********************************************/
Bullet::Bullet()
{

}

