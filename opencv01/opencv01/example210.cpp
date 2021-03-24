#include <opencv2/highgui.hpp>
#include <iostream>

void example210() {
	cv::namedWindow("Example2_10", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened()) {
		std::cout << "Couldn't open capture." << std::endl;
	}
	else {
		std::cout << "open capture 0" << std::endl;
		cv::Mat frame;
		for (;;) {
			cap >> frame;
			if (frame.empty()) break;
			cv::imshow("Example2_10", frame);
			if (cv::waitKey(33) >= 0)break;
		}
	}
}

int main210() {
	example210();
	return 0;

}