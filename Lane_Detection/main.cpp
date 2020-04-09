#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>
//#include <math.h>
#include <vector>

#include "imgUtils.h"
#include "lane.hpp"

using namespace cv;
using namespace std;

static void help(char **argv) 
{
	cout << endl
		 << "This program demonstrated the use of the discrete Fourier transform (DFT). " << endl
		 << "The dft of an image is taken and it's power spectrum is displayed." << endl << endl
		 << "Usage:" << endl
		 << argv[0] << " [image_name -- default lena.jpg]" << endl << endl;
}

//=============================================================================================
int main(int argc, char **argv)
{
	Mat I = imread("../data/image.png", CV_LOAD_IMAGE_COLOR);
	lane L(I);

	L.BirdEyeView();
	L.thresholdColChannel();
	Mat bin;
	cvtColor(L.m_HSV, bin, COLOR_HSV2BGR);

	imshow("Im_source", L.m_matSrc);
	imshow("Bird Eye View", L.m_BEV);
	imshow("Thresh", L.m_HSV);
	imshow("Binary_Thresh", bin);

	waitKey(0);
	destroyAllWindows();	
	return EXIT_SUCCESS;
}

