#include<opencv2/opencv.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;



/////  Warp Images  /////

float w = 250, h = 350;
Mat matrix, imgWarp;


void main()
{
	string path = "pok.jpg";
	Mat img = imread(path);
	//709,199 \ 912,628   1038,266 /546,536

	Point2f src[4] = { {709,199},{1038,266},{546,536},{912,628} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };



	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));
	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	waitKey(0);


}
