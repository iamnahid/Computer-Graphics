#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

// Cross Line
glBegin(GL_LINES);
glColor3f (0.0, 1.0, 0.0);
glVertex2i(0, 280);
glColor3f (0.0, 1.0, 0.0);
glVertex2i(1080, 280);
glEnd();
glBegin(GL_LINES);
glColor3f (0.0, 1.0, 0.0);
glVertex2i(450, 0);
glColor3f (0.0, 1.0, 0.0);
glVertex2i(450, 720);
glEnd();

// Triangle circle
glBegin(GL_LINE_LOOP);
glColor3f (0.0, 1.0, 0.8);
glVertex2d(540,85);
glColor3f (0.0, 1.0, 0.8);
glVertex2d(540,165);
glColor3f (0.0, 1.0, 0.8);
glVertex2d(680,125);
glEnd();
glBegin(GL_LINE_LOOP);
glColor3f (1.0, 0.8, 0.0);
glVertex2d(620,205);
glColor3f (1.0, 0.8, 0.0);
glVertex2d(660,225);
glColor3f (1.0, 0.8, 0.0);
glVertex2d(680,125);
glEnd();
glBegin(GL_LINE_LOOP);
glColor3f (0.0, 1.0, 0.8);
glVertex2d(740,205);
glColor3f (0.0, 1.0, 0.8);
glVertex2d(820,105);
glColor3f (0.0, 1.0, 0.8);
glVertex2d(680,125);
glEnd();
glBegin(GL_LINE_LOOP);
glColor3f (1.0, 0.8, 0.0);
glVertex2d(600,45);
glColor3f (1.0, 0.8, 0.0);
glVertex2d(660,65);
glColor3f (1.0, 0.8, 0.0);
glVertex2d(680,125);
glEnd();
glBegin(GL_LINE_LOOP);
glColor3f (0.0, 1.0, 0.8);
glVertex2d(730,55);
glColor3f (0.0, 1.0, 0.8);
glVertex2d(780,75);
glColor3f (0.0, 1.0, 0.8);
glVertex2d(680,125);
glEnd();

// Windows Icon
glColor3f (0.0, 0.5, 1.0);
glBegin(GL_POLYGON);
glVertex2i(50,600);
glVertex2i(150,630);
glVertex2i(150,500);
glVertex2i(50,500);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(160,633);
glVertex2i(280,663);
glVertex2i(280,500);
glVertex2i(160,500);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(50,490);
glVertex2i(150,490);
glVertex2i(150,360);
glVertex2i(50,390);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(160,490);
glVertex2i(280,490);
glVertex2i(280,330);
glVertex2i(160,357);
glEnd();


// Mail
glBegin(GL_TRIANGLES);
glColor3f (1.0, 1.0, 1.0);
glVertex2i(50, 100);
glColor3f (1.0, 1.0, 1.0);
glVertex2i(50, 200);
glColor3f (1.0, 1.0, 1.0);
glVertex2i(130, 150);
glEnd();
glBegin(GL_LINE_LOOP);
glColor3f (0.0, 0.5, 1.0);
glVertex2d(290,215);
glColor3f (0.0, 0.5, 1.0);
glVertex2d(65,215);
glColor3f (0.0, 0.5, 1.0);
glVertex2d(175,135);
glEnd();
glBegin(GL_LINE_LOOP);
glColor3f (0.0, 0.5, 1.0);
glVertex2d(290,85);
glColor3f (0.0, 0.5, 1.0);
glVertex2d(65,85);
glColor3f (0.0, 0.5, 1.0);
glVertex2d(175,165);
glEnd();
glBegin(GL_TRIANGLES);
glColor3f (1.0, 1.0, 1.0);
glVertex2i(305, 100);
glColor3f (1.0, 1.0, 1.0);
glVertex2i(305, 200);
glColor3f (1.0, 1.0, 1.0);
glVertex2i(225, 150);
glEnd();


// Printer
glPointSize(5.0);
glBegin(GL_LINE_LOOP);
glColor3f (1.0, 1.0, 1.0);
glVertex2i(550, 550);
glColor3f (1.0, 1.0, 1.0);
glVertex2i(950, 550);
glColor3f (1.0, 1.0, 1.0);
glVertex2i(950, 400);
glColor3f (1.0, 1.0, 1.0);
glVertex2i(550, 400);
glEnd();
glBegin(GL_LINE_LOOP);
glColor3f (0.0, 1.0, 0.5);
glVertex2i(650, 600);
glColor3f (0.0, 1.0, 0.5);
glVertex2i(850, 600);
glColor3f (0.0, 1.0, 0.5);
glVertex2i(850, 500);
glColor3f (0.0, 1.0, 0.5);
glVertex2i(650, 500);
glEnd();
glBegin(GL_LINE_LOOP);
glColor3f (0.0, 1.0, 0.5);
glVertex2i(650, 450);
glColor3f (0.0, 1.0, 0.5);
glVertex2i(850, 450);
glColor3f (0.0, 1.0, 0.5);
glVertex2i(850, 350);
glColor3f (0.0, 1.0, 0.5);
glVertex2i(650, 350);
glEnd();
glFlush ();
}
void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(15.0);
glLineWidth(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1080.0, 0.0, 720.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1080, 720);
glutInitWindowPosition (0, 50);
glutCreateWindow ("4 items");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
