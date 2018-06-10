#include "stdafx.h"
#include <time.h>
using namespace cv;

/**
* @brief ��opencv3�н����������.
*/
int main()
{
	const char xmlPath[] = "data/haarcascade_frontalface_default.xml";
	CascadeClassifier ccf;   // ����������
	if(!ccf.load(xmlPath))   // ����ѵ���ļ�
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
		cvtColor(frame, gray, CV_BGR2GRAY); // ת���ɻҶ�ͼ����Ϊharr�����ӻҶ�ͼ����ȡ
		equalizeHist(gray, gray);  // ֱ��ͼ����
		std::vector<Rect> faces;  // ����һ�������������������
		ccf.detectMultiScale(gray,faces,1.1,3,0,Size(24,24),Size(256,256)); // �������
		for(std::vector<Rect>::const_iterator iter = faces.begin(); iter != faces.end(); ++iter)
			rectangle(frame, *iter, Scalar(255, 0, 0), 1, 8); // ������������
		imshow("faces", frame);
		t = clock() - t;
		int n = 40 - t;
		waitKey(max(n, 1));
	}
	cvDestroyAllWindows();
	return 1;
}
