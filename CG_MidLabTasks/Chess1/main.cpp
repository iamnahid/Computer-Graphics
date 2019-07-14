#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

for (int c=0; c<8; c++)
{

    for (int i = 50;i <= 400 ; i=i+50)
    {

        for (int j = 600; j>=200; j= j-50)
            {
                int a,b,c;
                a = i;
                b = j;

                if ( c%2 == 0 )
                {
                    glColor3f (0.0,0.0,0.0);
                    glBegin(GL_POLYGON);
                    glVertex2i(a, b);
                    glVertex2i(a + 50, b);
                    glVertex2i(a + 50, b - 50);
                    glVertex2i(a, b - 50);
                    glEnd();
                    glFlush ();

                }
                else
                {
                    glColor3f (1.0,1.0,1.0);
                    glBegin(GL_POLYGON);
                    glVertex2i(a, b);
                    glVertex2i(a + 50, b);
                    glVertex2i(a + 50, b - 50);
                    glVertex2i(a, b - 50);
                    glEnd();
                    glFlush ();

                }
                c++;

            }
            c++;

    }
}
//glPointSize(3.0);
glBegin(GL_LINE_LOOP);
glColor3f (1.0, 1.0, 1.0);
glVertex2d(50,200);
glColor3f (1.0, 1.0, 1.0);
glVertex2d(50,600);
glColor3f (1.0, 1.0, 1.0);
glVertex2d(450,600);
glColor3f (1.0, 1.0, 1.0);
glVertex2d(450,200);
glEnd();
glFlush();


}
void myInit (void)
{
glClearColor(0.0,0.0, 0.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
//glPointSize(30.0);
//glLineWidth(3.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1080.0, 0.0, 720.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1080, 720);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Knight is the King !");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
