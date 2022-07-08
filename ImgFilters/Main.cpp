#include <opencv2/opencv.hpp>
#include <iostream>
#include "Filters.h"



void ApplyWaveFilter(cv::VideoCapture p_camera);
void ApplyColorSwapEffect(cv::VideoCapture p_camera);
void ApplyToColor16Effect(cv::VideoCapture p_camera);

int main()
{
	cv::VideoCapture camera(0);

	if (!camera.isOpened())
	{
		std::cout << "ERROR : we couldn't open camera " << "\n";
		return -1;
	}
	 
	//ApplyWaveFilter(camera);
	//ApplyColorSwapEffect(camera);
	ApplyToColor16Effect(camera);
}

void ApplyWaveFilter(cv::VideoCapture p_camera)
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
			ImageFilters::WaveFilter(&frame, &output,yMultiplyer,xMultiplyer);
			cv::imshow("Wave Effect", output);

			if (cv::waitKey(10) >= 0)
				break;
		}
}

void ApplyColorSwapEffect(cv::VideoCapture p_camera)
{
	cv::Mat frame;



	while (true)
	{
		p_camera >> frame;
		ImageFilters::ColorSwap(&frame);
		cv::imshow("Color Effect", frame);

		if (cv::waitKey(10) >= 0)
			break;
	}
}


void ApplyToColor16Effect(cv::VideoCapture p_camera)
{
	cv::Mat frame;


	while (true)
	{
		p_camera >> frame;
		ImageFilters::ToColor16(&frame);

		cv::imshow("To Color 16 ", frame);


		if (cv::waitKey(10) >= 0)
			break;
	}
}

