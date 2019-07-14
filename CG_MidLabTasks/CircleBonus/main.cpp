#include <iostream>
#include <windows.h>
#include <gl/glut.h>
#include <math.h>
#include <ctime>
#include <stdio.h>

    using namespace std;
  int ww=1600,wh=900;
  int R = 0, M = 0, L = 0;
  float P = 0.0,R1=0.3,Q =0.0,G=0.5,B=0.2;

  float color()
  {

      if( R1 <= 0.0 || B <=1.0)
      {
          R1=G;
          G=R1+G;
          B=G-0.2;
      }
      else
      {
          G = 0.4;
         R1=0.0;
         B=0.0;
      }return R1,G,B;


  }
  float Center()
  {
      if ( P <= 1600 && Q <= 900)
      {
          srand(time(NULL));
          P= P+ (rand() % 10) ;
          Q = Q+(rand() % 10 );
          cout<<endl<<P<<" "<<Q<<endl;
          return P,Q;
      }
    }

  void Mid(int r)
  {
        //M = R;
        //glBegin(GL_POINTS);
        //glColor3f(0.0,1.0,0.0);
        int x=0,y=r,p=1-r;
        while ( x <= y)
              {

                  glBegin(GL_POINTS);
                  glColor3f(R1,G,B+0.2);
                  glVertex2d(P + x, floor(Q + y));
                  glVertex2d(P + y, floor(Q + x));
                  glVertex2d(P - y, floor(Q + x));
                  glVertex2d(P - x, floor(Q + y));
                  glVertex2d(P - x, floor(Q - y));
                  glVertex2d(P - y, floor(Q - x));
                  glVertex2d(P + y, floor(Q - x));
                  glVertex2d(P + x, floor(Q - y));

                  if ( p < 0 )
                    {
                        p = p + 2*x + 3;
                    }
                    else
                    {
                        p = p + 2*(x-y)+5;
                        y--;
                    }
                    x++;
               }
               glEnd();
               glFlush();
//               myinit();


}
int limit ( int m )
  {
      M = m;

      return M;
  }

void display()
  {
      int f =0, s =1, n = 0;
      for (int i= 0; i < M; i++)
      {

        if(i == 0)
        {
            cout <<f<< " ";
            continue;
        }
        if(i == 1)
        {
            cout << s << " ";
            continue;
        }
        n = f + s;
        f = s;
        s = n;
        R = n;
        cout<<R<<" ";
        color();
        Mid(R);
        Center();
        }

        cout << endl << endl;
        glClear(GL_COLOR_BUFFER_BIT);
        glutSwapBuffers();
        //Center(L);
       //glFlush();

}
  void myinit()
  {
       glClearColor(0.0,0.0,0.0,0.0);
       //glColor3f(0.0,0.0,0.0);
       glViewport(0,0,(GLsizei)ww,(GLsizei)wh);
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       //glPointSize(0.0);
       gluOrtho2D(-650,(GLdouble)ww,-400,(GLdouble)wh);
       glMatrixMode(GL_MODELVIEW);
  }
  int main(int argc,char** argv)
  {
       glutInit(&argc,argv);
       glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
       glutInitWindowSize(ww,wh);
       glutInitWindowPosition(20,100);
       glutCreateWindow("MidPoint-Circle Algorithm !!");
       glutDisplayFunc(display);

       cout<<" Input your limit: ";
       cin>>L;
       limit(L);
       myinit();


       glutMainLoop();
       return 0;
  }
