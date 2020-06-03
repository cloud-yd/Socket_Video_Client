#pragma once

#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <stdio.h>
#include <Winsock2.h>

#pragma warning(disable:4996)
#pragma comment(lib, "WS2_32") //链接到WS2_32.lib

using namespace std;
using namespace cv;


//待传输图像默认大小为 640*480，可修改
#define IMG_WIDTH 640	// 需传输图像的宽
#define IMG_HEIGHT 480	// 需传输图像的高
//默认格式为CV_8UC3
#define BUFFER_SIZE IMG_WIDTH*IMG_HEIGHT*3/32

struct sentbuf
{
	char buf[BUFFER_SIZE];
	int flag;
};

class WinsockMatTransmissionClient
{
public:
	WinsockMatTransmissionClient(void);
	~WinsockMatTransmissionClient(void);

private:
	SOCKET sockClient;
	struct sentbuf data;

public:

	// 打开socket连接
	// params :	IP		服务器的ip地址
	//			PORT	传输端口
	// return : -1		连接失败
	//			1		连接成功
	int socketConnect(const char* IP, int PORT);


	// 传输图像
	// params : image 待传输图像
	// return : -1		传输失败
	//			1		传输成功
	int transmit(cv::Mat image);


	// 断开socket连接
	void socketDisconnect(void);
};

