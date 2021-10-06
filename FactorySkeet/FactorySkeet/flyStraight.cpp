#include "flyStraight.h"
#include "birdFactory.h"

using namespace std;

void FlyStraight::createVelocity()
{
    startVelocity.setDx(1);
    startVelocity.setDy(1);
}