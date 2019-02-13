#ifndef rocks_h
#define rocks_h

#include "flyingObject.h"
#include "uiDraw.h"
#include <list>
#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#define BIG_CLOSE_ENOUGH 16
#define MEDIUM_CLOSE_ENOUGH 10
#define SMALL_CLOSE_ENOUGH 4





// Define the following classes here:
//   Rock
class Rock: public FlyingObject
{
protected:
	int rotation;
	int score;
	float close;



public:
	// returns int if it
	int hit(){ return score; }
	int getClose(){ return close; }
	// draws the Rock
	virtual void draw(){ drawCircle(getPoint(), 15); }
	virtual std::list<Rock*> splitAsteroids(){ return std::list<Rock*>(); }

	Rock(){score = 0; rotation = 0; }
};

//   BigRock
//   MediumRock
//   SmallRock
class BigRock: public Rock
{
public:
	
	// draws the big Rock
	virtual void draw(){ setR(); drawLargeAsteroid( point, rotation); }
	// allows rotation
	void setR(){ rotation += BIG_ROCK_SPIN; if(rotation >= 360){ rotation = 0;} }
	virtual std::list<Rock*> splitAsteroids();
	// Default constructor
	BigRock(){ score = 1; close = 16;}
	BigRock(Point point, Velocity velocity){ this->point = point, this->velocity = velocity; }

};

class MediumRock: public Rock
{
public:
	// Draws medium Rock
	virtual void draw(){ setR(); drawMediumAsteroid( point, rotation); }
	// allows rotation
	void setR(){ rotation += MEDIUM_ROCK_SPIN; if(rotation >= 360){ rotation = 0;}}
	virtual std::list<Rock*> splitAsteroids();
	// Default constructor
	MediumRock(){ score = 2; close = MEDIUM_CLOSE_ENOUGH; }
	MediumRock(Point point, Velocity velocity){ this->point = point, this->velocity = velocity; }
};

class SmallRock: public Rock
{
public:
	// Draws small Rock
	virtual void draw(){ setR();  drawSmallAsteroid( point, rotation); }
	// allows rotation
	void setR(){ rotation += SMALL_ROCK_SPIN; if(rotation >= 360){ rotation = 0;}}
	// Default constructor
	SmallRock(){ score = 5; close = SMALL_CLOSE_ENOUGH; }
	SmallRock(Point point, Velocity velocity){ this->point = point, this->velocity = velocity; }
};



#endif /* rocks_h */
