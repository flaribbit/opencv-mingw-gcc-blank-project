#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
int main(){
    Mat img=imread("70970995_p0.png");
    Mat imgSmall,imgGray;
    cvtColor(img,imgGray,COLOR_BGR2GRAY);
    int height=320;
    int width=img.cols*height/img.rows;
    resize(imgGray,imgSmall,Size(width,height),0,0,INTER_AREA);
    imshow("1",imgSmall);
    int div=3;
    for(int i=0;i<imgSmall.rows-1;i++){
        for(int j=1;j<imgSmall.cols-1;j++){
            uchar oldPixel=imgSmall.at<uchar>(i,j);
            uchar newPixel=(oldPixel*div+127)/255*255/div;
            int quantError=oldPixel-newPixel;
            imgSmall.at<uchar>(i,j)=newPixel;
            imgSmall.at<uchar>(i  ,j+1)=MIN(imgSmall.at<uchar>(i  ,j+1)+quantError*7/16,255);
            imgSmall.at<uchar>(i+1,j-1)=MIN(imgSmall.at<uchar>(i+1,j-1)+quantError*3/16,255);
            imgSmall.at<uchar>(i+1,j  )=MIN(imgSmall.at<uchar>(i+1,j  )+quantError*5/16,255);
            imgSmall.at<uchar>(i+1,j+1)=MIN(imgSmall.at<uchar>(i+1,j+1)+quantError*1/16,255);
        }
    }
    imshow("2",imgSmall);
    waitKey();
    img.release();
    imgGray.release();
    return 0;
}