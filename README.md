# Mountain-Madness-2018
The goal was to create a game with which the user could play with gravity. 
We want to be able to add multiple objects, and a single player object with adjustable gravity. 
The player gives some initial parameters to the player object, with the end goal of hitting the target.

# physics.c
Contains the physics engine. Contains structs representing the player object, and "gravity objects". 
The target struct represents a target for the player object. 

# graphics.c
Unfinished. The main challenge was trying to pass pObj_t positions to display() 
so the pObj position would be reflected in the graphics.

