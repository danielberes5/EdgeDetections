// edgeDetect.cpp : Defines the entry point for the console application. 
// Environment: Visual studio 2019, Windows 10
// Assumptions: Opecv is installed configured in the visual studio project
// Opencv version: OpenCV 4.5.3

#include "edgeMethods.h"
#include <opencv2/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<string>
#include<iostream>



int main()
{

    cv::Mat imgOriginal;        // input image
    cv::Mat imgGrayscale;        // grayscale of input image
    cv::Mat imgBlurred;            // intermediate blured image
    cv::Mat imgCanny;            // Canny edge image
    cv::Mat imgPrew;            // Prewitt edge image
    cv::Mat imgSob;             // Sobel edge image
    cv::Mat imgLan;             // Laplacian edge image
    cv::Mat imgLan2;            // Laplacian edge image in consideration to the diagonal pixels

    std::cout << "Please enter an image filename : ";
    std::string img_addr;
    std::cin >> img_addr;

    std::cout << "Searching for " + img_addr << std::endl;

    imgOriginal = cv::imread(img_addr, cv::IMREAD_COLOR);            // open image

    if (imgOriginal.empty()) {                                    // if unable to open image
        std::cout << "error: image not read from file\n\n";        // show error message on command line
        return(0);                                                // and exit program
    }

    cv::cvtColor(imgOriginal, imgGrayscale, cv::COLOR_BGR2GRAY);        // convert to grayscale

    cv::GaussianBlur(imgGrayscale,            
        imgBlurred,                            
        cv::Size(5, 5),                        // smoothing window width and height in pixels
        1.5);                                // sigma value, determines how much the image will be blurred

    cv::Canny(imgBlurred,            
        imgCanny,                    
        100,                        // low threshold
        200);                        // high threshold

    edgeDetectPrew(imgBlurred, imgPrew);

    edgeDetectSob(imgBlurred, imgSob);

    edgeDetectLan(imgBlurred, imgLan);

    edgeDetectLan2(imgBlurred, imgLan2);


    // Declare windows
    // Note: you can use CV_WINDOW_NORMAL which allows resizing the window
    // or CV_WINDOW_AUTOSIZE for a fixed size window matching the resolution of the image
    // CV_WINDOW_AUTOSIZE is the default
    cv::namedWindow("imgOriginal", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("imgCanny", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("imgPrewitt", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("imgSobel", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("imgLaplacian", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("imgLaplacian2", cv::WINDOW_AUTOSIZE);

    //Show windows
    cv::imshow("imgOriginal", imgOriginal);
    cv::imshow("imgCanny", imgCanny);
    cv::imshow("imgPrewitt", imgPrew);
    cv::imshow("imgSobel", imgSob);
    cv::imshow("imgLaplacian", imgLan);
    cv::imshow("imgLaplacian2", imgLan2);

    cv::waitKey(0);                    // hold windows open until user presses a key
    return 0;
}
