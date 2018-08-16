#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <cmath>
using namespace cv;
using namespace std;

int main()
{
	Mat img= imread("test_f3.png",0);//need to read in grayscale
	string WINDOW = "Occupancy-Grid";//window for trackbar
    namedWindow(WINDOW,CV_WINDOW_AUTOSIZE); 
	int r= 4;
	createTrackbar("r",WINDOW, &r, img.rows);
	Point center=Point(img.cols/2, img.rows/2);
	cout<<center.x<<" "<<center.y<<endl;
	while(1)
	{
		//dft
		Mat dftInput1, dftImage1, inverseDFT, inverseDFTconverted, dft_image=Mat::zeros(img.rows, img.cols, CV_8U);
	    img.convertTo(dftInput1, CV_32F);
	    dft(dftInput1, dftImage1, DFT_COMPLEX_OUTPUT);
	    //frequency filtering
	    r = getTrackbarPos("r",WINDOW);//getting radius from trackbar
	    //at a radius r with center of image as center of circle, let values be of dft image be as they are, convert all other values to black.
	    //Not applying angle from center due to bad output when this is done. Therefore,brute force is used.
	    for(int row=0;row<img.rows;row++)
	    {
	    	for(int col=0;col<img.cols;col++)
	    	{
	    		int dist=sqrt((center.x-col)*(center.x-col)+(center.y-row)*(center.y-row));
	    		if(abs(int(dist)-r)!=0 )
	    		{
	    			dftImage1.at<uchar>(row,col)=0;
	    		}
	    	}
	    }
	    // copying dft image to another image due to error in imshow and convertTo
	    for (int row=0;row<dftImage1.rows;row++)
    	{
	        for(int col=0;col<dftImage1.cols;col++)
	        {
	             dft_image.at<uchar>(row,col)=dftImage1.at<uchar>(row,col);
	        }
    	}
	    idft(dftImage1, inverseDFT,  2 | DFT_REAL_OUTPUT);
	    inverseDFT.convertTo(inverseDFTconverted, CV_32F);
	    imshow("input", img);
	    imshow("dft", dft_image);
	    imshow("inverseDFT", inverseDFTconverted);
	    waitKey(1);
	}

}