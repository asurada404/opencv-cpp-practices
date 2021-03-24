#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
int g_level = 2;



void exercises23() {
	cv::VideoCapture cap;
	cv::VideoWriter writer;
	cv::namedWindow("exercises23", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("exercises23-pyr", cv::WINDOW_AUTOSIZE);
	cap.open(0);
	if (!cap.isOpened()) {
		std::cout << "could not open !" << std::endl;
	}
	else {
		double fps = cap.get(cv::CAP_PROP_FPS);
		cv::Size size((int)cap.get(cv::CAP_PROP_FRAME_WIDTH) / 4,
			(int)cap.get(cv::CAP_PROP_FRAME_HEIGHT) / 4);

		writer.open("exercises23.avi", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);

		cv::createTrackbar("level", "exercises23", &g_level, 8);

		cv::Mat rgb_frame, pyr_frame;
		for (;;) {
			cap >> rgb_frame;
			cv::imshow("exercises23", rgb_frame);
			if (rgb_frame.empty()) break;
			cv::pyrDown(rgb_frame, pyr_frame);
			for (int i = 1; i < g_level/2; i++) {
				cv::pyrDown(pyr_frame, pyr_frame);
			}
			cv::imshow("exercises23-pyr", pyr_frame);
			writer << pyr_frame;
			char c = cv::waitKey(10);
			if (c == 27) break;

		}
		writer.release();
	}

}

int main() {
	exercises23();
	return 0;


}