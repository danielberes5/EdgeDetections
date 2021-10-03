// edgeMethods.cpp : Defines the working of the additional edge methods
// Environment: Visual studio 2019, Windows 10
// Assumptions: Opecv is installed configured in the visual studio project
// Opencv version: OpenCV 4.5.3

#include "edgeMethods.h"
#include<opencv2/imgproc/imgproc.hpp>
#include<string>
#include<iostream>

//The edge methods works with CV_8UC1-type images

void edgeDetectPrew(const cv::Mat src, cv::Mat& dst)
{
	assert(!src.empty());
	dst = cv::Mat::zeros(src.size(), CV_8UC1);

	for (uint i = 1; i < src.rows; i++)
	{
		for (uint j = 1; j < src.cols; j++)
		{
			int sumX = src.at<uchar>(i + 1, j + 1);
			sumX += src.at<uchar>(i, j + 1);
			sumX += src.at<uchar>(i - 1, j + 1);
			sumX -= src.at<uchar>(i - 1, j - 1);
			sumX -= src.at<uchar>(i, j - 1);
			sumX -= src.at<uchar>(i + 1, j - 1);

			int sumY = src.at<uchar>(i + 1, j + 1);
			sumY += src.at<uchar>(i + 1, j);
			sumY += src.at<uchar>(i + 1, j - 1);
			sumY -= src.at<uchar>(i - 1, j + 1);
			sumY -= src.at<uchar>(i - 1, j);
			sumY -= src.at<uchar>(i - 1, j - 1);

			dst.at<uchar>(i, j) = sqrt((sumX * sumX) + (sumY * sumY));
		}
	}
}

void edgeDetectSob(const cv::Mat src, cv::Mat& dst)
{
	assert(!src.empty());
	dst = cv::Mat::zeros(src.size(), CV_8UC1);

	for (uint i = 1; i < src.rows; i++)
	{
		for (uint j = 1; j < src.cols; j++)
		{
			int sumX = src.at<uchar>(i + 1, j + 1);
			sumX += src.at<uchar>(i, j + 1) * 2;
			sumX += src.at<uchar>(i - 1, j + 1);
			sumX -= src.at<uchar>(i - 1, j - 1);
			sumX -= src.at<uchar>(i, j - 1) * 2;
			sumX -= src.at<uchar>(i + 1, j - 1);

			int sumY = src.at<uchar>(i + 1, j + 1);
			sumY += src.at<uchar>(i + 1, j) * 2;
			sumY += src.at<uchar>(i + 1, j - 1);
			sumY -= src.at<uchar>(i - 1, j + 1);
			sumY -= src.at<uchar>(i - 1, j) * 2;
			sumY -= src.at<uchar>(i - 1, j - 1);

			dst.at<uchar>(i, j) = sqrt((sumX * sumX) + (sumY * sumY));
		}
	}
}

void edgeDetectLan(const cv::Mat src, cv::Mat& dst)
{
	assert(!src.empty());
	dst = cv::Mat::zeros(src.size(), CV_8UC1);

	for (uint i = 1; i < src.rows - 1; i++)
	{
		for (uint j = 1; j < src.cols - 1; j++)
		{
			int sum = src.at<uchar>(i, j) * 4;
			sum -= src.at<uchar>(i - 1, j);
			sum -= src.at<uchar>(i + 1, j);
			sum -= src.at<uchar>(i, j - 1);
			sum -= src.at<uchar>(i, j + 1);

			dst.at<uchar>(i, j) = abs(sum);

		}
	}
}

void edgeDetectLan2(const cv::Mat src, cv::Mat& dst)
{
	assert(!src.empty());
	dst = cv::Mat::zeros(src.size(), CV_8UC1);

	for (uint i = 1; i < src.rows - 1; i++)
	{
		for (uint j = 1; j < src.cols - 1; j++)
		{
			int sum = src.at<uchar>(i, j) * 8;
			sum -= src.at<uchar>(i - 1, j);
			sum -= src.at<uchar>(i + 1, j);
			sum -= src.at<uchar>(i, j - 1);
			sum -= src.at<uchar>(i, j + 1);
			sum -= src.at<uchar>(i - 1, j - 1);
			sum -= src.at<uchar>(i + 1, j + 1);
			sum -= src.at<uchar>(i - 1, j + 1);
			sum -= src.at<uchar>(i + 1, j - 1);

			dst.at<uchar>(i, j) = abs(sum);
		}
	}
}