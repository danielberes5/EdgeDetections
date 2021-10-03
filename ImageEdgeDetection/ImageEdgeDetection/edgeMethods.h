// edgeMethods.h : Declaration of the edgeMethods.cpp methods
// Environment: Visual studio 2019, Windows 10
// Assumptions: Opecv is installed configured in the visual studio project
// Opencv version: OpenCV 4.5.3


#ifndef E_METHODS_H_INCLUDED
#define E_METHODS_H_INCLUDED

#include<opencv2/core.hpp>


void edgeDetectPrew(const cv::Mat src, cv::Mat& dst);

void edgeDetectSob(const cv::Mat src, cv::Mat& dst);

void edgeDetectLan(const cv::Mat src, cv::Mat& dst);

void edgeDetectLan2(const cv::Mat src, cv::Mat& dst);



#endif
