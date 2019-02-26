#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
GLsizei winWidth = 600, winHeight = 600;
GLfloat xwcMin = 0.0, xwcMax = 225.0;
GLfloat ywcMin = 0.0, ywcMax = 225.0;

class wcPt2D
{
	public: GLfloat x, y;
};

typedef GLfloat Matrix3x3 [3][3];
Matrix3x3 matComposite;
const GLdouble pi = 3.14159;

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
}

void matrix3x3SetIdentity (Matrix3x3 matIdent3x3)
{
	GLint row, col;
	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			matIdent3x3 [row][col] = (row == col);
}

void matrix3x3PreMultiply (Matrix3x3 m1, Matrix3x3 m2)
{
	GLint row, col;
	Matrix3x3 matTemp;
	for (row = 0; row < 3; row++)
		for (col = 0; col < 3 ; col++)
			matTemp [row][col] = m1 [row][0] * m2 [0][col] + m1 [row][1] *	m2 [1][col] + m1 [row][2] * m2 [2][col];	
	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			m2 [row][col] = matTemp [row][col];
}

void translate2D (GLfloat tx, GLfloat ty)
{
	Matrix3x3 matTransl;
	matrix3x3SetIdentity (matTransl);
	matTransl [0][2] = tx;
	matTransl [1][2] = ty;
	matrix3x3PreMultiply (matTransl, matComposite);
}

void rotate2D (wcPt2D pivotPt, GLfloat theta)
{
	Matrix3x3 matRot;
	matrix3x3SetIdentity (matRot);
	matRot [0][0] = cos (theta);
	matRot [0][1] = -sin (theta);
	matRot [0][2] = pivotPt.x * (1 - cos (theta)) +	pivotPt.y * sin (theta);
	matRot [1][0] = sin (theta);
	matRot [1][1] = cos (theta);
	matRot [1][2] = pivotPt.y * (1 - cos (theta)) -	pivotPt.x * sin (theta);
	matrix3x3PreMultiply (matRot, matComposite);
}

void scale2D (GLfloat sx, GLfloat sy, wcPt2D fixedPt)
{
	Matrix3x3 matScale;
	matrix3x3SetIdentity (matScale);
	matScale [0][0] = sx;
	matScale [0][2] = (1 - sx) * fixedPt.x;
	matScale [1][1] = sy;
	matScale [1][2] = (1 - sy) * fixedPt.y;
	matrix3x3PreMultiply (matScale, matComposite);
}

void transformVerts2D (GLint nVerts, wcPt2D * verts)
{
	GLint k;
	GLfloat temp;
	for (k = 0; k < nVerts; k++)
	{
		temp = matComposite [0][0] * verts [k].x + matComposite [0][1] * verts [k].y + matComposite [0][2];
		verts [k].y = matComposite [1][0] * verts [k].x + matComposite [1][1] *	verts [k].y + matComposite [1][2];
		verts [k].x = temp;
	}
}

void triangle (wcPt2D *verts)
{
	GLint k;
	glBegin (GL_TRIANGLES);
	for (k = 0; k < 3; k++)
		glVertex2f (verts [k].x, verts [k].y);
	glEnd ( );
}

void displayFcn (void)
{
	GLint nVerts = 3;
	wcPt2D verts [3] = { {50.0, 25.0}, {150.0, 25.0}, {100.0, 100.0} };
	wcPt2D centroidPt;
	GLint k, xSum = 0, ySum = 0;
	for (k = 0; k < nVerts; k++)
	{
		xSum += verts [k].x;
		ySum += verts [k].y;
	}
	centroidPt.x = GLfloat (xSum) / GLfloat (nVerts);
	centroidPt.y = GLfloat (ySum) / GLfloat (nVerts);
	wcPt2D pivPt,fixedPt;
	pivPt = centroidPt;
	fixedPt = centroidPt;
	GLfloat tx = 0.0, ty = 100.0;
	GLfloat sx = 0.5, sy = 0.5;
	GLdouble theta = pi/2.0;
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 1.0);
	triangle (verts);
	matrix3x3SetIdentity (matComposite);
	scale2D (sx, sy, fixedPt);
	rotate2D (pivPt, theta);
	translate2D (tx, ty);
	transformVerts2D (nVerts, verts);
	glColor3f (1.0, 0.0, 0.0);
	triangle (verts);
	glFlush ( );
}

void winReshapeFcn (GLint newWidth, GLint newHeight)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ( );
	gluOrtho2D (xwcMin, xwcMax, ywcMin, ywcMax);
	glClear (GL_COLOR_BUFFER_BIT);
}

int main (int argc, char ** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (50, 50);
	glutInitWindowSize (winWidth, winHeight);
	glutCreateWindow ("Geometric Transformation Sequence");
	init ( );
	glutDisplayFunc (displayFcn);
	glutReshapeFunc (winReshapeFcn);
	glutMainLoop ( );
	return 0;
}