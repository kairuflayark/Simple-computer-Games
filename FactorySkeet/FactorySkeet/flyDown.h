#include "createVelocity.h"
#include "birdFactory.h"

class FlyDown : public CreateVelocity, public BirdFactory
{
    protected:
        void createVelocity();
};