#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
float x=150, y=150, z=0,scale=1.0,angle=0.0;
int oldX=0, oldY=0,now=1;
void display()
{
    glClearColor(0.5,0.5,0.5,1);///R,G,B,A 其中A為半透明功能
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
    glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
    glRotatef(angle,0,1,0);
    glScalef(scale,scale,scale);
    glColor3f(1,1,0);///黃色
    glutSolidTeapot(0.3);///茶壺
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
    if(key=='1'||key=='w'||key=='W') now=1;///移動
    if(key=='2'||key=='e'||key=='E') now=2;///轉動
    if(key=='3'||key=='r'||key=='R') now=3;///縮放
}
void mouse(int button,int state,int mouseX,int mouseY)
{
        ///為了解決瞬間移動的錯誤，改用正確的方法
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    if(now==1){///移動
        x += (mouseX-oldX); y+=(mouseY-oldY);
    }
    else if(now==2){///旋轉
        angle += (mouseX-oldX);
    }
    else if(now==3){///縮放
        if(mouseX-oldX > 0) scale *= 1.01;
        if(mouseX-oldX < 0) scale *= 0.99;
    }
    oldX=mouseX;      oldY=mouseY;
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 light");

    glutDisplayFunc(display);
    ///偷來的程式要放glutCreateWindow()之後才會有效
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
