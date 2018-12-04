#ifndef VISION_H
#define VISION_H
#include <iostream>
#include "opencv2/core.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;


class vision
{
private:
    VideoCapture Cap;
    Mat src;
    Mat hsv;
    Mat dst;
    int low_H, low_S, low_V, high_H, high_S, high_V;
    vector<Vec3f> circles;
    vector<Vec3f>::iterator itrCircles;
public:
    vision();
    void setLowH(int n);
    void setLowS(int n);
    void setLowV(int n);
    void setHighH(int n);
    void setHighS(int n);
    void setHighV(int n);
    void openCamera();
    void updateFrame();
    Mat getDst();
    Mat getSrc();
    void treatment();
    void contours();
    Mat drawing;
    Mat getDrawing();
    
};

#endif // VISION_H
