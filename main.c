#include "physics.c"
#include "graphics.c"
#include <unistd.h>
#include <GL/glut.h>

const size_t DELAY = 2e4;

void drawP( float px, float py, float pz, double radius ) {
  glColor3f(0.0, 1.0, 0.0);
  glTranslatef( px, py, pz );
  glutSolidSphere( radius, 7, 7);
}

void drawTarg( float px, float py, float pz, double radius ) {
  glColor3f( 1.0, 0.0, 0.0 );
  glTranslatef( px, py, pz );
  glutSolidSphere( radius, 7, 7);
}

void drawG( float px, float py, float pz, double radius ) {
  glColor3f( 0.0, 0.0, 1.0 );
  glTranslatef( px, py, pz );
  glutSolidSphere( radius, 7, 7);
}

void render() {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glLoadIdentity();
  gluLookAt( 0.0f, 0.0f, 10.0f,
	     0.0f, 0.0f, 0.0f,
	     0.0f, 1.0f, 0.0f);
  //drawP( 0.0, 0.0, 0.0, 1 );
  //drawTarg( 0.0, -1.0, 0.0, 1 );
  //drawG( 1.0, 0.0, 0.0, 1 );
  glutSwapBuffers();
}

//float posX = 0.01;
//float posY = -0.1;
//float posZ = 0;

float tPosX = 0.0;
float tPosY = 0.1;
float tPosZ = 0;

float gPosX = -0.1;
float gPosY = 0;
float gPosZ = 0;

void circ() {
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_TRIANGLE_FAN);
  for (int i = 0; i <= 300; i++) {
    angle = 2 * M_PI * i / 300;
    double x = cos(angle) / 20;
    double y = sin(angle) / 20;
    glVertex2d(x, y);
  }
  glEnd();
}

void display() {
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glPushMatrix();
  glTranslatef(posX, posY, posZ);
  circ();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(tPosX, tPosY, tPosZ);
  circ();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(gPosX, gPosY, gPosZ);
  circ();
  glPopMatrix();

  applyGrav
  
  glutSwapBuffers();
}

float move_unit = 0.02f;
void keyboarddown(int key, int x, int y) {
  switch (key) {
  case GLUT_KEY_RIGHT:
    posX += move_unit;
    break;
  case GLUT_KEY_LEFT:
    posX -= move_unit;
    break;
  case GLUT_KEY_UP:
    posY += move_unit;
    break;
  case GLUT_KEY_DOWN:
    posY -= move_unit;
    break;
  default:
    break;
  }
  glutPostRedisplay();
}
  

void update() {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glTranslatef( posX, posY, posZ );
  drawPolygon();
  glutPostRedisplay();
}

int main( int argc, char** argv ) {

  // GLUT initialization
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA );
  glutInitWindowPosition( 100, 100 );
  glutInitWindowSize( 320, 320 );
  glutCreateWindow( "" );

  pObj_t player = createPObj();
  targ_t target = createTarg();
  gObj_t grav   = createGObj();
  grid_t grid   = createGrid();
  // glutDisplayFunc( render );
  //glutReshapeFunc( changeSize );
  //glutIdleFunc( render );
  glutDisplayFunc(display);
  glutSpecialFunc(keyboarddown);
  glutMainLoop();

  return 0;
}
