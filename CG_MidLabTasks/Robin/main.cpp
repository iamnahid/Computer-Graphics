#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
/*glBegin(GL_POLYGON);
glColor3f (1.0f,1.0f,1.0f);
glVertex2i(50, 100);
glVertex2i(50, 100);
glVertex2i(100,100);
glVertex2i(100, 100);
glEnd();
*/glBegin(GL_POINTS);
glColor3f (0.0, 0.0, 0.0);//1st Black
glVertex2i(85, 380);
glColor3f (0.0, 0.0, 0.0);//1st Black
glVertex2i(100, 380);
glColor3f (0.0, 0.0, 0.0);//1st Black
glVertex2i(115, 380);

glColor3f (0.72, 0.45, 0.20);//2nd Brown
glVertex2i(85, 365);
glColor3f (1.0 , 0.7, 0.0);//2nd Cream
glVertex2i(100, 365);
glColor3f (1.0, 0.7, 0.0);//2nd Cream
glVertex2i(115, 365);

glColor3f (1.0, 0.9, 0.3);//3rd Dark yellow
glVertex2i(85, 350);
glColor3f (1.0, 0.7, 0.0);//3rd Cream
glVertex2i(100, 350);
glColor3f (0.9, 1.0, 0.0);//3rd yellow
glVertex2i(115, 350);

glColor3f (0.7, 0.1, 0.2);//4th Dark red
glVertex2i(70, 335);
glColor3f (0.9, 0.0, 0.1);//4th REd
glVertex2i(85, 335);
glColor3f (0.9, 0.0, 0.1);//4th Red
glVertex2i(100, 335);
glColor3f (0.9, 0.0, 0.1);//4th Red
glVertex2i(115, 335);
glColor3f (0.9, 0.0, 0.1);//4th Red
glVertex2i(130, 335);

glColor3f (0.0, 0.3, 0.1);//5th Dark Green
glVertex2i(55, 320);
glColor3f (0.7, 0.1, 0.2);//5th Dark Red
glVertex2i(70, 320);
glColor3f (0.9, 0.0, 0.1);//5th Red
glVertex2i(85, 320);
glColor3f (0.9, 0.0, 0.1);//5th Red
glVertex2i(100, 320);
glColor3f (1.0, 1.0, 1.0);//5th Black
glVertex2i(115, 320);
glColor3f (0.9, 0.0, 0.1);//5th red
glVertex2i(130, 320);
glColor3f (0.0, 0.5, 0.3);//5th Green
glVertex2i(145, 320);

glColor3f (1.0 , 0.7, 0.0);//6th Cream
glVertex2i(55, 305);
glColor3f (0.7, 0.1, 0.2);//6th Dark Red
glVertex2i(70, 305);
glColor3f (0.9, 0.0, 0.1);//6th Red
glVertex2i(85, 305);
glColor3f (0.9, 0.0, 0.1);//6th Red
glVertex2i(100, 305);
glColor3f (0.9, 0.0, 0.1);//6th Red
glVertex2i(115, 305);
glColor3f (0.9, 0.0, 0.1);//6th Red
glVertex2i(130, 305);
glColor3f (1.0 , 0.7, 0.0);//6th Cream
glVertex2i(145, 305);

glColor3f (0.72, 0.45, 0.20);// Brown
glVertex2i(55, 290);
glColor3f (0.9, 1.0, 0.0);//7th yellow
glVertex2i(70, 290);
glColor3f (0.9, 1.0, 0.0);//7th Yellow
glVertex2i(85, 290);
glColor3f (0.9, 1.0, 0.0);//7th Yellow
glVertex2i(100, 290);
glColor3f (0.9, 1.0, 0.0);//7th Yellow
glVertex2i(115, 290);
glColor3f (0.9, 1.0, 0.0);//7th Yellow
glVertex2i(130, 290);
glColor3f (0.72, 0.45, 0.20);// Brown
glVertex2i(145, 290);

glColor3f (1.0, 0.9, 0.3);//8th Dark yellow
glVertex2i(55, 275);
glColor3f (0.0, 0.5, 0.3);//8th Green
glVertex2i(70, 275);
glColor3f (0.0, 0.5, 0.3);//8th Green
glVertex2i(85, 275);
glColor3f (0.0, 0.5, 0.3);//8th Green
glVertex2i(100, 275);
glColor3f (0.0, 0.5, 0.3);//8th Green
glVertex2i(115, 275);
glColor3f (0.0, 0.5, 0.3);//8th Green
glVertex2i(130, 275);
glColor3f (1.0, 0.9, 0.3);//8th Dark yellow
glVertex2i(145, 275);

glColor3f (1.0, 0.9, 0.3);//9th Dark yellow
glVertex2i(55, 260);
glColor3f (0.72, 0.45, 0.20);//9th Brown
glVertex2i(70, 260);
glColor3f (0.0, 0.5, 0.3);//9th Green
glVertex2i(85, 260);
glColor3f (0.0, 0.5, 0.3);//9th Green
glVertex2i(100, 260);
glColor3f (0.0, 0.5, 0.3);//9th Green
glVertex2i(115, 260);
glColor3f (1.0 , 0.7, 0.0);//9th Cream
glVertex2i(130, 260);
glColor3f (1.0, 0.9, 0.3);//9th Dark yellow
glVertex2i(145, 260);

glColor3f (1.0, 0.9, 0.3);//10th Dark yellow
glVertex2i(55, 245);
glColor3f (0.72, 0.45, 0.20);//10th Brown
glVertex2i(70, 245);
glColor3f (1.0 , 0.7, 0.0);//10th cream
glVertex2i(85, 245);
glColor3f (1.0, 0.9, 0.3);//10th Dark yellow
glVertex2i(100, 245);
glColor3f (0.72, 0.45, 0.20);//10th brown
glVertex2i(115, 245);
glColor3f (1.0 , 0.7, 0.0);//10th cream
glVertex2i(130, 245);
glColor3f (1.0, 0.9, 0.3);//10th Dark yellow
glVertex2i(145, 245);

glColor3f (0.72, 0.45, 0.20);//11th brown
glVertex2i(70, 230);
glColor3f (1.0 , 0.7, 0.0);//11th cream
glVertex2i(85, 230);
glColor3f (1.0, 1.0, 1.0);//11th white
glVertex2i(100, 230);
glColor3f (0.72, 0.45, 0.20);//11th brown
glVertex2i(115, 230);
glColor3f (1.0 , 0.7, 0.0);//11th cream
glVertex2i(130, 230);

glColor3f (0.0, 0.3, 0.1);//12th dark green
glVertex2i(70, 215);
glColor3f (0.0, 0.5, 0.3);//12th green
glVertex2i(85, 215);
glColor3f (1.0, 1.0, 1.0);//12th white
glVertex2i(100, 215);
glColor3f (0.0, 0.3, 0.1);//12th dark green
glVertex2i(115, 215);
glColor3f (0.0, 0.5, 0.3);//12th green8
glVertex2i(130, 215);
glEnd();

glFlush ();
}
void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(15.0);
glLineWidth(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Hello OpenGL");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
