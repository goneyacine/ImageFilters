#include "Filters.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>


using namespace ImageFilters;

void ImageFilters::WaveFilter(cv::Mat* p_input,cv::Mat* p_output,float p_multiplyerY,float p_multiplyerX)
{
	p_output->create(p_input->rows, p_input->cols, p_input->type());

	int newY;
	float time_ = (float)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	for (int y = 0; y < p_input->rows; y++)
	{
		for (int x = 0; x < p_input->cols; x++) 
		{ 
			newY = y + (int)(sin(((float)x / (float)p_input->cols / p_multiplyerX) * time_) * p_multiplyerY);

			if (newY >= p_output->rows || newY < 0)
				continue;


			p_output->at<cv::Vec3b>(newY,x) = p_input->at<cv::Vec3b>(y,x);
		}
	}
}
