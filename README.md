# 2022graphics1
## week02-1 親手打造 GLUT 的程式
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
