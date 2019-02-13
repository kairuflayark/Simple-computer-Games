#include "rocks.h"
#include <list>
using namespace std;


list<Rock*> BigRock::splitAsteroids()
{
   list <Rock*> rocks;

   for(int i = -1; i < 2; i + 2)
   {
      Rock * rock = new MediumRock(point, velocity);
      rock->getVelocity().addDy(i);
      rocks.push_back(rock);
   }
   Rock * rock = new SmallRock(point, velocity);
   rock->getVelocity().addDx(2);
   rocks.push_back(rock);
   return rocks;
   
}


 list<Rock*> MediumRock::splitAsteroids()
{
	list <Rock*> rocks;
	for(int i = -3; i < 4; i + 6)
   {
      Rock * rock = new SmallRock(point, velocity);
      rock->getVelocity().addDx(i);
      rocks.push_back(rock);
      
   }
   return rocks;
}
