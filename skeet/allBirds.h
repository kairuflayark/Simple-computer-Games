#include "bird.h"
#include "uiDraw.h"

class regularBird: public Bird
{
public:
	
	// draws the bird
	virtual void draw(){ drawCircle(getPoint(), 15); }
	// Default constructor
	regularBird(){ score = 0; hitCount = 1; hp = 1; }
};

class tBird: public Bird
{
public:
	// Draws ToughBird
	virtual void draw(){ drawToughBird( getPoint(), 15, hp); }
	// Default constructor
	tBird(){ score = 2; hitCount = 1; hp = 3; }
};

class sacredBird: public Bird
{
public:
	// Draws SacredBird
	virtual void draw(){ drawSacredBird( getPoint(), 15); }
	// Default constructor
	sacredBird(){ score = -10; hitCount = 0; hp = 1; }
};

class shotgunBird: public Bird
{
private:
	char s;
public:
	// Draws ShotgunBird
	virtual void draw() { drawCircle(getPoint(), 15); drawText( getPoint(), "S"); }
	// Default constructor
	shotgunBird(){ score = 0; hitCount = 0; hp = 1; shotgun = true; s = 'S'; }
};