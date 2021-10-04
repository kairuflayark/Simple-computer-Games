#include "movement.h"
#include "velocity.h"
#include "uiDraw.h"

Movement * Movement :: movementFactory(int type)
{
    switch (type)
    {
    case 1:
        return new MoveSlow();
        break;
    case 2:
        return new MoveDownSlow();
        break;
    case 3:
        return new MoveMedium();
        break;
    case 4:
        return new MoveDownMedium();
        break;
    case 5:
        return new MoveFast();
        break;
    case 6:
        return new MoveDownFast();
        break;
    }
}

Velocity MoveSlow :: move()
{
    Velocity velocity;
    velocity.setDx(random(.5, 1.5));
    velocity.setDy(random(.5, 1.5));
    return velocity;
}

Velocity MoveDownSlow :: move()
{
    Velocity velocity;
    velocity.setDx(random(.5, 1.5));
    velocity.setDy(random(-1.5, .5));
    return velocity;
}

Velocity MoveMedium :: move()
{
    Velocity velocity;
    velocity.setDx(random(.75, 2.0));
    velocity.setDy(random(.75, 2.0));
    return velocity;
}

Velocity MoveDownMedium :: move()
{
    Velocity velocity;
    velocity.setDx(random(.75, 2.0));
    velocity.setDy(random(-2.0, .75));
    return velocity;
}

Velocity MoveFast :: move()
{
    Velocity velocity;
    velocity.setDx(random(1.0, 3.0));
    velocity.setDy(random(1.0, 3.0));
    return velocity;
}

Velocity MoveFast :: move()
{
    Velocity velocity;
    velocity.setDx(random(1.0, 3.0));
    velocity.setDy(random(-3.0, -1.0));
    return velocity;
}