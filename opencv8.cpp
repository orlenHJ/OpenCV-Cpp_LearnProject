#include<opencv2/opencv.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;


///// Face Capture /////


void main()
{
	string path = "Oldfamily.jpg";
	Mat img = imread(path);

	CascadeClassifier faceCascade;
	faceCascade.load("haarcascade_frontalface_default.xml");
	if (faceCascade.empty()) { cout << "XML file not loaded " << endl; }

	vector<Rect>faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 3);

	}

	imshow("Image", img);
	waitKey(0);


}




/*


This .cpp is the end of the OpenCVLearn



*/













