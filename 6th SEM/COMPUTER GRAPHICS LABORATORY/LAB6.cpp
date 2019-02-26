#include<GL/glut.h>
void wall(double thickness)
{
	glPushMatrix();
	glTranslated(0.5,0.5*thickness, 0.5);
	glScaled(1.0,thickness, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();
}

void tableleg(double thick, double len)
{
	glPushMatrix();
	glTranslated(0,len/2,0);
	glScaled(thick, len, thick);
	glutSolidCube(1.0);
	glPopMatrix();
}

void table(double topwid, double topthick, double legthick, double leglen)
{
	glPushMatrix();
	glTranslated(0,leglen,0);
	glScaled(topwid, topthick, topwid);
	glutSolidCube(1.0);
	glPopMatrix();
	double dist=0.95*topwid/2.0-legthick/2.0;
	glPushMatrix();
	glTranslated(dist, 0, dist);
	tableleg(legthick, leglen);
	glTranslated(0.0,0.0,-2*dist);
	tableleg(legthick, leglen);
	glTranslated(-2*dist, 0, 2*dist);
	tableleg(legthick, leglen);
	glTranslated(0,0,-2*dist);
	tableleg(legthick,leglen);
	glPopMatrix();
}

void displaySolid(void)
{
	GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat mat_diffuse[]={0.5f,0.5f,0.5f,1.0f};
	GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={50.0f};
	glMaterialfv(GL_FRONT,GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS, mat_shininess);

	GLfloat lightintensity[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat lightposition[]={2.0f,6.0f,3.0f,0.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, lightposition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightintensity);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double winht=1.0;
	glOrtho(-winht*64/48, winht*64/48, -winht, winht,  
                                          0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.3,1.3,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	  glTranslated(0.6,0.38,0.5);
	  glRotated(30,0,1,0);
	  glutSolidTeapot(0.08);
	glPopMatrix();
	glPushMatrix();
	  glTranslated(0.4,0,0.4);
	  table(0.6,0.02,0.02,0.3);
	glPopMatrix();
	wall(0.02);
	glPushMatrix();
	  glRotated(90.0,0.0,0.0,1.0);
	  wall(0.02);
	glPopMatrix();
	glPushMatrix();
	  glRotated(-90.0,1.0,0.0,0.0);
	  wall(0.02);
	glPopMatrix();
	glFlush();
}


void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(400,300);
	glutCreateWindow("Shaded Scene");
	glutDisplayFunc(displaySolid);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClearColor(0.1,0.1,0.1,0.0);
	glViewport(0,0,640,480);
	glutMainLoop();
}