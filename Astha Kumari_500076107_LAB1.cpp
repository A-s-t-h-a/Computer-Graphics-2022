#include<Windows.h>   
#include<stdio.h>   
#include<glut.h>
#include<conio.h>   
#include<stdio.h>   
#include<math.h>   
#include<string.h>   

void Init_OpenGL()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}


void Display_Objects(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glColor3f(1.0, 0.8, 0.0);

	// draw a wire cube   
	glTranslatef(-2.0, 1.4, 0.0);
	glColor3f(1.0, 0.3, 0.0);
	glutWireCube(1.5);

	glPopMatrix();
	glutSwapBuffers();
}
void Reshape(int w, int h)
{

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-0.3, 0.5, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(700, 500);
	glutInitWindowPosition(250, 50);
	glutCreateWindow("Computer Graphics - Wired Cube");
	Init_OpenGL();
	glutDisplayFunc(Display_Objects);
	glutReshapeFunc(Reshape);
	glutMainLoop();
	return 0;
}