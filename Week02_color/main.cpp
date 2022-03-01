///先全刪
#include <GL/glut.h>///使用GLUT外掛,簡化程式
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///畫圖前，先清畫面
    glColor3d(1,1,0);///設定色彩
    ///glutSolidTeapot(0.3);///實心茶壺
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);///紅色
        glVertex2f(-1, -1);

        glColor3f(0,1,0);///綠色
        glVertex2f(+1, -1);

        glColor3f(0,0,1);///藍色
        glVertex2f(0, +1);
    glEnd();
    glutSwapBuffers();///畫好後,交換出來
}

int main(int argc, char** argv)///main()主函式 進階版
{
    glutInit( &argc, argv );///把參數送給glutInit初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///雙緩衝區+3D深度功能
    glutCreateWindow("第02週的程式哦!");///開GLUT視窗
    glutDisplayFunc(display);///用來顯示的函式
    glutMainLoop();///主要程式的迴圈
}
