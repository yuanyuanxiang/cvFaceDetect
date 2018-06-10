#include "stdafx.h"
#include <time.h>
using namespace cv;

/**
* @brief 在opencv3中进行人脸检测.
*/
int main()
{
	const char xmlPath[] = "data/haarcascade_frontalface_default.xml";
	CascadeClassifier ccf;   // 分类器对象
	if(!ccf.load(xmlPath))   // 加载训练文件
	{
		return 0;
	}
	VideoCapture cap(NULL);
	namedWindow("faces", WINDOW_NORMAL);
	while (true)
	{
		clock_t t = clock();
		Mat frame, gray;
		cap >> frame;
		cvtColor(frame, gray, CV_BGR2GRAY); // 转换成灰度图，因为harr特征从灰度图中提取
		equalizeHist(gray, gray);  // 直方图均衡
		std::vector<Rect> faces;  // 创建一个容器保存检测出来的脸
		ccf.detectMultiScale(gray,faces,1.1,3,0,Size(24,24),Size(256,256)); // 检测人脸
		for(std::vector<Rect>::const_iterator iter = faces.begin(); iter != faces.end(); ++iter)
			rectangle(frame, *iter, Scalar(255, 0, 0), 1, 8); // 画出脸部矩形
		imshow("faces", frame);
		t = clock() - t;
		int n = 40 - t;
		waitKey(max(n, 1));
	}
	cvDestroyAllWindows();
	return 1;
}
