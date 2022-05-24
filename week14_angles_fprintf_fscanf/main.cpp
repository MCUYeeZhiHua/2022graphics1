#include <GL/glut.h>
#include <stdio.h>
float angle[20], oldX=0;
int angleID=0;///���`ID
FILE * fout = NULL, * fin = NULL;
void myWrite(){
    if(fout==NULL) fout = fopen("file.txt","w+");
    for(int i=0;i<20;i++){
        printf("%.1f ",angle[i]);///�p�¦L�X��
        fprintf(fout,"%.1f ",angle[i]);///�ɮצL�X��
    }///�L�X20�ӼƦr
    printf("\n");///�C�I�s�@���A�p�¸���
    fprintf(fout,"\n");///�C�I�s�@���A�ɮפ]����
}
void myRead(){
    if(fout!=NULL){fclose(fout);fout=NULL;}
    if(fin==NULL) fin=fopen("file.txt","r");
    for(int i=0;i<20;i++){
        fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay();///���e�e��
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='r') myRead();
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}///���ާ@���`
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldX);
    myWrite();
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///��
    glRectf(0.3,0.5, -0.3,-0.5);///����
    glPushMatrix();
        glTranslatef(0.3,0.4,0);
        glRotatef(angle[0],0,0,1);
        glTranslatef(-0.3,-0.4,0);
        glColor3f(1,0,0);///��
        glRectf(0.3,0.5, 0.7,0.3);///�k�W���u
        glPushMatrix();
            glTranslatef(0.7,0.4,0);
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.7,-0.4,0);
            glColor3f(0,1,0);///��
            glRectf(0.7,0.5, 1.0,0.3);///�k�U��y
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.3,0.4,0);
        glRotatef(angle[2],0,0,1);
        glTranslatef(0.3,-0.4,0);
        glColor3f(1,0,0);///��
        glRectf(-0.3,0.5, -0.7,0.3);///���W���u
        glPushMatrix();
            glTranslatef(-0.7,0.4,0);
            glRotatef(angle[3],0,0,1);
            glTranslatef(0.7,-0.4,0);
            glColor3f(0,1,0);///��
            glRectf(-0.7,0.5, -1.0,0.3);///���U��y
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13 rect TRT TRT");
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}