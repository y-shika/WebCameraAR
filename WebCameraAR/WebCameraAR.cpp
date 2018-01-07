#include <iostream>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void) {
	VideoCapture capture(0);
	VideoCapture video("video\\shiki_chromakey.mp4");

	if (!capture.isOpened())
		return -1;
	if (!video.isOpened())
		return -1;

	Mat src_video;
	Mat frame;
	Mat Img;
	Mat mat = (Mat_<double>(2, 3) << 1.0, 0.0, 10, 0.0, 1.0, 10);

	char windowName1[] = "WebCamera";
	namedWindow(windowName1, CV_WINDOW_AUTOSIZE);
	/*char windowName2[] = "Video";
	namedWindow(windowName2, CV_WINDOW_AUTOSIZE);*/

	while (cvWaitKey(1) == -1) {
		capture >> frame;
		src_video = frame;
		video >> Img;

		resize(src_video, src_video, Size(), 2, 2);
		resize(Img, Img, Size(), 0.5, 0.5);

		if (Img.empty())
			break;

		warpAffine(Img, src_video, mat, src_video.size(), CV_INTER_LINEAR, BORDER_TRANSPARENT);

		imshow(windowName1, src_video);
		//imshow(windowName2, Img);
	}

	destroyAllWindows();
	return 0;
}