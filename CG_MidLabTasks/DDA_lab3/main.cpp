#include <windows.h>
#include <iostream>
#include <gl/glut.h>
#include <math.h>
//#include <stdio.h>
using namespace std;
//float PI = 3.14;
int a,b,c,d;
void DDA(int x0,int y0,int x1, int y1)
{
    glBegin(GL_POINTS);
    glColor3f(0.0,1.0,0.0);
    double x = double(x0);
    double y = double(y0);
    double m = double (y1-y0)/ (x1-x0);

    if ( m <= 1 )
    {
        while ( x <= x1)
        {
            glVertex2d(x,floor(y));
            y =y+m;
            x++;
        }
    }
    else
    {
        double m1 = 1/m;
        while ( y <= y1)
        {
            glVertex2d(x,floor(y));
            y ++;
            x=x+m1;
        }
    }
    glEnd();
//    display();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    DDA(a,b,c,d);
    //DDA(10, 20, 20, 30);
    /*DDA(20, 30, 30, 40);
    DDA(30,40,40,50);*/
    glutSwapBuffers();
}
void init (void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   // glPointSize(15.0);
    glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
}


int main(int argc, char** argv)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(620,480);
    glutInitWindowPosition(50,50);
    glutCreateWindow("DDA !!");
    init();
    //int a,b,c,d;
    cout<<" PLease input X1, X2, Y1 , Y2: "<<endl;
    cout<<" PLease press after Each input !! ";
    cin>>a>>b>>c>>d;
    DDA(a,b,c,d);
    glutDisplayFunc(display);
    //glutSwapBuffers();
    glutMainLoop();
    return 0;
}
