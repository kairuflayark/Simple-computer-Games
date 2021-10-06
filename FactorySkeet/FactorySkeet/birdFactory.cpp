#include "birdFactory.h"

using namespace std;

	
	// Creates the bird object
	Bird* BirdFactory ::instantiateBird(int type, double x, double y1, double y2){
        birdType = type;

        if (bird) { bird = NULL; }

        bird = new Bird();
        switch(birdType)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            {
                regularBird* regular = new regularBird(); 
                bird = regular;
                createEdgeStartingPoint(x, y1, y2);
                break;
            }
            case 6:
            case 7:
            case 8:
            {
                tBird* t = new tBird();
                bird = t;
                createEdgeStartingPoint(x, y1, y2);
                break;
            }
            case 9:
            {
                sacredBird* sacred = new sacredBird();
                bird = sacred;
                createEdgeStartingPoint(x, y1, y2);
                break;
            }
            case 10:
            case 11:
            {
                shotgunBird* sBird = new shotgunBird();
                bird = sBird;
                createEdgeStartingPoint(x, y1, y2);
                break;
            }
        }
        
        createVelocity();
        bird->setPoint(startPoint);
        bird->setVelocity(startVelocity);

        return bird;
	}

	// creates a starting point on the edge
	void BirdFactory :: createEdgeStartingPoint(double x, double y1, double y2){
        startPoint.setX(x);
        startPoint.setY(random(y1, y2));
	}

   // sets velocity of the bird
   void BirdFactory::setting(CreateVelocity *direction) 
   {
        direction->Velocity();
        char routes[3];
        int choice = random(1, 3);
   }