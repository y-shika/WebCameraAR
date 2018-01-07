#include <iostream>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void) {
	VideoCapture capture(0);

	if (!capture.isOpened())
		return -1;

	Mat src_video(Size(640, 480), CV_8UC1, Scalar::all(255));
	Mat frame(Size(640, 480), CV_8UC1, Scalar::all(255));

	char windowName[] = "WebCamera";
	namedWindow(windowName, CV_WINDOW_AUTOSIZE);

	while (cvWaitKey(1) == -1) {
		capture >> frame;
		src_video = frame;
		imshow(windowName, src_video);
	}

	destroyAllWindows();
	return 0;
}