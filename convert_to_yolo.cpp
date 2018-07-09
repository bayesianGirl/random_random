


using namespace std;
using namespace cv;
int main()
{
	Mat image= imread("example.jpg");
	double x_center_ratio, y_center_ratio, width_ratio, height_ratio;
	cin>>x_center_ratio>>y_center_ratio>>width_ratio>>height_ratio;
	double height= image.rows;
	double width= image.cols;
	double x_center= x_center_ratio*width;
	double y_center=y_center_ratio*height;
	double height_bb=height_ratio*height;
	double width_bb= width_ratio* width;
	double x_min= x_center-(width_bb/2);
	double y_min= y_center-(height_bb/2);
	double x_max= x_center+(width_bb/2);
	double y_max= y_center+(height_bb/2);

}



