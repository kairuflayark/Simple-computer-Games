#include "ship.h"
#include <iostream>

// Put your ship methods here
 void Ship::applyThrust()
 {

 	float dy = THRUST_AMOUNT * (cos(M_PI / 180.0 * angle));
 	float dx = THRUST_AMOUNT * (-sin(M_PI / 180.0 * angle));
 	velocity.addDx(dx);
 	velocity.addDy(dy);
 	thrust = true;

 }

// void Ship::advance()
// {
// 	point.setX(point.getX() + velocity.getDx());
// 	if (point.getX() >= rX)
// 		{
// 		point.setX(lX + 1);
// 		}
// 	if (point.getX() <= lX)
// 		{
// 		point.setX(rX - 1);
// 		}
// 	point.setY(point.getY() + velocity.getDy());
// 	if (point.getY() >= tY)
// 		{
// 		point.setY(bY + 1);
// 		}
// 	if (point.getY() <= bY)
// 		{
// 		point.setY(tY - 1);
// 		}

// }