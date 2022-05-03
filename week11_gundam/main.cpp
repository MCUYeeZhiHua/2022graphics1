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
