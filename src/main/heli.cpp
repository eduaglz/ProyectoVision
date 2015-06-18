#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace cv;
using namespace std;


int opcion;
int main()
{
	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Result", WINDOW_AUTOSIZE);
	Mat result;
	Mat img = imread("../Images/test1.jpg");
	Mat img2 = imread("../Images/puntos.jpg");
	Mat img3 = imread("../Images/puntos2.jpg");
	if(img.data)
		cout<< "Contiene Datos" << endl;
	imshow("Original", img);
	cout<<"1.- Box FIlter"<<endl;
	cout<<"2.- Gauss"<<endl;
	cout<<"3.- Median"<<endl;
	cout<<"4.- Laplacian"<<endl;
	cout<<"5.- Enhacement"<<endl;
	cout<<"6.- Bordes/Sobel"<<endl;
	cout<<"7.- Derivador"<<endl;
	cout<<"8.- Dilatacion"<<endl;
	cout<<"9.- Erosion"<<endl;
	cout<<"10.- Apertura"<<endl;
	cout<<"11.- Cerradura"<<endl;
	//cin >> opcion;
	int kernel_size = 9;
	int morphSize = 8;

	Mat kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);
	for(int i = 1; i < 12; i++)
	{
		switch(i)
		{
			case 1:
				filter2D(img, result, -1, kernel, Point(-1,-1), 0, BORDER_DEFAULT );
				break;

			case 2:
				GaussianBlur(img,result, Size(kernel_size,kernel_size),0.0);
				break;

			case 3:
				medianBlur(img,result,kernel_size);
				break;

			case 4:
				Laplacian(img,result,-1,kernel_size);
				break;

			case 5:
				Sobel(img,result,-1,1,1);
				result =  img + result;
				break;

			case 6:
				Sobel(img,result,-1,1,1);
				break;

			case 7:
				Sobel(img,result,-1,1,1);
				break;

			case 8:
				imshow("Original",img2);
				dilate( img2, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
				break;

			case 9:
				imshow("Original",img2);
				erode( img2, result, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
				break;

			case 10:
				imshow("Original",img3);
				erode( img3, result, getStructuringElement(MORPH_ELLIPSE, Size(morphSize, morphSize)) ); 
				dilate( result, result, getStructuringElement(MORPH_ELLIPSE, Size(morphSize, morphSize)) );
				break;

			case 11:
				imshow("Original",img3);
				dilate( img3, result, getStructuringElement(MORPH_ELLIPSE, Size(morphSize, morphSize)) );
				erode( result, result, getStructuringElement(MORPH_ELLIPSE, Size(morphSize, morphSize)) ); 
				break;
		}
		char buff[20];
		sprintf(buff,"../Resultados/%i.jpg",i);
		imwrite(buff,result);

	}
	//imshow( "Result", result );
	//Gaussiano
	//waitKey(0);
	return 0;
}