#include <opencv/highgui.h>///成功了
///樓上Compiler Include找到了

int main()
{///Ipl: Intel performance library
    ///IplImage * img=cvLoadImage("smile.jpg");///讀圖
    IplImage * img=cvLoadImage("smile.jpg");
    cvShowImage("week09",img);///秀圖
    cvWaitKey(0);///等待按鍵,等到你按為止
}
