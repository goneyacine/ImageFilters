#pragma once

#include <opencv2/opencv.hpp>

namespace ImageFilters
{
	void WaveFilter(cv::Mat* p_input,cv::Mat* p_output, float p_multiplyerY,float p_multiplyerX);
	void ColorSwap(cv::Mat* p_input);
	void ToColor16(cv::Mat* p_input);

}
