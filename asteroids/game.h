/*************************************************************
 * File: game.h
 * Author: Br. Burton
 *
 * Description: The game of Skeet. This class holds each piece
 *  of the game (birds, bullets, rifle, score). It also has
 *  methods that make the game happen (advance, interact, etc.)
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#ifndef GAME_H
#define GAME_H


#include <list>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"

// TODO: include your bullet and bird classes
#include "bullet.h"
#include "rocks.h"
#include "ship.h"

#define CLOSE_ENOUGH 10
#define MAX_ASTEROIDS 5


/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
 class Game 
{
public:
   /*********************************************
    * Constructor
    * Initializes the game 

    *********************************************/
   Game(Point tl, Point br);
   ~Game();
   
   /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
   void handleInput(const Interface & ui);
   
   /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
   void advance();
   
   /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface & ui);
   
private:
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;
   
   int score;
   
   Ship ship;
   std::list<Bullet> bullets;
   bool shotgun;
   
   // TODO: declare your bird here (e.g., "Bird * bird;")
   std::list <Rock*> rocks;
   bool start;
   float timeCount;
   
   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/
   bool isOnScreen(const Point & point);
   void advanceBullets();
   void advanceRock();
   Rock* createLargeRock();
   void advanceShip();
   void splitRocks();


   void handleCollisions();
   void cleanUpZombies();
};

#endif /* GAME_H */
