#ifndef BIRD_H
#define BIRD_H
#include "flyingObject.h"
#include "uiDraw.h"


class Bird: public FlyingObject
{
protected:
	int score;
	int hitCount;
	int hp;
	bool shotgun;

public:
	// returns int if it
	int hit(){ hp--; return hitCount; }
	// tracks remaining hp
	int getHp() { return hp; }
	// returns score on kill
	int getScore() { return score; }
	bool getShotgun() { return shotgun; }
	// draws the bird
	virtual void draw(){ drawCircle(getPoint(), 15); }


	Bird(){ hitCount = 1; hp = 1; score = 0; shotgun = false; }

};

#endif