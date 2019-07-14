#include<windows.h>
#include<gl/glut.h>
#include<stdio.h>
#include <iostream>

using namespace std;

float R = 0.0 ,G = 1.0,B = 0.0, L = 0.0;
static GLfloat spin = 0.0;
static GLfloat spin_speed = 0.1;
float spin_x = 0;
float spin_y = 0;
float spin_z = 1;
float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;
// assuming work-window width=50unit, height=25unit;
void init()
{
glClearColor(0,0,0,0);
glLineWidth(L);
glShadeModel(GL_SMOOTH); // Enable Smooth Shading
glClearDepth(1.0f); // Depth Buffer Setup
glEnable(GL_DEPTH_TEST); // Enables Depth Testing
}
//------- custom functions starts -------
void setSpin(float x, float y, float z)
{
spin_x = x;
spin_y = y;
spin_z = z;
}
void setColor(float r, float g, float b)
{
    R = r;
    G = g;
    B = b;
    glColor3f(R,G,B);
}
void setLength()
{
    //L = l;
    if ( L < 10)
    {
        L++;
        glLineWidth(L);
    }
    else
    {
        L = 0;
        glLineWidth(L);
    }

}
void reset()
{
spin_x = 0;
spin_y = 1;
spin_z = 0;
translate_x = 0.0;
translate_y = 0.0;
translate_z = -30.0;
}
//------- custom functions ends -------

void reshape(int w,int h)
{
glViewport(0,0, (GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void Tri(){
glBegin(GL_LINES);
glColor3f(R,G,B);
glPointSize(100.0);
glVertex2i(0, 0);
glColor3f(R,G,B);
glVertex2i(0, -20);
glFlush();
//2nd
glBegin(GL_LINES);
glColor3f(R,G,B);
glPointSize(100.0);
glVertex2i(0, 0);
glColor3f(R,G,B);
glVertex2i(20, 0);
glFlush ();
//3rd
glBegin(GL_LINES);
glColor3f(R,G,B);
glPointSize(100.0);
glVertex2i(0, 0);
glColor3f(R,G,B);
glVertex2i(0, 20);
glFlush();
//4th
glBegin(GL_LINES);
glColor3f(R,G,B);
glPointSize(100.0);
glVertex2i(0, 0);
glColor3f(R,G,B);
glVertex2i(-20, 0);
glFlush ();
//5th
glBegin(GL_LINES);
glColor3f(R,G,B);
glPointSize(100.0);
glVertex2i(0, 0);
glColor3f(R,G,B);
glVertex2i(10, -16);
glFlush();
//6th
glBegin(GL_LINES);
glColor3f(R,G,B);
glPointSize(100.0);
glVertex2i(0, 0);
glColor3f(R,G,B);
glVertex2i(10, 16);
glFlush ();
glEnd();
glFlush ();
//7th
glBegin(GL_LINES);
glColor3f(R,G,B);
glPointSize(100.0);
glVertex2i(0, 0);
glColor3f(R,G,B);
glVertex2i(-10, 16);
glFlush();
//8th
glBegin(GL_LINES);
glColor3f(R,G,B);
glPointSize(100.0);
glVertex2i(0,0);
glColor3f(R,G,B);
glVertex2i(-10, -16);
glFlush ();
glEnd();
glFlush ();
}
void Stand(void){

glBegin(GL_QUADS);
glColor3f(1,1,1);
glPointSize(10.0);
glVertex2i(0, 0);
glVertex2i(-1, -20);
glVertex2i(2, -20);
glVertex2i(0, 0);
glEnd();
glFlush ();
}

void myDisplay()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(translate_x, translate_y, translate_z);
Stand();
glRotatef(spin,spin_x,spin_y,spin_z);
//******************************************//
//------- custom code starts -------
Tri();

//------- custom code ends -------
//******************************************//
glutSwapBuffers();
}
void spinDisplay(void)
{
spin=spin+spin_speed;
if(spin>360.0)
{
spin=spin-360.0;
}
glutPostRedisplay();
}
void spinDisplayReverse(void)
{
spin=spin-spin_speed;
if(spin<360.0)
{
spin=spin+360.0;
}
glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
switch(button)
{
case GLUT_LEFT_BUTTON:
if(state==GLUT_DOWN)
glutIdleFunc(spinDisplay);
break;
case GLUT_MIDDLE_BUTTON:
if(state==GLUT_DOWN)
{
glutIdleFunc(NULL);
}
break;
case GLUT_RIGHT_BUTTON:
if(state==GLUT_DOWN)
glutIdleFunc(spinDisplayReverse);
break;
default:
break;
}
}
void keyboard(unsigned char key, int x, int y)
{
//-------- spin --------
if(key=='x')
{
setSpin(1.0,0.0,0.0);
glutPostRedisplay();
}
else if(key=='y')
{
setSpin(0.0,1.0,0.0);
glutPostRedisplay();
}
else if(key=='5')
{
spin_speed = spin_speed*2;
glutPostRedisplay();
}
else if(key=='z')
{
setSpin(0.0,0.0,1.0);
glutPostRedisplay();
}
else if(key=='a')
{
setSpin(1.0,1.0,1.0);
glutPostRedisplay();
}
//-------- spin --------
//-------- zoom --------
else if(key=='i')
{
translate_z++;
glutPostRedisplay();
}
else if(key=='o')
{
translate_z--;
glutPostRedisplay();
}
//-------- zoom --------
//-------- reset -------
else if(key=='r')
{
reset();
glutPostRedisplay();
}
else if(key=='1')
{
setColor(1.0, 0.0, 0.0);
glutPostRedisplay();
}
else if(key=='2')
{
setColor(0.0, 0.0, 1.0);
glutPostRedisplay();
}
else if(key=='3')
{
setColor(0.0, 1.0, 0.0);
glutPostRedisplay();
}
else if(key=='l')
{
setLength();
glutPostRedisplay();
}
//-------- reset -------
}



int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (620, 480);
glutInitWindowPosition (20, 25);
glutCreateWindow ("Rotation");
init ();
/////////Please Use these Functions/////////
glutDisplayFunc(myDisplay);
glutReshapeFunc(reshape);
glutMouseFunc(mouse);
glutKeyboardFunc(keyboard);





glutMainLoop();
return 0;
}









