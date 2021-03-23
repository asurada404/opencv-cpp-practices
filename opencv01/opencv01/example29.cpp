#include <opencv2/opencv.hpp>

int main() {
	cv::Mat img_rgb, img_gray, img_gray2, img_cny;

	img_rgb = cv::imread("test.jpg");
	cv::cvtColor(img_rgb, img_gray, cv::COLOR_BGR2GRAY);
	cv::pyrDown(img_gray, img_gray);
	cv::pyrDown(img_gray, img_gray2);
	cv::Canny(img_gray2, img_cny, 10, 100, 3, true);

	int x = 16;
	int y = 32;
	cv::Vec3b intensity = img_rgb.at<cv::Vec3b>(y, x);
	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];

	std::cout << "At (x,y) : " << x << ", " << y << std::endl;
	std::cout << "(b, g, r)" << (unsigned int)blue << " ," << (unsigned int)green << " ," << (unsigned int)red << std::endl;
	x /= 4;
	y /= 4;

	std::cout << "Pyrmid2 pixel " << (unsigned int)img_gray2.at<uchar>(y, x) << std::endl;

	return 0;
}