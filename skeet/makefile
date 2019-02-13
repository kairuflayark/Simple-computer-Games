###############################################################
# Program:
#     Project , Skeet
#     Brother Comeau, CS165
# Author:
#     James Call
# Summary:
#     The Program creates a game where the user attempts to shoot down various birds
#		with a rifle
# Above and Beyond
#	Added S bird which when killed activates a Shotgun Burst
#	Added Multiple birds to the game
#	Added a time counter that ends game when it runs out
#
#
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o flyingObject.o bullet.o bird.o velocity.o allBirds.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o flyingObject.o bullet.o bird.o velocity.o allBirds.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c -g uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c -g uiInteract.cpp

point.o: point.cpp point.h
	g++ -c -g point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bird.h
	g++ -c -g game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c -g driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c -g rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
flyingObject.o: flyingObject.cpp flyingObject.h point.h  velocity.h
	g++ -c -g flyingObject.cpp

bird.o: bird.h bird.cpp flyingObject.h 
	g++ -c -g bird.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h 
	g++ -c -g bullet.cpp

velocity.o: velocity.cpp velocity.h
	g++ -c -g velocity.cpp

allBirds.o: allBirds.h allBirds.cpp bird.h
	g++ -c -g allBirds.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
