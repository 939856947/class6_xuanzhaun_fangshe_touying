
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	cv::Mat disMat;
	cv::Mat disMat_Fangshe;
	cv::Mat disMat_Touying;
	cv::Mat srcMat = cv::imread("D:\\1233.jpg", 1);
	if (srcMat.empty()) return -1;

	//旋转-40度，缩放尺度为
	float angle = -10.0, scale = 1;
	//旋转中心为图像中心
	cv::Point2f  center(srcMat.cols*0.5, srcMat.rows*0.5);
	//获得变换矩阵
	const cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);
	cv::warpAffine(srcMat, disMat, affine_matrix, srcMat.size());
	cv::imshow("dst", disMat);


	//仿射
	const cv::Point2f src_pt[] = {
									cv::Point2f(200,200),
									cv::Point2f(250,200),
									cv::Point2f(200,100) };
	const cv::Point2f dst_pt[] = {
									cv::Point2f(300,100),
									cv::Point2f(300,50),
									cv::Point2f(200,100) };
	//计算仿射矩阵
	const cv::Mat affine_matrix_1 = cv::getAffineTransform(src_pt, dst_pt);
	cv::warpAffine(srcMat, disMat_Fangshe, affine_matrix_1, srcMat.size());
	cv::imshow("dst_fangshe", disMat_Fangshe);

	//投影变换
	const cv::Point2f src_pt_1[] = {
		cv::Point2f(150,150),
		cv::Point2f(150,300),
		cv::Point2f(350,300),
		cv::Point2f(350,150)};
	const cv::Point2f dst_pt_2[] = {
		cv::Point2f(200,150),
		cv::Point2f(200,300),
		cv::Point2f(340,270),
		cv::Point2f(340,180)};
	//透视变换行列式计算
	const cv::Mat affine_matrix_2 = cv::getAffineTransform(src_pt_1, dst_pt_2);
	cv::warpAffine(srcMat, disMat_Touying, affine_matrix_2, srcMat.size());
	cv::imshow("disMat_Touying", disMat_Touying);

	cv::imshow("src", disMat);
		waitKey(0);
	}

