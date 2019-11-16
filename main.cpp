#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
int main(){
    Mat img=imread("70970995_p0.png");
    namedWindow("1",0);
    imshow("1",img);
    printf("ImageSize: %dx%d\n",img.rows,img.cols);
    waitKey();
    return 0;
}