#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

int DD (int n,int * x, int *y, int start, int end)
{
	if (n==2)
	{
		cout<<"done"<<endl;
		return (y[start]-y[end])/(x[start]-x[end]);
	}
	else
	{
		cout<<"going"<<endl;
		return DD(n-1, x,y,1,n-1)-DD(n-1,x,y,0,n-2);
	}
} 
int find_polynomial(int var, int* x, int* y,int n)
{
	int prod=1,poly=0;
	for (int i=1;i<n;++i)
	{
		prod=prod*(var-x[i-1]);
		if(i=1)
			{int q=DD(i+1,x,y,0,i);}
		else
		{
		int q=DD(i+1,x,y,0,i)/(x[i]-x[0]);}
		poly=poly+prod*q;
	}
	return poly+y[0];
}   
int main()
{
	Mat image=imread("dog.jpg");
	Mat gray;
	Mat drawing(600, 800, CV_8UC1, Scalar::all(0)); 
	cvtColor(image, gray, CV_BGR2GRAY);
	gray.copyTo(drawing(cv::Rect(0,0,gray.cols, gray.rows)));
	int x[image.cols];
	int y[image.cols];
	for(int row=0;row<image.rows;++row)
	{
	for(int i=0;i<image.cols;++i)
	{
		x[i]=i;
		y[i]=gray.at<uchar>(i, row);
	}
	for (int j=image.cols;j<drawing.cols;++j)
	{
		drawing.at<uchar>(j,row)=find_polynomial(j,x,y,image.cols);
	}
}
imshow("win", drawing);
}

                