// #include <opencv2/imgproc/imgproc.hpp>
// #include <opencv2/core/core.hpp>
// #include <opencv2/highgui/highgui.hpp>
// #include "SDL/SDL.h"
// /*
//  * A simple 'getting started' interface to the ARDrone, v0.2 
//  * author: Tom Krajnik
//  * The code is straightforward,
//  * check out the CHeli class and main() to see 
//  */
// #include <stdlib.h>
// #include "CHeli.h"
// #include <unistd.h>
// #include <stdio.h>
// #include <iostream>

// using namespace std;
// using namespace cv;

// bool stop = false;
// CRawImage *image;
// CHeli *heli;
// // float pitch, roll, yaw, height;
// // int hover;
// // // Joystick related
// // SDL_Joystick* m_joystick;
// // bool useJoystick;
// // int joypadRoll, joypadPitch, joypadVerticalSpeed, joypadYaw;
// // bool navigatedWithJoystick, joypadTakeOff, joypadLand, joypadHover;

// // // Convert CRawImage to Mat
// // void rawToMat( Mat &destImage, CRawImage* sourceImage)
// // {	
// // 	uchar *pointerImage = destImage.ptr(0);
	
// // 	for (int i = 0; i < 240*320; i++)
// // 	{
// // 		pointerImage[3*i] = sourceImage->data[3*i+2];
// // 		pointerImage[3*i+1] = sourceImage->data[3*i+1];
// // 		pointerImage[3*i+2] = sourceImage->data[3*i];
// // 	}
// // }

// /*
//  * This method flips horizontally the sourceImage into destinationImage. Because it uses 
//  * "Mat::at" method, its performance is low (redundant memory access searching for pixels).
//  */
// void flipImageBasic(const Mat &sourceImage, Mat &destinationImage)
// {
// 	if (destinationImage.empty())
// 		destinationImage = Mat(sourceImage.rows, sourceImage.cols, sourceImage.type());

// 	for (int y = 0; y < sourceImage.rows; ++y)
// 		for (int x = 0; x < sourceImage.cols / 2; ++x)
// 			for (int i = 0; i < sourceImage.channels(); ++i)
// 			{
// 				destinationImage.at<Vec3b>(y, x)[i] = sourceImage.at<Vec3b>(y, sourceImage.cols - 1 - x)[i];
// 				destinationImage.at<Vec3b>(y, sourceImage.cols - 1 - x)[i] = sourceImage.at<Vec3b>(y, x)[i];
// 			}
// }

// void getGrayColors(const Mat &sourceImage, Mat &destinationImage)
// {
//     if (destinationImage.empty())
//         destinationImage = Mat(sourceImage.rows, sourceImage.cols, sourceImage.type());

//     for (int y = 0; y < sourceImage.rows; ++y)
//         for (int x = 0; x < sourceImage.cols / 2; ++x)
//         {
//             //b
//             int blue = sourceImage.at<Vec3b>(y,x)[0];
//             //g
//             int verde = sourceImage.at<Vec3b>(y,x)[1];
//             //r
//             int rojo = sourceImage.at<Vec3b>(y,x)[2];
//         }
//             // for (int i = 0; i < sourceImage.channels(); ++i)
//             // {
//             //     destinationImage.at<Vec3b>(y, x)[i] = sourceImage.at<Vec3b>(y, sourceImage.cols - 1 - x)[i];
//             //     destinationImage.at<Vec3b>(y, sourceImage.cols - 1 - x)[i] = sourceImage.at<Vec3b>(y, x)[i];
//             // }
// }

// int main(int argc,char* argv[])
// {
// 	//establishing connection with the quadcopter
// 	heli = new CHeli();
	
// 	//this class holds the image from the drone	
// 	image = new CRawImage(320,240);
	
// 	// Initial values for control	
//     // pitch = roll = yaw = height = 0.0;
//     // joypadPitch = joypadRoll = joypadYaw = joypadVerticalSpeed = 0.0;

// 	// Destination OpenCV Mat	
// 	Mat currentImage = Mat(240, 320, CV_8UC3);
// 	// Show it	
// 	imshow("ParrotCam", currentImage);
// 	// Image to use for the mirror
// 	Mat mirrorImage = Mat(240, 320, CV_8UC3);

//     // Initialize joystick
//     // SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
//     // useJoystick = SDL_NumJoysticks() > 0;
//     // if (useJoystick)
//     // {
//     //     SDL_JoystickClose(m_joystick);
//     //     m_joystick = SDL_JoystickOpen(0);
//     // }

//     while (stop == false)
//     {

//         // Clear the console
//         printf("\033[2J\033[1;1H");

//         // if (useJoystick)
//         // {
//         //     SDL_Event event;
//         //     SDL_PollEvent(&event);

//         //     joypadRoll = SDL_JoystickGetAxis(m_joystick, 2);
//         //     joypadPitch = SDL_JoystickGetAxis(m_joystick, 3);
//         //     joypadVerticalSpeed = SDL_JoystickGetAxis(m_joystick, 1);
//         //     joypadYaw = SDL_JoystickGetAxis(m_joystick, 0);
//         //     joypadTakeOff = SDL_JoystickGetButton(m_joystick, 1);
//         //     joypadLand = SDL_JoystickGetButton(m_joystick, 2);
//         //     joypadHover = SDL_JoystickGetButton(m_joystick, 0);
//         // }

//         // // prints the drone telemetric data, helidata struct contains drone angles, speeds and battery status
//         // printf("===================== Parrot Basic Example =====================\n\n");
//         // fprintf(stdout, "Angles  : %.2lf %.2lf %.2lf \n", helidata.phi, helidata.psi, helidata.theta);
//         // fprintf(stdout, "Speeds  : %.2lf %.2lf %.2lf \n", helidata.vx, helidata.vy, helidata.vz);
//         // fprintf(stdout, "Battery : %.0lf \n", helidata.battery);
//         // fprintf(stdout, "Hover   : %d \n", hover);
//         // fprintf(stdout, "Joypad  : %d \n", useJoystick ? 1 : 0);
//         // fprintf(stdout, "  Roll    : %d \n", joypadRoll);
//         // fprintf(stdout, "  Pitch   : %d \n", joypadPitch);
//         // fprintf(stdout, "  Yaw     : %d \n", joypadYaw);
//         // fprintf(stdout, "  V.S.    : %d \n", joypadVerticalSpeed);
//         // fprintf(stdout, "  TakeOff : %d \n", joypadTakeOff);
//         // fprintf(stdout, "  Land    : %d \n", joypadLand);
//         // fprintf(stdout, "Navigating with Joystick: %d \n", navigatedWithJoystick ? 1 : 0);

// 		//image is captured
// 		heli->renewImage(image);

// 		// Copy to OpenCV Mat
// 		rawToMat(currentImage, image);
// 		imshow("ParrotCam", currentImage);
		
// 		// Mirror the image
// 		flipImageBasic(currentImage, mirrorImage);
// 		imshow("MirrorCam", mirrorImage);

//   //       char key = waitKey(5);
// 		// switch (key) {
// 		// 	case 'a': yaw = -20000.0; break;
// 		// 	case 'd': yaw = 20000.0; break;
// 		// 	case 'w': height = -20000.0; break;
// 		// 	case 's': height = 20000.0; break;
// 		// 	case 'q': heli->takeoff(); break;
// 		// 	case 'e': heli->land(); break;
// 		// 	case 'z': heli->switchCamera(0); break;
// 		// 	case 'x': heli->switchCamera(1); break;
// 		// 	case 'c': heli->switchCamera(2); break;
// 		// 	case 'v': heli->switchCamera(3); break;
// 		// 	case 'j': roll = -20000.0; break;
// 		// 	case 'l': roll = 20000.0; break;
// 		// 	case 'i': pitch = -20000.0; break;
// 		// 	case 'k': pitch = 20000.0; break;
//   //           case 'h': hover = (hover + 1) % 2; break;
//   //           case 27: stop = true; break;
//   //           default: pitch = roll = yaw = height = 0.0;
// 		// }

//   //       if (joypadTakeOff) {
//   //           heli->takeoff();
//   //       }
//   //       if (joypadLand) {
//   //           heli->land();
//   //       }
//   //       hover = joypadHover ? 1 : 0;

//         //setting the drone angles
//         // if (joypadRoll != 0 || joypadPitch != 0 || joypadVerticalSpeed != 0 || joypadYaw != 0)
//         // {
//         //     heli->setAngles(joypadPitch, joypadRoll, joypadYaw, joypadVerticalSpeed, hover);
//         //     navigatedWithJoystick = true;
//         // }
//         // else
//         // {
//         //     heli->setAngles(pitch, roll, yaw, height, hover);
//         //     navigatedWithJoystick = false;
//         // }

//         usleep(15000);
// 	}
	
// 	// heli->land();
//     // SDL_JoystickClose(m_joystick);
//     delete heli;
// 	delete image;
// 	return 0;
// }

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>


using namespace cv;
using namespace std;


bool video = true;
Mat stillImage;
Mat resultImage = Mat(480, 640, CV_8UC3, Scalar(0,0,0));
Mat rojo;
Mat verde;
Mat azul;

int mouseX = 0;
int mouseY = 0;

uchar mouseR = 0;
uchar mouseG = 0;
uchar mouseB = 0;

int histRojo[256];
int histVerde[256];
int histAzul[256];

int umbralRojo[2]={0,255};
int umbralAzul[2]={0,255};
int umbralVerde[2]={0,255};

int frontera = 127;

bool firstClick = true;

// Here we will store points
vector<Point> points;

Mat getGrayScale(const Mat &sourceImage)
{
    //printf("ciclo /n"); 
    Mat destinationImage;
     if (destinationImage.empty())
         destinationImage = Mat(sourceImage.rows, sourceImage.cols, CV_8UC1);

     for (int y = 0; y < sourceImage.rows; y++)
         for (int x = 0; x < sourceImage.cols; x++)
         {
            uchar gray = sourceImage.at<Vec3b>(y,x)[0]*0.1 
                    +   sourceImage.at<Vec3b>(y,x)[1]*0.3
                    +   sourceImage.at<Vec3b>(y,x)[2]*0.6;
            destinationImage.at<uchar>(y,x) = gray > frontera ? 0 : 255;
         }

     return destinationImage;
}

Mat getChannel(const Mat &sourceImage, const int channel)
{
    //printf("ciclo /n"); 
    Mat destinationImage;
     if (destinationImage.empty())
         destinationImage = Mat(sourceImage.rows, sourceImage.cols, CV_8UC1);

     for (int y = 0; y < sourceImage.rows; y++)
         for (int x = 0; x < sourceImage.cols; x++)
         {
            destinationImage.at<uchar>(y,x) = sourceImage.at<Vec3b>(y,x)[channel];
         }

     return destinationImage;
}

void calcHistRGB(const Mat &sourceImage, int *red, int *green, int *blue)
{
    Mat destinationImage;
     if (destinationImage.empty())
         destinationImage = Mat(sourceImage.rows, sourceImage.cols, CV_8UC3);

     for (int y = 0; y < sourceImage.rows; y++)
         for (int x = 0; x < sourceImage.cols; x++)
         {
            int r = sourceImage.at<Vec3b>(y,x)[2];
            int g = sourceImage.at<Vec3b>(y,x)[1];
            int b = sourceImage.at<Vec3b>(y,x)[0];

            red[r]++;
            green[g]++;
            blue[b]++;
         }
}
void colorBand(Mat destImage)
{
    for(int x = 0; x< 256;x++)
    {
        for(int y=101;y<120;y++)
        {
            destImage.at<Vec3b>(y,x)[0]=x;
            destImage.at<Vec3b>(y,x)[1]=x;
            destImage.at<Vec3b>(y,x)[2]=x;
        }
    }
}

void graphHist(Mat destImage, int *datos,Scalar color)
{
    float total = 640*480.0;
    int size = 480;
    for (int i = 0; i < 255; ++i) {
        Point topLeft = Point(i,100-datos[i]/160); 
        Point topRight = Point(i+1,100-datos[i+1]/160);
        line(destImage, topLeft, topRight,color,2,8);
    }
    colorBand(destImage);
}

void graphVerticalLine(Mat destImage, int *datos, int x)
{
    Point topLeft = Point(x,100-datos[x]/160); 
    Point topRight = Point(x,100);
    line(destImage, topLeft, topRight,Scalar(255,255,255),2,8);
}

void fillHist(Mat destImage, int *datos,Scalar color, int *rango)
{
    for (int i = 0; i < 255; ++i) {
        float topLeft = 100-datos[i]/160;
        float topRight = 100- datos[i+1]/160;
        // Point puntos[1][4];
        // puntos[0][0] = Point(i,100);
        // puntos[0][1] = Point(i,topLeft);
        // puntos[0][2] = Point(i+1,topRight);
        // puntos[0][3] = Point(i+1,100);
        // const Point *ppt[1] = {points[0]};
        // if(i>=rango[0] && i<=rango[1])
        // {
        //     fillPoly(destImage,ppt,4,1,color,8,0,Point());
        // }
    }
}

void clearArray(int *datos)
{
    for(int i = 0; i <= 255; i++)
        datos[i] = 0;
}
// void flipImageBasic(const Mat &sourceImage, Mat &destinationImage)
// {
// }

/* This is the callback that will only display mouse coordinates */
void mouseCoordinatesExampleCallback(int event, int x, int y, int flags, void* param);
    Mat histoMatRojo = Mat(120, 256, CV_8UC1);
    Mat histoMatVerde = Mat(120, 256, CV_8UC1);
    Mat histoMatAzul = Mat(120, 256, CV_8UC1);
int main(int argc, char *argv[])
{
    /* First, open camera device */
    VideoCapture camera;
    camera.open(0);

    /* Create images where captured and transformed frames are going to be stored */
    Mat currentImage;

    /* Create main OpenCV window to attach callbacks */
    namedWindow("Image");
    namedWindow("Result");
    namedWindow("Histo Rojo");
    namedWindow("Histo Verde");
    namedWindow("Histo Azul");

    /*
    namedWindow("R");
    namedWindow("G");
    namedWindow("B");
    */
    setMouseCallback("Image", mouseCoordinatesExampleCallback);

     

    while (true)
    {
        /* Obtain a new frame from camera */
        camera >> currentImage;
        clearArray(histRojo);
        clearArray(histAzul);
        clearArray(histVerde);
        histoMatRojo = Mat(120, 256, CV_8UC3,Scalar(0,0,0));
        histoMatVerde = Mat(120, 256, CV_8UC3,Scalar(0,0,0));
        histoMatAzul = Mat(120, 256, CV_8UC3,Scalar(0,0,0));
        calcHistRGB(stillImage,histRojo,histVerde,histAzul);
        graphHist(histoMatRojo,histRojo, Scalar(0,0,255));
        graphHist(histoMatVerde,histVerde, Scalar(0,255,0));
        graphHist(histoMatAzul,histAzul, Scalar(255,0,0));

        graphVerticalLine(histoMatRojo,histRojo,mouseR);
        graphVerticalLine(histoMatVerde,histVerde,mouseG);
        graphVerticalLine(histoMatAzul,histAzul,mouseB);

        graphVerticalLine(histoMatRojo,histRojo,umbralRojo[0]);
        graphVerticalLine(histoMatVerde,histVerde,umbralVerde[0]);
        graphVerticalLine(histoMatAzul,histAzul,umbralAzul[0]);

        graphVerticalLine(histoMatRojo,histRojo,umbralRojo[1]);
        graphVerticalLine(histoMatVerde,histVerde,umbralVerde[1]);
        graphVerticalLine(histoMatAzul,histAzul,umbralAzul[1]);
        
        char c = cvWaitKey(33);
        //cout<<c;
        if(c == 32)
        {
            cout<<"Imagen capturada"<<endl;
            stillImage = currentImage.clone();
            video = false;

            /* Calcular Histogramas para cada canal */
            int bins[] = {256};
            int channels[] = {0,1,2};
            float rango[] = {0, 255};
            const float *rangos[] = {rango};
            // calcHist(
            //     &stillImage   //Imagen a utilizar para el histograma
            //     ,1              //# de imagenes
            //     ,channels       //Canales a utilizar
            //     ,Mat()
            //     ,hist           //Resultado
            //     ,1              //Dimension del
            //     ,bins           //Cantidad de bins
            //     ,rangos          //Rango
            //     ,true
            //     ,false
            //     ); 

        }
        else if(c == 'R')
        {
            frontera++;
            cout << frontera<<endl;
        }
        else if(c == 'T')
        {
            frontera--;
            cout << frontera<<endl;
        }

        if (currentImage.data) 
        {
            /* Draw all points */
            if(points.size()>0)
                for (int i = 0; i < (points.size()-1); ++i) {
                    circle(currentImage, (Point)points[i], 5, Scalar( 0, 0, 255 ), CV_FILLED);
                    if(points.size()>1)
                        line(currentImage,(Point)points[i],(Point)points[i+1],Scalar( 255, 0,  0),2,8);
                }

            /* Show image */
            if(video)
                imshow("Image", currentImage);
            else
            {
                imshow("Image", stillImage);
                imshow("Result", resultImage);
            }
            imshow("Histo Rojo", histoMatRojo);
            imshow("Histo Verde", histoMatVerde);
            imshow("Histo Azul", histoMatAzul);
            /*
            imshow("R",getChannel(currentImage,2));
            imshow("G",getChannel(currentImage,1));
            imshow("B",getChannel(currentImage,0));
            */
            /* If 'x' is pressed, exit program */
            if (waitKey(3) == 'x')
                break;
        }
        else
        {
            cout << "No image data.. " << endl;
        }
        cout.flush();
        histoMatRojo.release();
        histoMatVerde.release();
        histoMatAzul.release();
    }
}

Mat filtrarImg(Mat sourceImage)
{
    Mat destinationImage = Mat(sourceImage.rows, sourceImage.cols, CV_8UC3);
    for (int y = 0; y < sourceImage.rows; y++)
        for (int x = 0; x < sourceImage.cols; x++)
        {
            int rojo = sourceImage.at<Vec3b>(y,x)[2];
            int verde = sourceImage.at<Vec3b>(y,x)[1];
            int azul = sourceImage.at<Vec3b>(y,x)[0];
            if((rojo>=umbralRojo[0] && rojo<= umbralRojo[1])&&
                (verde>=umbralVerde[0] && verde <= umbralVerde[1])&&
                (azul>=umbralAzul[0]&&azul<=umbralAzul[1]))
                    destinationImage.at<Vec3b>(y,x) = sourceImage.at<Vec3b>(y,x);
                else
                    destinationImage.at<Vec3b>(y,x) = {255,255,255};
        }
    return destinationImage;
}

void colorClick(int x, int y)
{
    //Sacar el valor en ese punto
    if(firstClick)
    {
        umbralRojo[0] = stillImage.at<Vec3b>(y,x)[2];
        line(histoMatRojo,Point(x,100), Point(x,100-histRojo[x]/160),Scalar(0,0,255),2,8);
        umbralVerde[0] = stillImage.at<Vec3b>(y,x)[1];
        umbralAzul[0] = stillImage.at<Vec3b>(y,x)[0];
        firstClick = false;
    }
    else
    {
     umbralRojo[1] = stillImage.at<Vec3b>(y,x)[2];
     umbralVerde[1] = stillImage.at<Vec3b>(y,x)[1];
     umbralAzul[1] = stillImage.at<Vec3b>(y,x)[0];
     firstClick = true;
     resultImage = filtrarImg(stillImage);
     fillHist(histoMatRojo,histRojo,Scalar(0,0,255),umbralRojo);
    }
}


void mouseCoordinatesExampleCallback(int event, int x, int y, int flags, void* param)
{
    switch (event)
    {
        case CV_EVENT_LBUTTONDOWN:
            cout << "  Mouse X, Y: " << x << ", " << y ;
            cout << endl;
            cout.flush();
            /*  Draw a point */
            points.push_back(Point(x, y));
            colorClick(x,y);
            break;
        case CV_EVENT_MOUSEMOVE:
            mouseX = x;
            mouseY = y;
            if(!video)
            {
                mouseR = stillImage.at<Vec3b>(y,x)[2];
                mouseG = stillImage.at<Vec3b>(y,x)[1];
                mouseB = stillImage.at<Vec3b>(y,x)[0];
            }
            break;
        case CV_EVENT_LBUTTONUP:
            break;
    }
}