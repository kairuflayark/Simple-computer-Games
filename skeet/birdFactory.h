#include "bird.h"
#include "velocity.h"
#include "point.h"
#include "movement.h"

class BirdFactory 
{
private: 
	Bird* bird;
	Velocity startVelocity;
	Point startPoint;
	int birdType;
	Movement * movement;

public:


	
	// Creates the bird object
	Bird* instantiateBird(int type, float x, float y1, float y2);
	// creates a starting point on the edge
	void createEdgeStartingPoint(float x, float y1, float y2);
	// Creates the Velocity according to location of starting point
	void createVelocity();
	
	// assembles elements and returns the bird

	BirdFactory() { startVelocity = Velocity(); startPoint = Point(); bird = NULL; birdType = 0; }
};