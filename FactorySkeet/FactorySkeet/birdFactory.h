
#include "allBirds.h"
#include "velocity.h"
#include "point.h"

class BirdFactory 
{
private: 
	Bird* bird;
	Velocity startVelocity;
	Point startPoint;
	int birdType;


public:


	
	// Creates the bird object
	Bird* instantiateBird(int type, double x, double y1, double y2);
	// creates a starting point on the edge
	void createEdgeStartingPoint(double  x, double y1, double y2);
	// Creates the Velocity according to location of starting point
	void createVelocity();
	
	// assembles elements and returns the bird

	BirdFactory() { startVelocity = Velocity(); startPoint = Point(); bird = NULL; birdType = 0;}

};