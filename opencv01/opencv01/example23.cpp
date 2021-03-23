#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/core.hpp>

#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace cv;
void show_image() {
	cv::Mat doomer = cv::imread("doomer.jpg");
	if (!doomer.empty()) {
		cv::imshow("depressed", doomer);
		cv::waitKey();
		cv::destroyWindow("depressed");
	}
	else {
		std::cout << "File not found." << std::endl;
	}
}

void show_video() {
	cv::namedWindow("example3", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	cap.open("video_demo.mp4");
	cv::Mat frame;
	for (;;) {
		cap >> frame;
		if (frame.empty()) break;
		cv::imshow("example3", frame);
		if (cv::waitKey(33) >= 0) break;

	}
}

int main23() {
	show_video();
	return 0;

}