#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void mask_copyTo()
{
	Mat src = imread("airplane.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat dst = imread("field.bmp", IMREAD_COLOR);

	if (src.empty() || mask.empty() || dst.empty())
	{
		cerr << "image load failed!" << endl;
	}

	src.copyTo(dst, mask);

	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}




int main(void)
{
	mask_copyTo();
	return 0;
}