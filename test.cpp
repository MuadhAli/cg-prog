#include <GL/glut.h>
void display()
{
    double x0 = 60, y0 = 20, x1 = 80, y1 = 120;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2d(x0, y0);
    glVertex2d(x1, y1);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glEnd();
    glFlush();
}

void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Cohen Suderland Line Clipping Algorithm");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

