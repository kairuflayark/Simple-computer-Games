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
#include "ground.h"
#include "lander.h"

int Game::high1 = 0;
int Game::high2 = 0;
//bool Game::restart = false;
/******************************************
 * GAME :: JUST LANDED
 * Did we land successfully?
 ******************************************/
bool Game :: justLanded(Lander lander) const
{
   bool landed = false;
   
   Point platformCenter = ground.getPlatformPosition();
   int width = ground.getPlatformWidth();

   float xDiff = lander.getPoint().getX() - platformCenter.getX();
   float yDiff = lander.getPoint().getY() - platformCenter.getY();

   float margin = width / 2.0;
   
   if (fabs(xDiff) < margin)
   {
      // between edges
      
      if (yDiff < 4 && yDiff >= 0)
      {
         // right above it
         
         if (fabs(lander.getVelocity().getDx()) < 3 && fabs(lander.getVelocity().getDy()) < 3)
         {
            // we're there!
            landed = true;
         }
      }
   }
   
   return landed;
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
	if (start == true && pause == false)
   {
      if (lander1.isLanded() != true && lander1.isAlive() == true)
      {
         timeCounter++;
      }
       if (high1 == 0 && lander1.isLanded() == true)
         high1 = timeCounter;
      if (high1 >= timeCounter && lander1.isLanded() == true)
      {
         high1 = timeCounter;
      }
   	if (lander1.isAlive() && !lander1.isLanded())
   	{
      	// advance the lander
      	lander1.applyGravity(GRAVITY_AMOUNT);
   	   lander1.advance();                                      
         
      // check for crash
   	   if (!ground.isAboveGround(lander1.getPoint()))
   	   {
   	      lander1.setAlive(false);
   	   }
   
      // check for just landed
   	   if (justLanded(lander1))
   	   {
   	      lander1.setLanded(true);
   	   }
   	}
   }
   if (start == true && pause == false && player2 == true)
   {
      if (lander2.isLanded() != true && lander2.isAlive() == true)
      {
         timeCounter2++;
      }
       if (high2 == 0 && lander2.isLanded() == true)
         high2 = timeCounter2;
      if (high2 >= timeCounter2 && lander2.isLanded() == true)
      {
         high2 = timeCounter2;
      }
      if (lander2.isAlive() && !lander2.isLanded())
      {
         // advance the lander
         lander2.applyGravity(GRAVITY_AMOUNT);
         lander2.advance();                                      
         
      // check for crash
         if (!ground.isAboveGround(lander2.getPoint()))
         {
            lander2.setAlive(false);
         }
   
      // check for just landed
         if (justLanded(lander2))
         {
            lander2.setLanded(true);
         }
      }
   }
}


/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   if (start == false)
   {
      if (ui.isSpace())
         {
         start = true;
         }
      if (ui.isX())
         {
            start = true;
            player2 = true;
            lander1.setPoint(Point(-topLeft.getX() / 2, topLeft.getY()));
         }
   }
   
   if(start == true && pause == false)
   {
      if (lander1.isAlive() && !lander1.isLanded())
      {
   
         if (ui.isDown() && lander1.canThrust() == true)
         {
            lander1.applyThrustBottom();
         }
         
         if (ui.isLeft() && lander1.canThrust() == true)
         {
            lander1.applyThrustLeft();
         }
         
         if (ui.isRight() && lander1.canThrust() == true)
         {
            lander1.applyThrustRight();
         }

      }
   }

   if (player2 == true && pause == false)
      {
         if (lander2.isAlive() && !lander2.isLanded())
         {
      
            if (ui.isX() && lander2.canThrust() == true)
            {
               lander2.applyThrustBottom();
            }
            
            if (ui.isZ() && lander2.canThrust() == true)
            {
               lander2.applyThrustLeft();
            }
            
            if (ui.isC() && lander2.canThrust() == true)
            {
               lander2.applyThrustRight();
            }

         }
      }
   if (lander1.isLanded() || lander2.isLanded() && pause != true)
      {
      if (ui.isSpace())
            {
               restart = true;
               player2 = false;
            }
      }
   if (!lander1.isAlive() || !lander2.isAlive() && pause != true)
      {
      if (ui.isSpace())
            {
               restart = true;
               player2 = false;
            }
      }


   if (restart == true)
   {
      lander1.setFuel(FUEL);
      lander1.setPoint(Point(0, topLeft.getY()));
      start = false;
      restart = false;
      timeCounter = 0;
      timeCounter2 = 0;
      lander1.setLanded(false);
      lander1.setAlive(true);
      ground.generateGround();
      lander1.setVelocity(Velocity(0, 0));
      lander2.setFuel(FUEL);
      lander2.setPoint(Point(topLeft.getX() / 2, topLeft.getY()));
      lander2.setLanded(false);
      lander2.setAlive(true);
      lander2.setVelocity(Velocity(0, 0));
   }

   if (ui.isQ() && pause == false)
      pause = true;

   if (ui.isSpace() && pause == true)
      pause = false;

}


/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   Point startGame;
   if (start == false)
   {
         startGame.setX(-70);
         startGame.setY(0);
         drawText(startGame, "Press Space to Start.");
         startGame.setY(startGame.getY() - 11 );
         drawText(startGame, "For two players press X.");
         startGame.setY(startGame.getY() - 11 );
         drawText(startGame, "Controls        P1       P2");
         startGame.setY(startGame.getY() - 11 );
         drawText(startGame, "ThrustDown   Down    X");
         startGame.setY(startGame.getY() - 11 );
         drawText(startGame, "ThrustLeft      Left       Z");
         startGame.setY(startGame.getY() - 11 );
         drawText(startGame, "ThrustRight    Right     C");
         startGame.setY(startGame.getY() - 11 );
         drawText(startGame, "Press Q to Pause.");
         startGame.setY(startGame.getY() - 11 );
         drawText(startGame, "Press Space to continue.");


   
   }
   
   

   if(start == true)
   
   {
      lander1.draw();

      if (lander1.isLanded())
   	{
        	drawText(Point(0, topLeft.getY() / 2), "You have successfully landed!");
         drawText(Point(0, topLeft.getY() / 2 - 12), "To play again press Space.");
      }
   
   	if (!lander1.isAlive())
   	{
        	drawText(Point(0, 12), "You have crashed!");
         drawText(Point(0, 0), "To play again press Space.");    
   	}
   	if (lander1.canThrust() == true && pause == false)
      {
       	drawLanderFlames(lander1.getPoint(), ui.isDown(), ui.isLeft(), ui.isRight());
      }
            
      Point p1Name;
      p1Name.setX(-topLeft.getX() -50);
      p1Name.setY(topLeft.getY() - 15);
      drawText(p1Name, "Player 1");

      Point fuelLocation;
      fuelLocation.setX(-topLeft.getX() - 30);
      fuelLocation.setY(topLeft.getY() - 21);
      drawNumber(fuelLocation, lander1.getFuel());

      Point timeLocation;
      timeLocation.setX(-topLeft.getX() - 30);
      timeLocation.setY(topLeft.getY() - 37);

      drawNumber(timeLocation, timeCounter * 2);

      Point highLocation;
      highLocation.setX(-topLeft.getX() - 30);
      highLocation.setY(topLeft.getY() - 53);

      drawNumber(highLocation, high1 * 2);
   
      if (player2 == true)
      {
         
           lander2.draw();

           if (lander2.isLanded())
           {
               drawText(Point(0, topLeft.getY() / 2), "You have successfully landed!");
               drawText(Point(0, topLeft.getY() / 2 - 12), "To play again press Space.");
               
            }
      
           if (!lander2.isAlive())
           {
               drawText(Point(0, 12), "You have crashed!");
               drawText(Point(0, 0), "To play again press Space.");
                  
            }
           
         
           if (lander2.canThrust() == true && pause == false)
            {
               drawLanderFlames(lander2.getPoint(), ui.isX(), ui.isZ(), ui.isC());
            }
                 
         Point p2Name;
         p2Name.setX(topLeft.getX() + 5);
         p2Name.setY(topLeft.getY() - 15);
         drawText(p2Name, "Player 2");

         Point fuelLocation2;
         fuelLocation2.setX(topLeft.getX() + 5);
         fuelLocation2.setY(topLeft.getY() - 21);
         drawNumber(fuelLocation2, lander2.getFuel());

         if (timeCounter2 * 2 >= 1000)
            timeCounter2 /= 10;
         Point timeLocation2;
         timeLocation2.setX(topLeft.getX() + 5);
         timeLocation2.setY(topLeft.getY() - 37);

         drawNumber(timeLocation2, timeCounter2 * 2);

         Point highLocation2;
         highLocation2.setX(topLeft.getX() + 5);
         highLocation2.setY(topLeft.getY() - 53);

         drawNumber(highLocation2, high2 * 2);
      }



      // draw ground
      ground.draw();
   }
   
}

