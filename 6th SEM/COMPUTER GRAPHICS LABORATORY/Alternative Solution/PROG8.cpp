#include <bits/stdc++.h>
#include <GL/glut.h>
#include <unistd.h>
using namespace std;
int stp = 10;
double X0, Y0, X1, Y1, X2, Y2, itr = 0, incVal = 0.2;

pair <double, double> findPoint(double _X1, double _Y1, double _X2, double _Y2, int dLen)
{
	double m = (_Y2 - _Y1) / (_X2 - _X1);
	double c = _Y1 - m * _X1;
	double seg = abs(_X2 - _X1) / stp;
	double xres = min(_X1, _X2) + seg * dLen;
	double yres = m * xres + c;
	return { xres, yres };
}

void solve()
{
	pair<double, double> pcur, pprev;
	vector< pair<double, double> > pts1(11), pts2(11);
	for (int i = 0; i <= stp; i++)
    {
		pts1[i] = findPoint(X0, Y0, X1, Y1, i);
		pts2[i] = findPoint(X1, Y1, X2, Y2, i);
	}
	for (int i = 0; i <= stp; i++)
	{
		pcur = findPoint(pts1[i].first, pts1[i].second, pts2[i].first, pts2[i].second, i);
		if (i != 0)
		{
			for (int thick = 0; thick < 200; thick++)
			{
				if(thick <67)
                    glColor3f(1, 0.5, 0);	// orange
				else if(thick < 133)
                    glColor3f(1, 1, 1);	// white
				else
                    glColor3f(0, 1, 0);	// green
				glBegin(GL_LINES);
				glVertex2d(pprev.first, pprev.second - thick);
				glVertex2d(pcur.first, pcur.second - thick);
				glEnd();
			}glFlush();
		}pprev = pcur;
	}
}

void drawStick()
{
	glColor3f(0.8, 0.4, 0.2);
	glBegin(GL_POLYGON);
	glVertex2i(150, 345);
	glVertex2i(160, 345);
	glVertex2i(160, 60);
	glVertex2i(150, 60);
	glEnd();
	glFlush();
}

void work()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	drawStick();
	X0 = 160, Y0 = 340, X1 = 210 + (itr * 3.0) / 4, Y1 = 390 - (itr * 2), X2 = 260 + (itr * 3.0) / 2, Y2 = 340;
	solve();
	X0 = 260 + (itr*3.0) / 2, Y0 = 340, X1 = 310 + 3 * (itr*3.0) / 4, Y1 = 290 + (itr * 2), X2 = 360 + (itr * 3), Y2 = 340;
	solve();
	usleep(20000);
	itr += incVal;
	if (itr > 15)
		incVal = -0.1;
	else if (itr < 0)
		incVal = 0.1;
	glutSwapBuffers();
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Bezier Curve");
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
	glutDisplayFunc(work);
	glutMainLoop();
}
