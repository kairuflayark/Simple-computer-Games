#include "createVelocity.h"
#include "birdFactory.h"

class FlyUp : public CreateVelocity, public BirdFactory
{
    protected:
        void createVelocity();
};