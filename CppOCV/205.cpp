#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void brightness4()
{
	Mat src=imread("lenna.bmp",IMREAD_GRAYSCALE);
	
	if (src.empty())
	{
		cerr << "image load failed!" << endl;
		return;
	}

	namedWindow("dst");
	createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&src);
	on_brightness(0, (void*)&src);

	waitKey();
	destroyAllWindows();
}

void on_brightness(int pos, void* userdata)
{
	Mat src = *(Mat*)userdata;
	Mat dst = src + pos;

	imshow("dst", dst);
}




int main(void)
{
	brightness4();
	return 0;
}