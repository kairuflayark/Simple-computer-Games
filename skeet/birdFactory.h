#include "bird.h"
#include "velocity.h"
#include "point.h"

class BirdFactory 
{
private: 
	Bird* bird;
	Velocity startVelocity;
	Point startPoint;
	int birdType,

public:


	
	// Creates the bird object
	Bird* instantiateBird();
	// creates a starting point on the edge
	void createEdgeStartingPoint(float x, float y1, float y2);
	// Creates the Velocity according to location of starting point
	void createVelocity();
	
	// assembles elements and returns the bird

	BirdFactory() { startVelocity = Velocity(); startPoint = Point(); bird = null; randomBird = 0;}

};