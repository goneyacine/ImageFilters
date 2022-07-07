#include "Filters.h"
#include <opencv2/opencv.hpp>


using namespace ImageFilters;

cv::Mat ImageFilters::FilterA(cv::Mat img)
{
	cv::Mat output;
	cv::blur(img, output, cv::Size(50, 50));

	return output;
}