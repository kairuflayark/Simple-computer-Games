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

class MoveSlow: public Movement
{
    public:
        Velocity move();
};

class MoveDownSlow
{
    public:
        Velocity move();
};

class MoveMedium
{
    public:
        Velocity move();
};

class MoveDownMedium
{
    public:
        Velocity move();
};

class MoveFast
{
    public:
        Velocity move();
};

class MoveDownFast
{
    public:
        Velocity move();
};