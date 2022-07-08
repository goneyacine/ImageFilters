#include "Filters.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>


using namespace ImageFilters;

void ImageFilters::WaveFilter(cv::Mat* p_input,cv::Mat* p_output,float p_multiplyerY,float p_multiplyerX)
{
	p_output->create(p_input->rows, p_input->cols, p_input->type());

	int newY;
	float time = (float)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	for (int y = 0; y < p_input->rows; y++)
	{
		for (int x = 0; x < p_input->cols; x++) 
		{ 
			newY = y + (int)(sin(((float)x / (float)p_input->cols / p_multiplyerX) * time) * p_multiplyerY);

			if (newY >= p_output->rows || newY < 0)
				continue;


			p_output->at<cv::Vec3b>(newY,x) = p_input->at<cv::Vec3b>(y,x);
		}
	}
}


void ImageFilters::ColorSwap(cv::Mat* p_input)
{
	uchar red;
	uchar blue;
	cv::Vec3b* color;

	for (int y = 0; y < p_input->rows; y++)
	{
		for (int x = 0; x < p_input->cols; x++)
		{
			color = &p_input->at<cv::Vec3b>(y, x);


			red = (*color)[2];
			blue = (*color)[0];
           

			(*color)[0] = red;
			(*color)[2] = blue;

		}
	}

}

void ImageFilters::ToColor16(cv::Mat* p_input)
{

	cv::Vec3b* color;

	for (int y = 0; y < p_input->rows; y++)
	{
		for (int x = 0; x < p_input->cols; x++)
		{
			color = &p_input->at<cv::Vec3b>(y, x);


			(*color)[0] = (uchar)((float)(*color)[0] / (float)0xFF * (float) 0xF);
			(*color)[0] = (uchar)((float)(*color)[0] / (float)0xF * (float)0xFF);

			(*color)[1] = (uchar)((float)(*color)[1] / (float)0xFF * (float)0xF);
			(*color)[1] = (uchar)((float)(*color)[1] / (float)0xF * (float)0xFF);

			(*color)[2] = (uchar)((float)(*color)[2] / (float)0xFF * (float)0xF);
			(*color)[2] = (uchar)((float)(*color)[2] / (float)0xF * (float)0xFF);

		}
	}
	
}




