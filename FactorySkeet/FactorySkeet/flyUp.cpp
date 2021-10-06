#include "flyUp.h"
#include "birdFactory.h"

using namespace std;

void FlyUp::createVelocity()
{
    startVelocity.setDx(random(0.75,1.5));
    startVelocity.setDy(random(1.5,2.0));
}