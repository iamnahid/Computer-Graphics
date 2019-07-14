#include<iostream>
#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

using namespace std;


void  myDisplay();


int xmax,xmin,ymax,ymin,m1,n1,m2,n2;


typedef int OutCode;

const int I = 0; // 0000
const int L = 1;   // 0001
const int R = 2;  // 0010
const int B = 4; // 0100
const int T = 8;    // 1000

OutCode ComputeOutCode(double x, double y)
{
	OutCode code;

	code = I;

	if (x < xmin)
		code |= L;
	else if (x > xmax)
		code |= R;
	if (y < ymin)
		code |= B;
	else if (y > ymax)
		code |= T;

	return code;
}

void Clipping(int x0, int y0, int x1, int y1)
{
	OutCode outcode0 = ComputeOutCode(x0, y0);
	OutCode outcode1 = ComputeOutCode(x1, y1);
	bool accept = false;

	while (true) {
		if (!(outcode0 | outcode1))
            {
                accept = true;
                break;
		    }
		else if (outcode0 & outcode1)
            {
                break;
		    }
		else {
			double x, y;

			OutCode outcodeOut = outcode0 ? outcode0 : outcode1;

			if (outcodeOut & T)
                {
                    x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                    y = ymax;
			    }
			else if (outcodeOut & B)
                {
                    x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                    y = ymin;
			    }
			else if (outcodeOut & R)
			 {
				y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
				x = xmax;
			}
			else if (outcodeOut & L)
                {
                    y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                    x = xmin;
			    }

			if (outcodeOut == outcode0)
                {
                    m1 = x;
                    n1 = y;
                    outcode0 = ComputeOutCode(m1, n1);
			    }
			else
                {
                    m2 = x;
                    n2 = y;
                    outcode1 = ComputeOutCode(m2, n2);
			    }
		}
	}
	if (accept) {}	myDisplay();
}

void myDisplay(void)
{

    glClear (GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_LOOP);
    glColor3f (0.0, 1.0, 0.0);
    glVertex2i(xmin,ymin);
    glVertex2i(xmax,ymin);
    glVertex2i(xmax,ymax);
    glVertex2i(xmin,ymax);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f (0.0, 1.0, 0.0);
    glVertex2i(m1,n1);
    glVertex2i(m2,n2);
    glEnd();
    glFlush ();

}
void myInit (void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLineWidth(2.0);
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

int main(int argc, char** argv)
{
//    sleep(1);
    cout<<" ----------------- Cohen Sutherland Line Clipping Algorithm -----------------\n\n"<<endl;
    cout<<" ########## enter the clipping window size ###########\n"<<endl;
    cout<<"Xmin: ";
    cin>>xmin;
    cout<<"\nYmin: ";
    cin>>ymin;
    cout<<"\Xmax: ";
    cin>>xmax;
    cout<<"\nYmax: ";
    cin>>ymax;
    cout<<endl<<endl;

    cout<<"************ enter line cordinates *************\n"<<endl;
    cout<<"X0: ";
    cin>>m1;
    cout<<"\nY0: ";
    cin>>n1;
    cout<<"\X1: ";
    cin>>m2;
    cout<<"\nY1: ";
    cin>>n2;
    cout<<endl<<endl;


    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (400,150);
    glutCreateWindow ("Hello OpenGL");
    glutDisplayFunc(myDisplay);
    Clipping(m1,n1,m2,n2);
    myInit ();
    glutMainLoop();
}
