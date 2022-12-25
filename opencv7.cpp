#include<opencv2/opencv.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;


///// Shape Detection /////

void getContours(Mat imgDil,Mat img_drawOn) {

	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;


	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img_drawOn, contours, -1, Scalar(255, 0, 255), 2);
	vector<vector<Point>>conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	string objectType;

	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		cout << area << endl;
		
		if (area > 1000) {

			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
			//rectangle(img_drawOn, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);

			int objCor = (int)conPoly[i].size();
			if (objCor == 3) { objectType = "Triangle"; }
			else if (objCor == 4) {

				float asqRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				
				if (asqRatio > 0.95 && asqRatio < 1.05) { objectType = "Square"; }
				else { objectType = "Rect"; }
			
			}
			else if (objCor > 4) { objectType = "Circle"; }

			drawContours(img_drawOn, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img_drawOn, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 3);
			putText(img_drawOn, objectType, { boundRect[i].x ,boundRect[i].y - 5}, FONT_HERSHEY_DUPLEX, 0.7, Scalar(0, 69, 255), 1);

		}
	}
}



Mat img,imgGray, imgBlur, imgCanny, imgDil, imgErode;
void main()
{
	string path = "shapeNew.png";
	Mat imgOrigin = imread(path);

	// Preprocessing
	resize(imgOrigin,img, Size(), 0.5, 0.5);

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);	//¸ßË¹Ä£ºý
	Canny(imgBlur, imgCanny, 25, 75);				//±ßÔµ¼ì²âÆ÷

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil,img);

	imshow("Image", img);
	/*imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dil", imgDil);*/

	waitKey(0);


}















