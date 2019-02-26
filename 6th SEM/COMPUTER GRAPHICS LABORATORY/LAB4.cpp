#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

GLfloat vertices[ ]={  -1.0,-1.0,-1.0,
						1.0,-1.0,-1.0,
						1.0, 1.0,-1.0,
					   -1.0, 1.0,-1.0,
                       -1.0,-1.0, 1.0,
                        1.0,-1.0, 1.0,
                        1.0, 1.0, 1.0,
                       -1.0, 1.0, 1.0 };

GLfloat normals[ ] ={  -1.0,-1.0,-1.0,
						1.0,-1.0,-1.0,
						1.0, 1.0,-1.0,
					   -1.0, 1.0,-1.0,
					   -1.0,-1.0, 1.0,
						1.0,-1.0, 1.0,
						1.0, 1.0, 1.0,
					   -1.0, 1.0, 1.0 };

GLfloat colors[ ]={ 0.0, 0.0, 0.0,
					1.0, 0.0, 0.0,
					1.0, 1.0, 0.0,
					0.0, 1.0, 0.0,
					0.0, 0.0, 1.0,
					1.0, 0.0, 1.0,
					1.0, 1.0, 1.0,
					0.0, 1.0, 1.0};

GLubyte cubeIndices[]={ 0,3,2,1,
						2,3,7,6,
						0,4,7,3,
						1,2,6,5,
						4,5,6,7,
						0,1,5,4};

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;
static GLdouble viewer[] = {0.0,0.0,5.0};

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2],0.0,0.0,0.0,0.0,1.0,0.0);
	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);
	glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,cubeIndices);
	glFlush();
	glutSwapBuffers();
}

void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		axis=0;
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
		axis=1;
	if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
		axis=2;
	theta[axis]+=2.0;
	
	if(theta[axis]>360.0)
		theta[axis]-=360.0;
	glutPostRedisplay();
}

void keys(unsigned char key, int x, int y)
{
	if(key=='x') viewer[0]-=1.0;
	if(key=='X') viewer[0]+=1.0;
	if(key=='y') viewer[1]-=1.0;
	if(key=='Y') viewer[1]+=1.0;
	if(key=='z') viewer[2]-=1.0;
	if(key=='Z') viewer[2]+=1.0;
	glutPostRedisplay();
}

void myReshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glFrustum(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,2.0,20.0);
	else
		glFrustum(-2.0,2.0,-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,2.0,20.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("color cuce");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keys);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glVertexPointer(3,GL_FLOAT,0,vertices);
	glColorPointer(3,GL_FLOAT,0,colors);
	glNormalPointer(GL_FLOAT,0,normals);
	glColor3f(1.0,1.0,1.0);
	glutMainLoop();
}