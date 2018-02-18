#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct pObj {
  double x;   // position
  double y;
  double dx;  // velocity
  double dy;
  double ax;  // acceleration
  double ay;
  double r;   // radius of player object
  double g;   // player object gravity 
} pObj_t;

typedef struct targ {
  double x;  // position
  double y;  // position
  double r;  // radius of circular target

} targ_t; // player target

typedef struct gObj {
  double x;  // position
  double y;
  double r;  // object radius
  double g;  // object gravity
} gObj_t; // object which influences the player object

typedef struct grid {
  int width;
  int height;
  
} grid_t; // grid upon which objects lie
/* Constructors */

pObj_t createPObj() {
  pObj_t pObj;
  pObj.x  = 0.0;
  pObj.y  = 0.0;
  pObj.dx = 0.0;
  pObj.dy = 0.0;
  pObj.ax = 0.0;
  pObj.ay = 0.0;
  pObj.r  = 1.0;
  pObj.g  = 0.0;
  
  return pObj;
}

targ_t createTarg() {
  targ_t targ;
  targ.x = 0.0;
  targ.y = -1.0;
  targ.r = 1.0;
  
  return targ;
}

gObj_t createGObj() {
  gObj_t gObj;
  gObj.x = 1.0;
  gObj.y = 0;
  gObj.r = 1.0;
  gObj.g = 0.00000125;

  return gObj;
}

grid_t createGrid() {
  grid_t grid;
  grid.width  = 800;
  grid.height = 600;

  return grid;
}

/* Getters */

void printPObj( pObj_t p ) {
  printf("Position: (%f, %f) \n", p.x, p.y);
  printf("Velocity: (%f, %f) \n", p.dx, p.dy);
  printf("Acceleration: (%f, %f) \n", p.ax, p.ay);
  printf("Radius: %f \n", p.r);
  printf("Gravity: %f \n", p.g);
  return;
}

void printTarg( targ_t t ) {
  printf("Position: (%f, %f) \n", t.x, t.y);
  return;
}

void printGObj( gObj_t g ) {
  printf("Position: (%f, %f) \n", g.x, g.y);
  printf("Gravity: %f \n", g.g);
  return;
}

void printGrid( grid_t g ) {
  printf("Size: %d x %d \n", g.width, g.height);
  return;
}
  
/* Setters */

/* Updates */

int updatePlayer( pObj_t* p, grid_t* g ) {
  p->x += p->dx;
  p->y += p->dy;
  //printf("%f \n", p.x);
  p->dx += p->ax;
  p->dy += p->ay;
  return 1;
  return 0;
}

int updateTarg() {
  return 0;
}

int updateG() {
  return 0;
}

// return 1 if player wins
// win condition: player object encased in target
int checkWin( targ_t* t, pObj_t* p ) {
  double disp = sqrt( pow( t->x - p->x, 2) + pow( t->y - p->x, 2) );
  if( (disp + p->r) < (t->r) ) {
    return 1;
  }
  return 0;
}

// returns 1 if there is a collision
int checkColl( pObj_t* p,  gObj_t* g ) {
  double disp = sqrt( pow( g->x - p->x, 2) + pow( g->y -p->x, 2) );
  if( disp < (g->r + p->r) ) {
    return 1;
  }
  return 0; 
}

/* Helper Calculators */
double findAngle( pObj_t* p, gObj_t* g) {
  if( g->x - p->x != 0) {
    //printf("%f\n", g->y - p->y );
    //printf("%f\n", g->x - p->x );
    return atan2( g->y - p->y,g->x - p->x);
  }
  else {
    return M_PI/2;
  }
}


/* Applying Physics */

int applyGrav( pObj_t* p, gObj_t* g ) {
  p->ax = (g->g)*cos(findAngle(p, g));
  //printf("cos computed\n");
  p->ay = (g->g)*sin(findAngle(p, g));
  //printf("sin computed\n");
}
