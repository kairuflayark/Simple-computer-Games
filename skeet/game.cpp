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

#include <vector>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5



/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br), rifle(br)
{
   // Set up the initial conditions of the game
   score = 0;

   // TODO: Set your bird pointer to a good initial value (e.g., NULL)
   for (int i = 0; i < MAX_BIRDS; i++)
   {
   bird[i] = NULL;
   }
   shotgun = false;
   start = false;
   timeCount = 1800;
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   for (int i = 0; i < MAX_BIRDS; i++)
   {
      if (bird[i] != NULL)
      {
         delete bird[i];
         bird[i] = NULL;
      }


   }

   // TODO: Check to see if there is currently a bird allocated
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
   advanceBird();
   timeCount--;
   handleCollisions();
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
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();
         
         if (!isOnScreen(bullets[i].getPoint()))
         {
            // the bullet has left the screen
            bullets[i].kill();
         }
         
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE BIRD
 *
 * 1. If there is no bird, create one with some probability
 * 2. If there is a bird, and it's alive, advance it
 * 3. Check if the bird has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceBird()
{
   for (int i = 0; i < MAX_BIRDS; i++)
   {
      if (bird[i] == NULL)
      {
         // there is no bird right now, possibly create one
         
         // "resurrect" it will some random chance
         if (random(0, 30) == 0)
         {
            // create a new bird
            bird[i] = createBird();
         }
      }
      else
      {
         // we have a bird, make sure it's alive
         if (bird[i]->isAlive())
         {
            // move it forward
            bird[i]->advance();
            
            // check if the bird has gone off the screen
            if (!isOnScreen(bird[i]->getPoint()))
            {
               // We have missed the bird
               bird[i]->kill();
            }
         }
      }
   }
}

/**************************************************************************
 * GAME :: CREATE BIRD
 * Create a bird of a random type according to the rules of the game.
 **************************************************************************/
Bird* Game :: createBird()
{
    int randomBird = random(1, 12);

    Bird* newBird = NULL;   


   
    newBird = birdFactory.instantiateBird(randomBird, topLeft.getX(), bottomRight.getY(), topLeft.getY());
   

   return newBird;
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
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
   {
      for (int s = 0; s < MAX_BIRDS; s++ )
   
      // now check for a hit (if it is close enough to any live bullets)
      for (int i = 0; i < bullets.size(); i++)
      {
         if (bullets[i].isAlive())
         {
            // this bullet is alive, see if its too close

            // check if the bird is at this point (in case it was hit)
            if (bird[s] != NULL && bird[s]->isAlive())
            {
               // BTW, this logic could be more sophisiticated, but this will
               // get the job done for now...
               if (fabs(bullets[i].getPoint().getX() - bird[s]->getPoint().getX()) < CLOSE_ENOUGH
                   && fabs(bullets[i].getPoint().getY() - bird[s]->getPoint().getY()) < CLOSE_ENOUGH)
               {
                  //we have a hit!
                  
                  // hit the bird
                  int points = bird[s]->hit();
                  score += points;
                  if (bird[s]->getHp() == 0)
                  {
                     bird[s]->kill();
                     points = bird[s]->getScore();
                     score += points;
                     if (shotgun == false)
                     {
                        shotgun = bird[s]->getShotgun();
                     }
                  }
                  // the bullet is dead as well
                  bullets[i].kill();
               }
            }
         } // if bullet is alive
         
      } // for bullets
   }
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // check for dead bird
   for (int i = 0; i < MAX_BIRDS; i++)
   {
      if (bird[i] != NULL && !bird[i]->isAlive())
      {
         // the bird is dead, but the memory is not freed up yet      
         // TODO: Clean up the memory used by the bird
   
      delete bird[i];
      bird[i] = NULL;

      }
   }
   
   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;
      
      if (!bullet.isAlive())
      {
         // If we had a list of pointers, we would need to delete the memory here...
         
         
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
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

   // Change the direction of the rifle
   if (ui.isLeft() && start == true)
   {
      rifle.moveLeft();
   }
   
   if (ui.isRight() && start == true)
   {
      rifle.moveRight();
   }
   
   // Check for "Spacebar
   if (ui.isSpace()  && start == true)
   {
      //TODO fix shotgun
      if( shotgun == true)
      {
         float angle = -20.0;
         Bullet newBullet;
         for (int i = 0; i <= 9; i++)
         {
            newBullet.fire(rifle.getPoint(), (rifle.getAngle() + angle));
            angle += 5.0;
            bullets.push_back(newBullet);
         }
         shotgun = false;

      }
      else
      { 
      Bullet newBullet;
      newBullet.fire(rifle.getPoint(), rifle.getAngle());
      
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
      drawText( Point(-60, -11), "Shoot Birds until time runs out");
      drawText( Point(-60, -22), "Shoot S birds to reload your shotgun");
      drawText( Point(-60, -33), "And make sure not to hit the Sacred Birds!");
   }


   if (start == true)
   {
      // draw the bird
      for (int i = 0; i < MAX_BIRDS; ++i)
      {
      
      // TODO: Check if you have a valid bird and if it's alive
      // then call it's draw method
      if (bird[i] != NULL && bird[i]->isAlive())

      bird[i]->draw();
      }
      // draw the rifle
      rifle.draw();
      
      // draw the bullets, if they are alive
      for (int i = 0; i < bullets.size(); i++)
      {
         if (bullets[i].isAlive())
         {
            bullets[i].draw();
         }
      }
      
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
      }
   }

}

