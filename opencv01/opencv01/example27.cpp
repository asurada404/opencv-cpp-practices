#include <opencv2/opencv.hpp>

int main27() {
	cv::Mat img_rgb, img_gray, img_cny;
	cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

	img_rgb = cv::imread("test.jpg"); 
	cv::cvtColor(img_rgb, img_gray, cv::COLOR_BGR2GRAY);

	cv::imshow("Example Gray", img_gray);
	cv::Canny(img_gray, img_cny, 10, 100, 3, true);
	cv::imshow("Example Canny", img_cny);
	cv::waitKey(0);

	return 0;
}