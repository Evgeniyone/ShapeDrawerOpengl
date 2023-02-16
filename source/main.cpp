#include <GL/glut.h>

#include "Render.h"

void TimerFunc(int nTimerID) {

  ShapeDrawer::Render::Draw();
  glutPostRedisplay();
  glutTimerFunc(10, TimerFunc, 1);
}
void Init(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowPosition(80, 80);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("A Simple Triangle");

  glutTimerFunc(1, TimerFunc, 1);

  glutMainLoop();
}



int main(int argc, char** argv) {
  Init(argc, argv);
}