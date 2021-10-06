#include "birdFactory.h"
#include "allBirds.h"
#include "movement.h"

using namespace std;

// Creates the bird object
Bird *BirdFactory ::instantiateBird(int type, float x, float y1, float y2)
{
   birdType = type;

   bird = NULL;

   bird = new Bird();
   switch (birdType)
   {
   case 1:
   case 2:
   case 3:
   case 4:
   case 5:
   {
      regularBird *regular = new regularBird();
      bird = regular;
      createEdgeStartingPoint(x, y1, y2);
      break;
   }
   case 6:
   case 7:
   case 8:
   {
      tBird *t = new tBird();
      bird = t;
      createEdgeStartingPoint(x, y1, y2);
      break;
   }
   case 9:
   {
      sacredBird *sacred = new sacredBird();
      bird = sacred;
      createEdgeStartingPoint(x, y1, y2);
      break;
   }
   case 10:
   case 11:
   {
      shotgunBird *sBird = new shotgunBird();
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
void BirdFactory ::createEdgeStartingPoint(float x, float y1, float y2)
{
   startPoint.setX(x);
   startPoint.setY(random(y1, y2));
}

// Creates the Velocity according to location of starting point
void BirdFactory ::createVelocity()
{
   switch (birdType)
   {
   case 1:
   case 2:
   case 3:
   case 4:
   case 5:
   case 9:
   {
      if (startPoint.getY() <= 0)
         startVelocity = movement->movementFactory(3)->move();
      else
         startVelocity = movement->movementFactory(4)->move();
      break;
   }
   case 6:
   case 7:
   case 8:
   {
      if (startPoint.getY() <= 0)
         startVelocity = movement->movementFactory(1)->move();
      else
         startVelocity = movement->movementFactory(2)->move();
      break;
   }
   case 10:
   case 11:
   {
      if (startPoint.getY() <= 0)
         startVelocity = movement->movementFactory(5)->move();
      else
         startVelocity = movement->movementFactory(6)->move();
      break;
   }
   }
}
