// OpenCV library

#include "opencv2/opencv.hpp"

#ifdef _DEBUG
// OpenCV lib名及版本
#define CV_LIBRARY(lib, ver) "opencv_"#lib""#ver"d.lib"
#else 
// OpenCV lib名及版本
#define CV_LIBRARY(lib, ver) "opencv_"#lib""#ver".lib"
#endif

// 使用OpenCV lib
#define CV_LIB(lib) CV_LIBRARY(lib, 300)

#pragma comment(lib, CV_LIB(calib3d))
#pragma comment(lib, CV_LIB(core))
#pragma comment(lib, CV_LIB(features2d))
#pragma comment(lib, CV_LIB(flann))
#pragma comment(lib, CV_LIB(highgui))
#pragma comment(lib, CV_LIB(imgproc))
#pragma comment(lib, CV_LIB(ml))
#pragma comment(lib, CV_LIB(objdetect))
#pragma comment(lib, CV_LIB(photo))
#pragma comment(lib, CV_LIB(stitching))
#pragma comment(lib, CV_LIB(superres))
#pragma comment(lib, CV_LIB(ts))
#pragma comment(lib, CV_LIB(video))
#pragma comment(lib, CV_LIB(videostab))

#if CV_VERSION_MAJOR >= 3
#pragma comment(lib, CV_LIB(hal))
#pragma comment(lib, CV_LIB(imgcodecs))
#pragma comment(lib, CV_LIB(shape))
#pragma comment(lib, CV_LIB(videoio))
#else 
#pragma comment(lib, CV_LIB(contrib))
#pragma comment(lib, CV_LIB(gpu))
#pragma comment(lib, "haartraining_engined.lib")
#pragma comment(lib, CV_LIB(legacy))
#pragma comment(lib, CV_LIB(nonfree))
#pragma comment(lib, CV_LIB(ocl))
#endif
