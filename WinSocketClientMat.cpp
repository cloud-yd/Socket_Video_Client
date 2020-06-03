/*Í¼Ïñ·¢ËÍ*/
#include "WinSocketClient.h"
#include <iostream>

int main()
{
	WinsockMatTransmissionClient socketMat;
	socketMat.socketConnect("192.168.0.182", 6000);

	cv::namedWindow("camera", cv::WINDOW_AUTOSIZE);
#if 1
	cv::VideoCapture capture;
	capture.open(0);
	//capture.open(1);
	cv::Mat image;

	while (1)
	{
		if (!capture.isOpened())
			return 0;

		capture >> image;

		if (image.empty())
		{
			printf("image is empty \n");
			return 0;
		}
		else
		{
			cv::imshow("camera", image);
			cv::waitKey(10);
			socketMat.transmit(image);
		}

	}
#else

	for (;;)
	{
		socketMat.transmit();
	}
#endif
	socketMat.socketDisconnect();
	cv::destroyAllWindows();
	return 0;
}
