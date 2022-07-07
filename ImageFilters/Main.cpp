#include <opencv2/opencv.hpp>
#include <iostream>
#include "Filters.h"


int main()
{
	cv::VideoCapture camera(0);

	if (!camera.isOpened())
	{
		std::cout << "ERROR : we couldn't open camera " << "\n";
		return -1;
	}

	cv::Mat frame;

	camera >> frame;

	while (true)
	{
		cv::imshow("webCam", frame);
		cv::imshow("filteredImg", ImageFilters::FilterA(frame));

		if (cv::waitKey(10) >= 0)
			break;
	}
}