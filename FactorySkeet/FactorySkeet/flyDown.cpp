#include "flyDown.h"
#include "birdFactory.h"

using namespace std;

void FlyDown::createVelocity()
{
    startVelocity.setDx(random(0.75,1.5));
    startVelocity.setDy(random(-2.0,-1.5));
}