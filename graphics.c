#include <GL/glut.h>
#include <math.h>

static int radius = 2;

void changeSize(int w, int h) {
  if( h == 0 ) {
    h = 1;
  }

  float ratio = w * 1.0 / h;

  glMatrixMode( GL_PROJECTION );

  glLoadIdentity();

  glViewport(0, 0, w, h);

  gluPerspective(45,ratio,1,100);

  glMatrixMode(GL_MODELVIEW);
}

float angle = 0.0f;

void drawPolygon() {
  glBegin(GL_POLYGON);
  for(double i = 0; i < 2*M_PI; i += M_PI/6) {
    glVertex3f(cos(i) * radius, sin(i) * radius, 3.0);
  }
  glEnd();
}

//float ballX = 0.0f;
//float ballY = 0.0f;
//float ballZ = -1.0f;

void drawBall(float ballX, float ballY, float ballZ) {
  glColor3f(0.0, 1.0, 0.0);
  glTranslatef(ballX, ballY, ballZ);
  glutSolidSphere(0.6, 7, 7);
}
float bx = 0.0f;
/*
void renderScene(void) {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  gluLookAt( 0.0f, 0.0f, 10.0f,
	     0.0f, 0.0f, 0.0f,
	     0.0f, 1.0f, 0.0f);
  drawBall(bx, 0.0f, -1.0f);
  drawBall(bx, 0.0f, -1.0f);
  glutSwapBuffers();
}


int main(int argc, char** argv) {

  // init GLUT and create window
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(320,320);
  glutCreateWindow("Lighthouse3D - GLUT Tutorial");

  // register callbacks
  glutDisplayFunc(renderScene);
  glutReshapeFunc(changeSize);
  glutIdleFunc(renderScene);
  // enter GLUT event processing cycle
  glutMainLoop();
  return 1;
}
*/
