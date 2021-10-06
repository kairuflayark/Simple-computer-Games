#include "createVelocity.h"
#include "birdFactory.h"

class FlyStraight : public CreateVelocity, public BirdFactory
{
    protected:
        void createVelocity();
};