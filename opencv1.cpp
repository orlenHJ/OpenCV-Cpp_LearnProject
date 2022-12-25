#include<opencv2/opencv.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


///// images /////


//void main()
//{
//	string path = "timg.jpg";
//	Mat img = imread(path);
//	imshow("Image", img);
//	waitKey(0);
//
//
//}

////////Video/////////

//void main()
//{
//	string path = "video_exp.mp4";
//	VideoCapture cap(path);
//	Mat img;
//
//	while (1)
//	{
//		
//		cap.read(img);
//		imshow("Image", img);
//		waitKey(20);
//
//
//	}
//}

///////////// WebCam //////////////

void main()
{

	VideoCapture cap(0);
	Mat img;

	while (1)
	{

		cap.read(img);
		imshow("Image", img);
		waitKey(1);


	}
}
























