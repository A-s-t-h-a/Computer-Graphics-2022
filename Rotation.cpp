// Keyboard callbacks to rotate a robot arm

// Hierarchical modeling

// parent object and a child object

// "special" callback in GLUT



#include <glut.h>



static int shoulderangle = 0, elbowangle = 0;



void special(int key, int, int)

{

	switch (key)

	{

	case GLUT_KEY_LEFT: (elbowangle += 5) %= 360; break;



	case GLUT_KEY_RIGHT: (elbowangle -= 5) %= 360; break;



	case GLUT_KEY_UP: (shoulderangle += 5) %= 360; break;



	case GLUT_KEY_DOWN: (shoulderangle -= 5) %= 360; break;



	default: return;

	}



	glutPostRedisplay();

}



// Draw the arms

// wirebox(w,h,d)



void wirebox(GLdouble width, GLdouble height, GLdouble depth)

{

	glPushMatrix();



	glScalef(width, height, depth);



	glutWireCube(1.0);



	glPopMatrix();



}



// Displaying the arm in current possition and orientation



void display()

{



	glClear(GL_COLOR_BUFFER_BIT);



	glMatrixMode(GL_MODELVIEW);



	glPushMatrix();



	glRotatef((GLfloat)shoulderangle, 0.0, 0.0, 1.0);



	glTranslatef(1.0, 0.0, 0.0);



	wirebox(2.0, 1.0, 1.0);



	glTranslatef(1.0, 0.0, 0.0);



	glRotatef((GLfloat)elbowangle, 0.0, 0.0, 1.0);



	glTranslatef(1.0, 0.0, 0.0);



	wirebox(2.0, 1.0, 1.0);



	glPopMatrix();



	glFlush();



}



void reshape(GLint w, GLint h)

{



	glViewport(0, 0, w, h);



	glMatrixMode(GL_PROJECTION);



	glLoadIdentity();



	gluPerspective(65.0, GLfloat(w) / GLfloat(h), 1.0, 20.0);



}



void init()

{



	glShadeModel(GL_FLAT);



	glMatrixMode(GL_MODELVIEW);



	glLoadIdentity();



	gluLookAt(1, 2, 8, 0, 0, 0, 0, 1, 0);



}



int main(int argc, char** argv)

{



	glutInit(&argc, argv);



	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);



	glutInitWindowPosition(80, 80);



	glutInitWindowSize(800, 800);



	glutCreateWindow("CG LAB: Movement of Robotic arm using Keys");



	glutDisplayFunc(display);



	glutReshapeFunc(reshape);



	glutSpecialFunc(special);



	init();



	glutMainLoop();



}