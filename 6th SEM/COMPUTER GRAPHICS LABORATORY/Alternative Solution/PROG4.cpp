#include<stdio.h>
#include<math.h>
#include<iostream.h>
#include<GL/glut.h>
using namespace std;

float pts[8][3] = {{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1},{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1}};
float theta[] ={0,0,0};
int axis = 2;
float viewer[]={5,0,0};

void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glFrustum(-2,2,-2,2,2,10);
	glMatrixMode(GL_MODELVIEW);
}

void draw_polygon(int a, int b, int c, int d)
{
	glBegin(GL_QUADS);
	glVertex3fv(pts[a]);
	glVertex3fv(pts[b]);
	glVertex3fv(pts[c]);
	glVertex3fv(pts[d]);
	glEnd();
}

void draw_cube(float pts[8][3])
{
	glColor3f(0,0,1);
	draw_polygon(0,1,2,3); //front face
	glColor3f(0,1,0);
	draw_polygon(4,5,6,7);	//behind face
	glColor3f(1,0,0);
	draw_polygon(0,1,5,4);	//left face
	glColor3f(0,0,0);
	draw_polygon(3,2,6,7);	//right face
	glColor3f(0,1,1);
	draw_polygon(0,4,7,3);	//bottom face
	glColor3f(1,0,1);
	draw_polygon(1,5,6,2);	//top face
}

void myDisplay()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,1,0);
	glRotatef(theta[2],0,0,1);
	glRotatef(theta[1],0,1,0);
	glRotatef(theta[0],1,0,0);
	draw_cube(pts);
	glFlush();
	glutSwapBuffers();
}

void spincube()
{
	theta[axis] = theta[axis]+4;
	if(theta[axis]>360)
		theta[axis]=0;
	glutPostRedisplay();
}

void mouse(int btn , int state , int x , int y)
{
	if((btn==GLUT_LEFT_BUTTON)&&(state==GLUT_DOWN))
		axis=0;
	if((btn==GLUT_RIGHT_BUTTON)&&(state==GLUT_DOWN))
		axis=2;
	if((btn==GLUT_MIDDLE_BUTTON)&&(state==GLUT_DOWN))
		axis=1;
	spincube();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key=='X') viewer[0]+=1;
	if(key=='x') viewer[0]-=1;
	if(key=='Y') viewer[1]+=1;
	if(key=='y') viewer[1]-=1;
	if(key=='Z') viewer[2]+=1;
	if(key=='z') viewer[2]-=1;
	glutPostRedisplay();
}

int main (int argc, char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode( GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
	glutCreateWindow("Positioning of Camera");
	myInit();
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
    glutMainLoop();
}
