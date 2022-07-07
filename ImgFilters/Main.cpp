#include <opencv2/opencv.hpp>
#include <iostream>
#include "Filters.h"



void ApplyWaveFileter(cv::VideoCapture p_camera);

int main()
{
	cv::VideoCapture camera(0);

	if (!camera.isOpened())
	{
		std::cout << "ERROR : we couldn't open camera " << "\n";
		return -1;
	}
	 
	ApplyWaveFileter(camera);
	
}

void ApplyWaveFileter(cv::VideoCapture p_camera)
{
	cv::Mat frame, output;

	std::cout << "Enter the y multiplyer" << "\n";
	float yMultiplyer;
	std::cin >> yMultiplyer;
	std::cout << "Enter the x multiplyer" << "\n";
	float xMultiplyer;
	std::cin >> xMultiplyer;

		while (true)
		{
			p_camera >> frame;
			//	cv::imshow("webCam", frame);
			ImageFilters::WaveFilter(&frame, &output,yMultiplyer,xMultiplyer);
			cv::imshow("filteredImg", output);

			if (cv::waitKey(10) >= 0)
				break;
		}
}