#include <opencv/highgui.h>///���\�F
///�ӤWCompiler Include���F

int main()
{///Ipl: Intel performance library
    ///IplImage * img=cvLoadImage("smile.jpg");///Ū��
    IplImage * img=cvLoadImage("smile.jpg");
    cvShowImage("week09",img);///�q��
    cvWaitKey(0);///���ݫ���,����A������
}
