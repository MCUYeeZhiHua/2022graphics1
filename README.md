# 2022graphics1
## week02-2 親手打造 GLUT 的程式
用程式碼打造出一個茶壺！新增一個GLUT檔案，檔名：week02_color，將 main.cpp 內的程式碼刪除並加入以下程式

```C++
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("第02週的程式哦!");
    glutDisplayFunc(display);
    glutMainLoop();
}
```

## week02-3 彩色三角形

```C++
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    ///glutSolidTeapot(0.3);
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2f(-1, -1);

        glColor3f(0,1,0);
        glVertex2f(+1, -1);

        glColor3f(0,0,1);
        glVertex2f(0, +1);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("第02週的程式哦!");
    glutDisplayFunc(display);
    glutMainLoop();
}
```


## week05 
keyboard
```C++
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
    printf("你按下了 %c 在 %d 座標\n",key,x,y);
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("第05週的程式哦!");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard)
    glutMainLoop();
}
```
keyboard+mouse+motion
```C++
#include <GL/glut.h>
#include <stdio.h>
float x=0, y=0, z=0;
int oldX=0, oldY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
    glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glColor3f(1,1,0);///黃色
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard(unsigned char key, int mouseX, int mouseY)
{

}
void mouse(int button,int state,int mouseX,int mouseY)
{
            
}
void motion(int mouseX,int mouseY)
{
    x+=(mouseX-oldX); y+=(mouseY-oldY);
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
```
scale放大縮小功能
```C++
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

```

## week06_light
```C++
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glutSwapBuffers();
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
    ///放在glutMainLoop()之前
    glutMainLoop();///卡在這裡，之後的程式都不會執行到

}

```

## week06_light_mouse_motion_rotate
```C++
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
```
## week08_model
```C++
#include <GL/glut.h>///角括號，是系統的 include 裡的檔案
#include "glm.h" ///雙引號，同目錄裡的檔案
GLMmodel* pmodel = NULL; ///指到GLModel模型的指標
void
drawmodel(void)
{
    if(!pmodel){
        pmodel = glmReadOBJ("data/dolphins.obj"); ///date裡的模型都能用
        if(!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel,90.0);
    }
    glmDraw(pmodel,GLM_SMOOTH);
}///用來畫3D模型
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    ///glutSolidTeapot(0.3);
    drawmodel();///學習來的話模型
    glutSwapBuffers();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week08 model");
    glutDisplayFunc(display);

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

    glutMainLoop();
}
```

## week09_opencv.cpp
```C++
#include <opencv/highgui.h>///成功了
///樓上Compiler Include找到了

int main()
{///Ipl: Intel performance library
    ///IplImage * img=cvLoadImage("smile.jpg");///讀圖
    IplImage * img=cvLoadImage("smile.jpg");
    cvShowImage("week09",img);///秀圖
    cvWaitKey(0);///等待按鍵,等到你按為止
}

```

## week09_texture
```C++
#include <GL/glut.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);
     glutSolidTeapot(0.3);
     glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");

    glutDisplayFunc(display);
    myTexture("earth.jpg");
    glutMainLoop();
}

```

## week10_texture_background
```C++
#include <GL/glut.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);
    ///glutSolidTeapot(0.3);
    glBegin(GL_POLYGON);
        glTexCoord2f(0,1); glVertex2f(-1,-1);
        glTexCoord2f(1,1); glVertex2f(+1,-1);
        glTexCoord2f(1,0); glVertex2f(+1,+1);
        glTexCoord2f(0,0); glVertex2f(-1,+1);
    glEnd();
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glutDisplayFunc(display);
    myTexture("earth.jpg");

    glutMainLoop();
}

```

## week10_texture_earth
```C++
#include <GL/glut.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
GLUquadric * sphere = NULL; ///指標，指到二次曲面
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        gluQuadricTexture(sphere, 1); ///設好貼圖
        gluSphere(sphere, 1, 30, 30); ///畫圓球
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.05; ///每次執行 display() 加1度
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture earth");

    glEnable(GL_DEPTH_TEST); ///開3D深度測試，才會有3D效果
    glutIdleFunc(display); ///有空 idle 呼叫 display()
    glutDisplayFunc(display);
    myTexture("earth.jpg");
    sphere = gluNewQuadric(); ///準備好二次曲面
    glutMainLoop();
}

```

## week10_texture_model
```C++
#include <GL/glut.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
///GLUquadric * sphere = NULL; ///指標，指到二次曲面
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glPushMatrix();
        glRotatef(angle, 0,1,0);
        if(pmodel==NULL){ ///使用3D模型
            pmodel = glmReadOBJ( "data/Gundam.obj" ); ///使用3D模型
            glmUnitize(pmodel);///使用3D模型,縮放到 -1...+1間,才看得到
            glmFacetNormals(pmodel);///使用3D模型,面的法向量
            glmVertexNormals(pmodel, 90);///使用3D模型, 頂點的法向量
        }
        glmDraw(pmodel,GLM_TEXTURE);
    glPopMatrix();
    glutSwapBuffers();
    angle+=1; ///每次執行 display() 加1度
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");

    glEnable(GL_DEPTH_TEST); ///開3D深度測試，才會有3D效果
    glutIdleFunc(display); ///有空 idle 呼叫 display()
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");
    ///sphere = gluNewQuadric(); ///準備好二次曲面
    glutMainLoop();
}

```

## week11_gundam
```C++
#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include "glm.h"
GLMmodel * pmodel=NULL;
///GLUquadric * sphere = NULL;///指標,指到2次曲面
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;///旋轉角度
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,1,0);
        if(pmodel==NULL)///如果是空指標 表示模型還沒準備好
        {
            pmodel=glmReadOBJ("data/Gundam.obj");///讀模型
            glmUnitize(pmodel);///換算成unit單位大小
            glmFacetNormals(pmodel);///重新計算模型的面的法向量
            glmVertexNormals(pmodel,90);///重新計算模型頂點的法向量
        }
        glmDraw(pmodel,GLM_TEXTURE);///有模型後畫面要記得畫貼圖
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.01;
 }
 int main(int argc, char *argv[])///main()主函式 進階版
 {
    glutInit(&argc,argv);///把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///雙緩衝區+3D深度功能
    glutCreateWindow("week11_gundam");///開GLUT視窗

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);///顯示用的函式
    glutIdleFunc(display);
    myTexture("data/Diffuse.jpg");
    ///myTexture("earth.jpg");
    ///sphere=gluNewQuadric();///準備好2次曲面
    glutMainLoop();
 }

```

## week11_TRT
```C++
#include <GL/glut.h>
void hand()
{
    glColor3f(0,1,0);
    glutSolidTeapot(0.2);
}
void body()
{
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
}
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    body();
    glPushMatrix();
        glTranslated(0.5,0.2,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.3,0,0);
        hand();
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.1;
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week11 TRT");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}

```

## week12_TRT
```C++
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glutSolidTeapot(0.3);///茶壺當身體
     glPushMatrix();
        glTranslatef(0.2,0,0);///(3)掛右邊(把整個往右移動)
        glRotatef(angle, 0,0,1);///(2)旋轉
        glTranslatef(0.2,0,0);///(1)把旋轉中心，放到世界中心
        glColor3f(1,0,0);///紅色
        glutSolidTeapot(0.2);///小茶壺，想像是手臂
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.01; ///每次執行 display() 加1度
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12 TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}

```
## week12_TRT_TRT
```C++
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

```
