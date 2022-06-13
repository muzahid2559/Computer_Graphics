#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>


double points[45][45][3], r = 1.85, s = 0.00681817;
double pi = acos(-1);

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glDepthFunc(GL_LEQUAL);

    for (int x=0; x<45; x++) {
        for (int y=0; y<45; y++) {
			points[x][y][0] = double((x / 3.0f) - 7.25f);
			points[x][y][1] = double((y / 5.0f) - 4.5f);
			points[x][y][2] = double(sin((((x / 5.0f) * 40.0f) / 360.0f) * pi * 2.0f));
		}
	}
}

void rectangle(void)
{
    int x, y;
	double double_x, double_y, double_xb, double_yb;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.0f, 0.0f, -12.0f);

	glBegin(GL_QUADS);
//square
	glColor3f(0.0, 0.8, 0.3);
	glVertex3f(-5.9f, -3.0f, 0.0f);
	glVertex3f(5.0f, -3.0f, 0.0f);
	glVertex3f(5.0f, 4.0f, 0.0f);
    glVertex3f(-5.9f, 4.0f, 0.0f);

	glEnd();
//root
	glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
        glVertex3f(-6.2, 4.5, -1.0);
        glVertex3f(-6.2, -8.0, -1.0);
        glVertex3f(-6.6, -8.0, -1.0);
        glVertex3f(-6.6, 4.5, -1.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5.0, -7.0, -1.0);
        glVertex3f(-5.0, -8.0, -1.0);
        glVertex3f(-8.0, -8.0, -1.0);
        glVertex3f(-8.0, -7.0, -1.0);
    glEnd();
//circle
    glColor3f(0.96, 0.16, 0.26);

	glBegin(GL_POLYGON);
        for (int i=0; i<100; i++) {
            double theta = (2 * pi * i) / 100;
            glVertex3f(r * cos(theta), r * sin(theta), 1.0);
        }
	glEnd();


}

void display(void)
{
	rectangle();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(900, 800);
    glutInitWindowPosition(283, 100);
    glutCreateWindow("Waving Flag of Bangladesh");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
