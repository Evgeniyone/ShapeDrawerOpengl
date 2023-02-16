#include "Shape.h"

#include <GL/glut.h>
#include <math.h>

namespace ShapeDrawer {

void Rectangle::Draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3d(1, 0, 0);
  glRectf(atributes_.point_1.x, atributes_.point_1.y, atributes_.point_2.x,
          atributes_.point_2.y);
  glFlush();
}

void Circle::Draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  int i;
  int triangleAmount = 100;

  GLfloat twicePi = 2.0f * 3.14159265f;
  glBegin(GL_TRIANGLE_FAN);
  glColor3d(1, 0, 1);
  glVertex2d(atributes_.center.x, atributes_.center.y);
  for (i = 0; i <= triangleAmount; i++) {
    glVertex2d(atributes_.center.x +
                   atributes_.radius * cos(i * twicePi / triangleAmount),
               atributes_.center.y +
                   atributes_.radius * sin(i * twicePi / triangleAmount));
  }
  glEnd();
  glFlush();
}

void Square::Draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  float halfside = atributes_.side_length / 2;

  glColor3d(1, 1, 0);
  glBegin(GL_POLYGON);

  glVertex2d(atributes_.point.x + halfside, atributes_.point.y + halfside);
  glVertex2d(atributes_.point.x + halfside, atributes_.point.y - halfside);
  glVertex2d(atributes_.point.x - halfside, atributes_.point.y - halfside);
  glVertex2d(atributes_.point.x - halfside, atributes_.point.y + halfside);

  glEnd();
  glFlush();
}

void Triangle::Draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glColor3d(1, 1, 1);

  glBegin(GL_POLYGON);
  glVertex2d(atributes_.point_1.x, atributes_.point_1.y);
  glVertex2d(atributes_.point_2.x, atributes_.point_2.y);
  glVertex2d(atributes_.point_3.x, atributes_.point_3.y);
  glEnd();
  glFlush();
}

}  // namespace ShapeDrawer