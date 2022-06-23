
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);

        glColor3f (1.0, 0.0, 1.0);


	glBegin(GL_TRIANGLES); //Begin triangle coordinates



	//Triangle opr
	glVertex3f(0.45, 0.30f, 0.0f);
	glVertex3f(0.75f, 0.50f, 0.0f);
	glVertex3f(0.20f, 0.50f, 0.0f);


    //Triangle nich
    glColor3f (1.0, 1.0, 0.0);
	glVertex3f(0.20, 0.20f, 0.0f);
	glVertex3f(0.75f, 0.20f, 0.0f);
	glVertex3f(0.45f, 0.30f, 0.0f);

    //Triangle left
    glColor3f (1.0, 1.0, 0.0);
	glVertex3f(0.75, 0.20f, 0.0f);
	glVertex3f(0.75f, 0.50f, 0.0f);
	glVertex3f(0.45f, 0.30f, 0.0f);


    //Triangle right
    glColor3f (1.0, 1.0, 0.0);
	glVertex3f(0.20, 0.20f, 0.0f);
	glVertex3f(0.45f, 0.30f, 0.0f);
	glVertex3f(0.20f, 0.50f, 0.0f);


	glEnd();//End triangle coordinates

glFlush ();
}
void init (void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -10.0, 10.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (600, 600);
glutInitWindowPosition (100, 100);
glutCreateWindow ("hello");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}
