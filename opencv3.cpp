#include<opencv2/opencv.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;



///// images Resize Crop  /////


void main()
{
	string path = "timg.jpg";
	Mat img = imread(path);
	Mat imgResize,imgCrop;
	
	cout << img.size() << endl;  //[1068 x 1156]
	//resize(img, imgResize, Size(640,480));
	resize(img, imgResize, Size(),0.5,0.5);

	Rect roi(200, 100, 500, 500);
	imgCrop = img(roi);


	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);

	waitKey(0);


}












