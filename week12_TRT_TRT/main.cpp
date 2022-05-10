#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot(0.3);///茶壺當身體

     glPushMatrix();///右邊的手臂手肘
        glTranslatef(0.2,0,0);///(3)掛到右邊(整個往動)
        glRotatef(angle, 0,0,1);///(2)旋轉
        glTranslatef(0.2,0,0);
        glColor3f(1,0,0);
        glutSolidTeapot(0.2);///小茶壺，當作小手臂
        glPushMatrix();
            glTranslatef(0.2,0,0);///(3)掛到右邊(整個往動)
            glRotatef(angle, 0,0,1);///(2)旋轉
            glTranslatef(0.2,0,0);
            glColor3f(1,0,0);
            glutSolidTeapot(0.2);///小茶壺，當作小手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左邊的手臂手肘
        glTranslatef(-0.2,0,0);///(3)掛到左邊(整個往動)
        glRotatef(-angle, 0,0,1);///(2)旋轉
        glTranslatef(-0.2,0,0);
        glColor3f(1,0,0);
        glutSolidTeapot(0.2);///小茶壺，當作小手臂
        glPushMatrix();
            glTranslatef(-0.2,0,0);///(3)掛到左邊(整個往動)
            glRotatef(-angle, 0,0,1);///(2)旋轉
            glTranslatef(-0.2,0,0);
            glColor3f(1,0,0);
            glutSolidTeapot(0.2);///小茶壺，當作小手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.01; ///每次執行 display() 加1度
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12_TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
