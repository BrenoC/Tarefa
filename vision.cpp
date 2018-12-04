#include "vision.h"

vision::vision()
{
    low_H = 0;
    low_S = 0;
    low_V = 0;
    high_H = 180;
    high_S = 255;
    high_V = 255;

}

void vision::setLowH(int n){
    low_H = n;
}

void vision::setLowS(int n){
    low_S = n;
}

void vision::setLowV(int n){
    low_V = n;
}

void vision::setHighH(int n){
    high_H = n;
}

void vision::setHighS(int n){
    high_S = n;
}

void vision::setHighV(int n){
    high_V = n;
}

void vision::openCamera(){
    Cap.open(0);
    if( Cap.isOpened() )
        cout << "Camera opened succefully" << endl;

    else
        cout << "Unable to open the camera" << endl;
}

void vision::updateFrame(){
        if( Cap.isOpened() )
            Cap.read(src);
        else
            cout << "Unable to get the frame" << endl;
}
void vision::contours(){
    Mat canny_output;
    Canny( hsv, canny_output, 100, 100*2 );
    vector<vector<Point> > contours;
    findContours( canny_output, contours, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
    vector<RotatedRect> minRect( contours.size() );
    vector<RotatedRect> minEllipse( contours.size() );
    for( size_t i = 0; i < contours.size(); i++ )
    {
        minRect[i] = minAreaRect( contours[i] );
        if( contours[i].size() > 5 )
        {
            minEllipse[i] = fitEllipse( contours[i] );
        }
    }
    drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
    for( size_t i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( 0,255,0 );
        // contour
        drawContours( drawing, contours, (int)i, color , 5 );
        // ellipse
        ellipse( drawing, minEllipse[i], color, 5 );
        // rotated rectangle
        Point2f rect_points[4];
        minRect[i].points( rect_points );
        for ( int j = 0; j < 4; j++ )
        {
            line( drawing, rect_points[j], rect_points[(j+1)%4], color, 5 );
        }
    }

}


void vision::treatment(){
    cvtColor(src, hsv, COLOR_BGR2HSV);
    inRange(hsv, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), hsv);
    GaussianBlur(hsv, hsv, Size(9,9), 1.5);
    contours();
    cvtColor(hsv,hsv, COLOR_GRAY2RGB);
    bitwise_or(hsv,drawing,hsv);
    cvtColor(src, src, COLOR_BGR2RGB);
    bitwise_and(src, hsv, dst);
}


Mat vision::getDst(){
    return dst;
}


Mat vision::getSrc(){
    return src;
}

Mat vision::getDrawing(){
    return drawing;
}

