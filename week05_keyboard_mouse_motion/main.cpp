#include <GL/glut.h>
#include <stdio.h>
float x=150, y=150, z=0,scale=1.0;
int oldX=0, oldY=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1);///R,G,B,A �䤤A���b�z���\��
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glPushMatrix();///�ƥ��x�}
            glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
            glScalef(scale,scale,scale);
            glColor3f(1,1,0);///����
            glutSolidTeapot(0.3);///����
        glPopMatrix();///�٭�x�}
        glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{

}
void mouse(int button,int state,int mouseX,int mouseY)
{
    ///���F�ѨM�������ʪ����~�A��Υ��T����k
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    if(mouseX-oldX > 0) scale *= 1.01;
    if(mouseX-oldX < 0) scale *= 0.99;
    oldX=mouseX;      oldY=mouseY;
    display();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("��05�g���{���@!");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
