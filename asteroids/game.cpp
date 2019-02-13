/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "ship.h"


#include <list>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5
 
/***************************************
 * GAME CONSTRUCTOR
 *****************************->*********/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br)
{
   // Set up the initial conditions of the game
   score = 0;

   // TODO: Set your rock pointer to a good initial value (e.g., NULL)
  /* for (int i = 0; i < MAX_ASTEROIDS; i++)
   {
   rock[i] = NULL;
   }
   */
   shotgun = false;
   start = true;
   timeCount = 1800;
   ship.setWrap(topLeft.getX(), bottomRight.getX(), topLeft.getY(), bottomRight.getY());
}

/****************************************
 * GAME DESTRUCTOR
 ******************************->*********/
Game :: ~Game()
{


   // TODO: Check to see if there is currently a rock allocated
   //       and if so, delete it.

}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   if (start == true && timeCount > 0)
   {
   advanceBullets();
   advanceRock();
   advanceShip();
   timeCount--;
   handleCollisions();
   splitRocks();
   cleanUpZombies();

   }
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{ 
   // Move each of the bullets forward if it is alive
   for (list <Bullet>::iterator bl = bullets.begin(); bl != bullets.end(); ++bl)
   {
      if (bl->isAlive() == true)
      {
         // this bullet is alive, so tell it to move forward
         bl->advance();
         bl->count();
         if (bl->getCount() == 40)
            bl->kill();

      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE BIRD
 *
 * 1. If there is no rock, create one with some probability
 * 2. If there is a rock, and it's alive, advance it
 * 3. Check if the rock has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceRock()
{
   
   
      if (rocks.size() < MAX_ASTEROIDS)
      {
         // there is no rock right now, possibly create one
         
         // "resurrect" it will some random chance
         
            // create a new rock
            Rock* nRock;
            nRock = createLargeRock();
            rocks.push_back(nRock);
            
         
      }
      for (list <Rock*>::iterator it = rocks.begin(); it != rocks.end(); ++it)
      {
         // we have a rock, make sure it's alive
         if ((*it)->isAlive())
         {
            // move it forward
            (*it)->advance();
            
            // check if the rock has gone off the screen
            
         }
      }
   
}

/*******************************************************************************
*
*
********************************************************************************/
void Game::splitRocks()
{
   std::list <Rock*> nRocks;
   for (list <Rock*>::iterator it = rocks.begin(); it != rocks.end(); ++it)
   {
      if (!(*it)->isAlive())
      {
         nRocks = (*it)->splitAsteroids();

      }
   }

   rocks.splice(rocks.end(), nRocks);
}

/**************************************************************************
 * GAME :: CREATE ROCK
 * Create a rock of a random type according to the rules of the game.
 **************************************************************************/
Rock* Game :: createLargeRock()
{
   Rock* newRock = NULL;

   
   
   // set position 
   Point startRock;
   startRock.setX(random(topLeft.getX(), bottomRight.getX()));
   startRock.setY(random(bottomRight.getY(), topLeft.getY()));
   // set velocity
   Velocity startVelocity;
   
   startVelocity.setDx(random(-1, 2));
   startVelocity.setDy(random(-1, 2));
   newRock = new BigRock(startRock, startVelocity);
   newRock->setWrap(topLeft.getX(), bottomRight.getX(), topLeft.getY(), bottomRight.getY());

    
   
   
   
   return newRock;
}


/**************************************************************************
*
*
**************************************************************************/
void Game::advanceShip()
{
   ship.advance();

}
/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a rock and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
   
   for (list <Rock*>::iterator it = rocks.begin(); it != rocks.end(); ++it)
      {
         // now check for a hit (if it is close enough to any live bullets)
         for (list <Bullet>::iterator bl = bullets.begin(); bl != bullets.end(); ++bl)
         {
            if (bl->isAlive())
            {
               // this bullet is alive, see if its too close

               // check if the rock is at this point (in case it was hit)
               if ((*it)->isAlive())
               {
                  // BTW, this logic could be more sophisiticated, but this will
                  // get the job done for now...
                  if (fabs(bl->getPoint().getX() - (*it)->getPoint().getX()) < 16 //(*it)->getClose()
                      && fabs(bl->getPoint().getY() - (*it)->getPoint().getY()) < 16) //(*it)->getClose())
                  {
                     //we have a hit!
                     
                     //hit the rock
                     int points = (*it)->hit();
                     score += points;
                     bl->kill();
                     (*it)->kill();
                     
                     //    }   
                     // if (shotgun == false)
                     // {
                     //    //shotgun = (*it)->getShotgun();
                     // }
                     
                     
                     // the bullet is dead as well
                     
                  }
               }
            } // if bullet is alive
            
         } // for bullets
   }
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate rock)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // check for dead rock
   // for (list <Rock*>::iterator it = rocks.begin(); it != rocks.end(); ++it)
   // {
   //    if (!(*it)->isAlive())
   //    {
   //       // the rock is dead, but the memory is not freed up yet      
   //       // TODO: Clean up the memory used by the rock
   
   //       it = rocks.erase(it);

   //    }
   // }
   

   for (list <Bullet>::iterator bl = bullets.begin(); bl != bullets.end(); ++bl)
   {
      
      if (bl->isAlive() != true)
      {
         // If we had a list of pointers, we would need to delete the memory here...
         
         
         // remove from list and advance
         bl = bullets.erase(bl);
      }
  
   }
   
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   if (ui.isSpace() && start == false)
      start = true;

   // Change the direction of the ship
   if ( start == true && ship.isAlive())
      if (ui.isLeft())
      {
         ship.moveLeft();
      }
      
      if (ui.isRight())
      {
         ship.moveRight();
      }
      if (ui.isDown())
      {
         ship.applyThrust();
         ship.setThrust(true);
      }
      else
      {
         ship.setThrust(false);
      }
   
   // Check for "Spacebar"
   if (ui.isSpace()  && start == true)
   {
      //TODO fix shotgun
      if( shotgun == true)
      {
         float angle = -20.0;
         Bullet newBullet;
         for (int i = 0; i <= random(9, 25); i++)
         {
            newBullet.fire(ship.getPoint(), (ship.getAngle() + angle), ship.getVelocity());
            angle += random(1.0, 3.0);
            if (angle <= 20)
            {
               newBullet.setWrap(topLeft.getX(), bottomRight.getX(), topLeft.getY(), bottomRight.getY());
               bullets.push_back(newBullet);
            }
         }
         

      }
      else
      { 
      Bullet newBullet;
      newBullet.fire(ship.getPoint(), ship.getAngle(), ship.getVelocity());
      newBullet.setWrap(topLeft.getX(), bottomRight.getX(), topLeft.getY(), bottomRight.getY());
      bullets.push_back(newBullet);
      }
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{  
   if (start == false)
   {
      drawText( Point(-60, 0), "Press Start to begin.");
      drawText( Point(-60, -11), "Shoot Rocks until time runs out");
      drawText( Point(-60, -22), "Shoot S rocks to reload your shotgun");
      drawText( Point(-60, -33), "And make sure not to hit the Sacred Rocks!");
   }


   if (start == true)
   {
      // draw the rock
      for (list <Rock*>::iterator it = rocks.begin(); it != rocks.end(); ++it)
      {
      
      // TODO: Check if you have a valid rock and if it's alive
      // then call it's draw method
         if ((*it)->isAlive() == true)
         {
            (*it)->draw();
         }
      }
      // draw the ship
      ship.draw();
      
      // draw the bullets, if they are alive
      for (list <Bullet>::iterator bl = bullets.begin(); bl != bullets.end(); ++bl)
      {
         if (bl->isAlive() == true)
         {
            bl->draw();
         }
      }
      /*
      // Put the score on the screen
      Point scoreLocation;
      scoreLocation.setX(topLeft.getX() + 5);
      scoreLocation.setY(topLeft.getY() - 5);
      
      drawNumber(scoreLocation, score);

      Point timeLocation;
      timeLocation.setX(-topLeft.getX() -30);
      timeLocation.setY(topLeft.getY() -5);

      drawNumber(timeLocation, (timeCount / 30));

      if (timeCount <= 0)
      {
         drawText( Point(-30, 0), "Thanks for playing!");
      }*/
   }

}

