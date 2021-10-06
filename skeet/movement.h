#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "velocity.h"

class Movement
{
    public:
        virtual Velocity move() = 0;
        Movement * movementFactory(int type);
};

#endif


#ifndef MOVESLOW_H
#define MOVESLOW_H

class MoveSlow: public Movement
{
    public:
        Velocity move();
};

#endif

#ifndef MOVEDOWNSLOW_H
#define MOVEDOWNSLOW_H

class MoveDownSlow: public Movement
{
    public:
        Velocity move();
};

#endif

#ifndef MOVEMEDIUM_H
#define MOVEMEDIUM_H

class MoveMedium: public Movement
{
    public:
        Velocity move();
};

#endif

#ifndef MOVEDOWNMEDIUM_H
#define MOVEDOWNMEDIUM_H

class MoveDownMedium: public Movement
{
    public:
        Velocity move();
};

#endif

#ifndef MOVEFAST_H
#define MOVEFAST_H

class MoveFast: public Movement
{
    public:
        Velocity move();
};

#endif

#ifndef MOVEDOWNFAST_H
#define MOVEDOWNFAST_H

class MoveDownFast: public Movement
{
    public:
        Velocity move();
};

#endif