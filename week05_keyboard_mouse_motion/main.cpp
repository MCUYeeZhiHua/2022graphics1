#include <GL/glut.h>
#include <stdio.h>
float x=150, y=150, z=0,scale=1.0;
int oldX=0, oldY=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1);///R,G,B,A 其中A為半透明功能
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glPushMatrix();///備份矩陣
            glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
            glScalef(scale,scale,scale);
            glColor3f(1,1,0);///黃色
            glutSolidTeapot(0.3);///茶壺
        glPopMatrix();///還原矩陣
        glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{

}
void mouse(int button,int state,int mouseX,int mouseY)
{
    ///為了解決瞬間移動的錯誤，改用正確的方法
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
    glutCreateWindow("第05週的程式哦!");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
