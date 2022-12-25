#include<opencv2/opencv.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;



///// images Basic Functions  /////


void main()
{
	string path = "timg.jpg";
	Mat img = imread(path);
	Mat imgGary,imgBlur, imgCanny, imgDil, imgErode;

	cvtColor(img, imgGary, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur,Size(3,3),3,0);	//¸ßË¹Ä£ºý
	Canny(imgBlur, imgCanny, 25, 75);			//±ßÔµ¼ì²âÆ÷

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3)); 
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);


	imshow("Image", img);
	imshow("Image Gary", imgGary);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dialation", imgDil);
	imshow("Image Erode", imgErode);
	waitKey(0);


}
























