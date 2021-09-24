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

	// Creates the Velocity according to location of starting point
	void BirdFactory :: createVelocity(){
        switch (birdType)
        {
           case 1:
           case 2:
           case 3:
           case 4:
           case 5:
           {
              if(startPoint.getY() <= 0)
              {
                 startVelocity.setDx(random(.75, 2.0));
                 startVelocity.setDy(random(.75, 2.0));
              }
              else
              {
                 startVelocity.setDx(random(.75, 2.0));
                 startVelocity.setDy(random(-2.0, -.75));
              }
              break;
           }
           case 6:
           case 7:
           case 8:
           {
              if(startPoint.getY() <= 0)
              {
                 startVelocity.setDx(random(.5, 1.5));
                 startVelocity.setDy(random(.5, 1.5));
              }
              else
              {
                 startVelocity.setDx(random(.5, 1.5));
                 startVelocity.setDy(random(-1.5, -.5));
              }
              break;
           }
           case 9: 
           {
              if(startPoint.getY() <= 0)
              {
                 startVelocity.setDx(random(.75, 2.0));
                 startVelocity.setDy(random(.75, 2.0));
              }
              else
              {
                 startVelocity.setDx(random(.75, 2.0));
                 startVelocity.setDy(random(-2.0, -.75));
              }
              break;
           }
           case 10:
           case 11:
           {
              if(startPoint.getY() <= 0)
              {
                 startVelocity.setDx(random(1.0, 3.0));
                 startVelocity.setDy(random(1.0, 3.0));
              }
              else
              {
                 startVelocity.setDx(random(1.0, 3.0));
                 startVelocity.setDy(random(-3.0, -1.0));
              }
              break;
           }
        }

	}
	
