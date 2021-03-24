#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

void example211() {
	cv::namedWindow("Example211", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example211-logpolar", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened()) {
		std::cout << "Could not open capture." << std::endl;
		return ;
	}
	double fps = cap.get(cv::CAP_PROP_FPS);
	cv::Size size((int)cap.get(cv::CAP_PROP_FRAME_WIDTH),
		(int)cap.get(cv::CAP_PROP_FRAME_HEIGHT)
		);
	cv::VideoWriter writer;
	//string output_file = "lpg_polar.avi";
	writer.open("lpg_polar.avi", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
	cv::Mat logpolar_frame, bgr_frame;
	for (;;) {
		cap >> bgr_frame;
		if (bgr_frame.empty()) break;
		cv::imshow("Example211", bgr_frame);
		cv::logPolar(
			bgr_frame,
			logpolar_frame,
			cv::Point2f(bgr_frame.cols/2,bgr_frame.rows/2),
			40,
			cv::WARP_FILL_OUTLIERS
		);
		cv::imshow("Example211-logpolar", logpolar_frame);
		writer << logpolar_frame;
		char c = cv::waitKey(10);
		if (c == 27) break;
	}
	cap.release();

}


int main211() {
	example211();
	return 0;
}