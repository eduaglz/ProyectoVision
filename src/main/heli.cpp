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
#include <math.h>

#include "CHeli.h"


using namespace cv;
using namespace std;

CRawImage *image;
CHeli *heli;

bool video = true;
int width = 320;
int height = 240;

Mat bigImage;
Mat stillImage;
Mat resultImage = Mat(height, width, CV_8UC3, Scalar(0,0,0));
Mat imgHSV;
Mat imgYIQ;
Mat grayScale;

Mat resultHSV = Mat(height, width, CV_8UC3, Scalar(0,0,0));
Mat resultYIQ = Mat(height, width, CV_8UC3, Scalar(0,0,0));

Scalar lineColors[3] = {Scalar(0,0,255),Scalar(0,255,0),Scalar(255,0,0)};
Scalar minRGB;
Scalar maxRGB;
Scalar minHSV;
Scalar maxHSV;
Scalar minYIQ;
Scalar maxYIQ;

int mouseX = 0;
int mouseY = 0;

uchar mouseRGB[3] = {0,0,0};
int histRGB[3][256];
int umbralesRGB[3][2] = {{0,255},{0,255},{0,255}};
Mat histoMatRGB[3] = { Mat(120, 256, CV_8UC1),Mat(120, 256, CV_8UC1),Mat(120, 256, CV_8UC1)};

uchar mouseYIQ[3] = {0,0,0};
int histYIQ[3][256];
int umbralesYIQ[3][2] = {{0,255},{0,255},{0,255}};
Mat histoMatYIQ[3] = { Mat(120, 256, CV_8UC1),Mat(120, 256, CV_8UC1),Mat(120, 256, CV_8UC1)};

uchar mouseHSV[3] = {0,0,0};
int histHSV[3][256];
int umbralesHSV[3][2] = {{0,255},{0,255},{0,255}};
Mat histoMatHSV[3] = { Mat(120, 256, CV_8UC1),Mat(120, 256, CV_8UC1),Mat(120, 256, CV_8UC1)};



int frontera = 127;

bool firstClick = true;

// Here we will store points
vector<Point> points;

// Convert CRawImage to Mat
void rawToMat( Mat &destImage, CRawImage* sourceImage)
{ 
  uchar *pointerImage = destImage.ptr(0);
    
  for (int i = 0; i < 240*320; i++)
  {
      pointerImage[3*i] = sourceImage->data[3*i+2];
      pointerImage[3*i+1] = sourceImage->data[3*i+1];
      pointerImage[3*i+2] = sourceImage->data[3*i];
  }
}

// Create a HSV image from the RGB image using the full 8-bits, since OpenCV only allows Hues up to 180 instead of 255.
// ref: "http://cs.haifa.ac.il/hagit/courses/ist/Lectures/Demos/ColorApplet2/t_convert.html"
// Remember to free the generated HSV image.
IplImage* convertImageRGBtoHSV(const IplImage *imageRGB)
{
    float fR, fG, fB;
    float fH, fS, fV;
    const float FLOAT_TO_BYTE = 255.0f;
    const float BYTE_TO_FLOAT = 1.0f / FLOAT_TO_BYTE;

    // Create a blank HSV image
    IplImage *imageHSV = cvCreateImage(cvGetSize(imageRGB), 8, 3);
    if (!imageHSV || imageRGB->depth != 8 || imageRGB->nChannels != 3) {
        printf("ERROR in convertImageRGBtoHSV()! Bad input image.\n");
        exit(1);
    }

    int h = imageRGB->height;       // Pixel height.
    int w = imageRGB->width;        // Pixel width.
    int rowSizeRGB = imageRGB->widthStep;   // Size of row in bytes, including extra padding.
    char *imRGB = imageRGB->imageData;  // Pointer to the start of the image pixels.
    int rowSizeHSV = imageHSV->widthStep;   // Size of row in bytes, including extra padding.
    char *imHSV = imageHSV->imageData;  // Pointer to the start of the image pixels.
    for (int y=0; y<h; y++) {
        for (int x=0; x<w; x++) {
            // Get the RGB pixel components. NOTE that OpenCV stores RGB pixels in B,G,R order.
            uchar *pRGB = (uchar*)(imRGB + y*rowSizeRGB + x*3);
            int bB = *(uchar*)(pRGB+0); // Blue component
            int bG = *(uchar*)(pRGB+1); // Green component
            int bR = *(uchar*)(pRGB+2); // Red component

            // Convert from 8-bit integers to floats.
            fR = bR * BYTE_TO_FLOAT;
            fG = bG * BYTE_TO_FLOAT;
            fB = bB * BYTE_TO_FLOAT;

            // Convert from RGB to HSV, using float ranges 0.0 to 1.0.
            float fDelta;
            float fMin, fMax;
            int iMax;
            // Get the min and max, but use integer comparisons for slight speedup.
            if (bB < bG) {
                if (bB < bR) {
                    fMin = fB;
                    if (bR > bG) {
                        iMax = bR;
                        fMax = fR;
                    }
                    else {
                        iMax = bG;
                        fMax = fG;
                    }
                }
                else {
                    fMin = fR;
                    fMax = fG;
                    iMax = bG;
                }
            }
            else {
                if (bG < bR) {
                    fMin = fG;
                    if (bB > bR) {
                        fMax = fB;
                        iMax = bB;
                    }
                    else {
                        fMax = fR;
                        iMax = bR;
                    }
                }
                else {
                    fMin = fR;
                    fMax = fB;
                    iMax = bB;
                }
            }
            fDelta = fMax - fMin;
            fV = fMax;              // Value (Brightness).
            if (iMax != 0) {            // Make sure it's not pure black.
                fS = fDelta / fMax;     // Saturation.
                float ANGLE_TO_UNIT = 1.0f / (6.0f * fDelta);   // Make the Hues between 0.0 to 1.0 instead of 6.0
                if (iMax == bR) {       // between yellow and magenta.
                    fH = (fG - fB) * ANGLE_TO_UNIT;
                }
                else if (iMax == bG) {      // between cyan and yellow.
                    fH = (2.0f/6.0f) + ( fB - fR ) * ANGLE_TO_UNIT;
                }
                else {              // between magenta and cyan.
                    fH = (4.0f/6.0f) + ( fR - fG ) * ANGLE_TO_UNIT;
                }
                // Wrap outlier Hues around the circle.
                if (fH < 0.0f)
                    fH += 1.0f;
                if (fH >= 1.0f)
                    fH -= 1.0f;
            }
            else {
                // color is pure Black.
                fS = 0;
                fH = 0; // undefined hue
            }

            // Convert from floats to 8-bit integers.
            int bH = (int)(0.5f + fH * 255.0f);
            int bS = (int)(0.5f + fS * 255.0f);
            int bV = (int)(0.5f + fV * 255.0f);

            // Clip the values to make sure it fits within the 8bits.
            if (bH > 255)
                bH = 255;
            if (bH < 0)
                bH = 0;
            if (bS > 255)
                bS = 255;
            if (bS < 0)
                bS = 0;
            if (bV > 255)
                bV = 255;
            if (bV < 0)
                bV = 0;

            // Set the HSV pixel components.
            uchar *pHSV = (uchar*)(imHSV + y*rowSizeHSV + x*3);
            *(pHSV+0) = bH;     // H component
            *(pHSV+1) = bS;     // S component
            *(pHSV+2) = bV;     // V component
        }
    }
    return imageHSV;
}

void convertPixelRGBtoYIQ(Mat &sourceImage, int x, int y, float *destArray)
{
    float fR, fG, fB;
    float fY, fI, fQ;
    const float FLOAT_TO_BYTE = 255.0f;
    const float BYTE_TO_FLOAT = 1.0f / FLOAT_TO_BYTE;

     // Get the RGB pixel components. NOTE that OpenCV stores RGB pixels in B,G,R order.
    Vec3b RGB = sourceImage.at<Vec3b>(y,x);
    int bB = RGB[0]; // Blue component
    int bG = RGB[1]; // Green component
    int bR = RGB[2]; // Red component

    // Convert from 8-bit integers to floats
    fR = bR * BYTE_TO_FLOAT;
    fG = bG * BYTE_TO_FLOAT;
    fB = bB * BYTE_TO_FLOAT;
    // Convert from RGB to YIQ,
    // where R,G,B are 0-1, Y is 0-1, I is -0.5957 to +0.5957, Q is -0.5226 to +0.5226.
    fY =    0.299 * fR +    0.587 * fG +    0.114 * fB;
    fI = 0.595716 * fR - 0.274453 * fG - 0.321263 * fB;
    fQ = 0.211456 * fR - 0.522591 * fG + 0.311135 * fB;

    *destArray = fY;
    *(destArray + 1) = fI;
    *(destArray + 2) = fQ;
}

// Create a YIQ image from the RGB image using an approximation of NTSC conversion(ref: "YIQ" Wikipedia page).
// Remember to free the generated YIQ image.
IplImage* convertImageRGBtoYIQ(const IplImage *imageRGB)
{
    float fR, fG, fB;
    float fY, fI, fQ;
    const float FLOAT_TO_BYTE = 255.0f;
    const float BYTE_TO_FLOAT = 1.0f / FLOAT_TO_BYTE;
    const float MIN_I = -0.5957f;
    const float MIN_Q = -0.5226f;
    const float Y_TO_BYTE = 255.0f;
    const float I_TO_BYTE = 255.0f / (MIN_I * -2.0f);
    const float Q_TO_BYTE = 255.0f / (MIN_Q * -2.0f);

    // Create a blank YIQ image
    IplImage *imageYIQ = cvCreateImage(cvGetSize(imageRGB), 8, 3);
    if (!imageYIQ || imageRGB->depth != 8 || imageRGB->nChannels != 3) {
        printf("ERROR in convertImageRGBtoYIQ()! Bad input image.\n");
        exit(1);
    }

    int h = imageRGB->height;           // Pixel height
    int w = imageRGB->width;            // Pixel width
    int rowSizeRGB = imageRGB->widthStep;       // Size of row in bytes, including extra padding.
    char *imRGB = imageRGB->imageData;      // Pointer to the start of the image pixels.
    int rowSizeYIQ = imageYIQ->widthStep;       // Size of row in bytes, including extra padding.
    char *imYIQ = imageYIQ->imageData;      // Pointer to the start of the image pixels.
    for (int y=0; y<h; y++) {
        for (int x=0; x<w; x++) {
            // Get the RGB pixel components. NOTE that OpenCV stores RGB pixels in B,G,R order.
            uchar *pRGB = (uchar*)(imRGB + y*rowSizeRGB + x*3);
            int bB = *(uchar*)(pRGB+0); // Blue component
            int bG = *(uchar*)(pRGB+1); // Green component
            int bR = *(uchar*)(pRGB+2); // Red component

            // Convert from 8-bit integers to floats
            fR = bR * BYTE_TO_FLOAT;
            fG = bG * BYTE_TO_FLOAT;
            fB = bB * BYTE_TO_FLOAT;
            // Convert from RGB to YIQ,
            // where R,G,B are 0-1, Y is 0-1, I is -0.5957 to +0.5957, Q is -0.5226 to +0.5226.
            fY =    0.299 * fR +    0.587 * fG +    0.114 * fB;
            fI = 0.595716 * fR - 0.274453 * fG - 0.321263 * fB;
            fQ = 0.211456 * fR - 0.522591 * fG + 0.311135 * fB;
            // Convert from floats to 8-bit integers
            int bY = (int)(0.5f + fY * Y_TO_BYTE);
            int bI = (int)(0.5f + (fI - MIN_I) * I_TO_BYTE);
            int bQ = (int)(0.5f + (fQ - MIN_Q) * Q_TO_BYTE);

            // Clip the values to make sure it fits within the 8bits.
            if (bY > 255)
                bY = 255;
            if (bY < 0)
                bY = 0;
            if (bI > 255)
                bI = 255;
            if (bI < 0)
                bI = 0;
            if (bQ > 255)
                bQ = 255;
            if (bQ < 0)
                bQ = 0;

            // Set the YIQ pixel components
            uchar *pYIQ = (uchar*)(imYIQ + y*rowSizeYIQ + x*3);
            *(pYIQ+0) = bY;     // Y component
            *(pYIQ+1) = bI;     // I component
            *(pYIQ+2) = bQ;     // Q component
        }
    }
    return imageYIQ;
}


void generateColorMat(Mat destImage, Scalar color)
{
    int counter = 0;
    int col = 0;
    for(int x = 0; x < 320; x++)
    {
        for(int y = 0; y < 240; y++)
        {
            if(counter > col)
            {
                col++;
                counter = 0;
            }


            destImage.at<Vec3b>(y,x) = Vec3b(0,col,col);
            counter++;
            if(col == 255 && counter == 255)
            {
                col = 0;
                counter = 0;
            }
            // float col = y/240.0;
            // int sector = floor(y/60.0);
            // switch(sector)
            // {
            //     case 0:
            //     destImage.at<Vec3b>(y,x) = Vec3b(0,0,255*col);
            //     break;
            //     case 1:
            //     destImage.at<Vec3b>(y,x) = Vec3b(0,255*col,0);
            //     break;
            //     case 2:
            //     destImage.at<Vec3b>(y,x) = Vec3b(255*col,0,0);
            //     break;
            // }
            //destImage.at<Vec3b>(y,x) = Vec3b(0,255*col,255*col);
        }
    }
}


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
            destinationImage.at<uchar>(y,x) = gray;
            //destinationImage.at<uchar>(y,x) = gray > frontera ? 0 : 255;
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
    int r = 255;
    int g = 0;
    int b = 0;
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

// void colorBand(Mat destImage)
// {
//     int h = 0;
//     int s = 255;
//     int v = 255;

//     Mat tmp = destImage.clone();
//     for(int x = 0; x< 256;x++)
//     {
//         h++;
//         for(int y=101;y<120;y++)
//         {
//             tmp.at<Vec3b>(y,x)[0]=h;
//             tmp.at<Vec3b>(y,x)[1]=s;
//             tmp.at<Vec3b>(y,x)[2]=v;
//         }
//     }
//     cvtColor(tmp,destImage, CV_HSV2RGB);
// }

void graphHist(Mat destImage, int *datos,Scalar color)
{
    float max = 0.0;
    for(int i =0; i<256; i++)
    {
        if(datos[i]>max)
            max = datos[i];
    }
    for (int i = 0; i < 255; ++i) {
        Point topLeft = Point(i,100-((datos[i]/max)*100)); 
        Point topRight = Point(i+1,100-((datos[i+1]/max)*100));
        line(destImage, topLeft, topRight,color,2,8);
    }
    colorBand(destImage);
}

void graphVerticalLine(Mat destImage, int *datos, int x, Scalar color)
{
    float max = 0.0;
    for(int i =0; i<256; i++)
    {
        if(datos[i]>max)
            max = datos[i];
    }
    Point topLeft = Point(x,100-((datos[x]/max)*100)); 
    Point topRight = Point(x,100);
    line(destImage, topLeft, topRight,color,2,8);
}

void clearArray(int *datos)
{
    for(int i = 0; i <= 255; i++)
        datos[i] = 0;
}

void graphData(Mat sourceImage, int channels, int histogramas[][256], Mat *matHistogramas, Scalar *lineColors, uchar *mouseColorValues, int umbrales[][2])
{
        for(int i = 0; i < channels; i++)
        {
            //cout<<"Borrar Arreglo"<<endl;
            clearArray(histogramas[i]);
            //cout<<"Crear Mat"<<endl;
            matHistogramas[i] = Mat(120,256,CV_8UC3,Scalar(0,0,0));
            //cout<<"calcular histogramas"<<endl;
            calcHistRGB(sourceImage,histogramas[0],histogramas[1],histogramas[2]);
            //cout<<"Graficar histogramas"<<endl;
            graphHist(matHistogramas[i],histogramas[i],lineColors[i]);
            graphVerticalLine(matHistogramas[i],histogramas[i],mouseColorValues[i],Scalar(0,255,255));
            graphVerticalLine(matHistogramas[i],histogramas[i],umbrales[i][0],Scalar(255,0,255));
            graphVerticalLine(matHistogramas[i],histogramas[i],umbrales[i][1],Scalar(255,255,0));
        }
}

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

     //establishing connection with the quadcopter
     heli = new CHeli();
        
     //this class holds the image from the drone 
     image = new CRawImage(320,240);

    /* Create images where captured and transformed frames are going to be stored */
    Mat currentImage = Mat(240,320,CV_8UC3,Scalar(0,0,0));

    /* Create main OpenCV window to attach callbacks */
    namedWindow("Image");
    moveWindow("Image",0,0);

    namedWindow("Result");
    moveWindow("Result",320,0);

    namedWindow("Histo Rojo");
    moveWindow("Histo Rojo",0,530);

    namedWindow("Histo Verde");
    moveWindow("Histo Verde",0,680);

    namedWindow("Histo Azul");
    moveWindow("Histo Azul",0,900);

    IplImage *tmp;
    IplImage *imageHSV;
    IplImage *imageYIQ;
    namedWindow("HSV");
    moveWindow("HSV",640,0);

    namedWindow("Result HSV");
    moveWindow("Result HSV",960,0);


    namedWindow("Histo H");
    moveWindow("Histo H",640,530);

    namedWindow("Histo S");
    moveWindow("Histo S",640,680);

    namedWindow("Histo V");
    moveWindow("Histo V",640,900);

    namedWindow("YIQ");
    moveWindow("YIQ",1280,0);

    namedWindow("Result YIQ");
    moveWindow("Result YIQ",1600,0);

    namedWindow("Histo Y");
    moveWindow("Histo Y",1280,530);

    namedWindow("Histo I");
    moveWindow("Histo I",1280,680);

    namedWindow("Histo Q");
    moveWindow("Histo Q",1280,900);

    setMouseCallback("Image", mouseCoordinatesExampleCallback);

     

    while (true)
    {
        /* Obtain a new frame from camera */
        camera >> bigImage;
        //bigImage = imRead
        resize(bigImage,currentImage,Size(width,height));
        //currentImage = Mat(height, width, CV_8UC3, Scalar(0,0,0));
        //generateColorMat(currentImage,Scalar(0,0,255));

         //image is captured
        //heli->renewImage(image);
        // Copy to OpenCV Mat
        //rawToMat(currentImage, image);
        grayScale = getGrayScale(currentImage);
        if(video)
        {

            tmp = new IplImage(currentImage);
            cvtColor(currentImage,imgHSV, CV_BGR2HSV);
        }
        else
        {
            tmp = new IplImage(stillImage);
            cvtColor(stillImage,imgHSV, CV_BGR2HSV);
        }
        //imageHSV = cvtColor(stillImage);//convertImageRGBtoHSV(tmp);
        imageYIQ = convertImageRGBtoYIQ(tmp);
        //imgHSV = Mat(imageHSV);
        imgYIQ = Mat(imageYIQ);
        graphData(stillImage, 3, histRGB, histoMatRGB, lineColors, mouseRGB, umbralesRGB);
        graphData(imgYIQ, 3, histYIQ, histoMatYIQ, lineColors, mouseYIQ, umbralesYIQ);
        graphData(imgHSV, 3, histHSV, histoMatHSV, lineColors, mouseHSV, umbralesHSV);


        char c = cvWaitKey(33);
        if(c == 32)
        {
            cout<<"Imagen capturada"<<endl;
            stillImage = currentImage.clone();
            video = false;
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
                for (uint i = 0; i < (points.size()-1); ++i) {
                    circle(currentImage, (Point)points[i], 5, Scalar( 0, 0, 255 ), CV_FILLED);
                    if(points.size()>1)
                        line(currentImage,(Point)points[i],(Point)points[i+1],Scalar( 255, 0,  0),2,8);
                }

            /* Show image */
            if(video)
            {
                imshow("Image", currentImage);
            }
            else
            {
                imshow("Image", stillImage);
                imshow("Result", resultImage);
                imshow("Result YIQ", resultYIQ);
                imshow("Result HSV", resultHSV);
            }
            imshow("Grises", grayScale);
            imshow("Histo Rojo", histoMatRGB[0]);
            imshow("Histo Verde", histoMatRGB[1]);
            imshow("Histo Azul", histoMatRGB[2]);

            imshow("Histo H", histoMatHSV[0]);
            imshow("Histo S", histoMatHSV[1]);
            imshow("Histo V", histoMatHSV[2]);

            imshow("Histo Y", histoMatYIQ[0]);
            imshow("Histo I", histoMatYIQ[1]);
            imshow("Histo Q", histoMatYIQ[2]);

            imshow("HSV", imgHSV);
            imshow("YIQ", imgYIQ);

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
        //cvReleaseImage(&imageHSV);
        //cvReleaseImage(&imageYIQ);
        delete tmp;
    }
}

Mat filtrarImg(Mat sourceImage, int umbrales[][2])
{
    Mat destinationImage = Mat(sourceImage.rows, sourceImage.cols, CV_8UC3);
    for (int y = 0; y < sourceImage.rows; y++)
        for (int x = 0; x < sourceImage.cols; x++)
        {
            int rojo = sourceImage.at<Vec3b>(y,x)[2];
            int verde = sourceImage.at<Vec3b>(y,x)[1];
            int azul = sourceImage.at<Vec3b>(y,x)[0];
            if((
                rojo>=umbrales[0][0] && 
                rojo<= umbrales[0][1])&&
                (verde>=umbrales[1][0] && 
                verde <= umbrales[1][1])&&
                (azul>=umbrales[2][0]&&
                azul<=umbrales[2][1]))
                    destinationImage.at<Vec3b>(y,x) = sourceImage.at<Vec3b>(y,x);
                else
                    destinationImage.at<Vec3b>(y,x) = Vec3b(255,255,255);
        }
    return destinationImage;
}
void setRango(int *valores, int nuevoValor)
{
    if(nuevoValor < valores[0])
    {
        valores[1] = valores[0];
        valores[0] = nuevoValor;
    }
    else
    {
        valores[1] = nuevoValor;
    }
}

void colorClick(int x, int y)
{
    //Sacar el valor en ese punto
    if(firstClick)
    {
        minRGB = Scalar(stillImage.at<Vec3b>(y,x)[2],stillImage.at<Vec3b>(y,x)[1],stillImage.at<Vec3b>(y,x)[0]);
        minHSV = Scalar(imgHSV.at<Vec3b>(y,x)[0],imgHSV.at<Vec3b>(y,x)[1],imgHSV.at<Vec3b>(y,x)[2]);
        minYIQ = Scalar(imgYIQ.at<Vec3b>(y,x)[0],imgYIQ.at<Vec3b>(y,x)[1],imgYIQ.at<Vec3b>(y,x)[2]);
        umbralesRGB[0][0] = stillImage.at<Vec3b>(y,x)[2];
        umbralesRGB[1][0] = stillImage.at<Vec3b>(y,x)[1];
        umbralesRGB[2][0] = stillImage.at<Vec3b>(y,x)[0];

        umbralesHSV[0][0] = imgHSV.at<Vec3b>(y,x)[0];
        umbralesHSV[1][0] = imgHSV.at<Vec3b>(y,x)[1];
        umbralesHSV[2][0] = imgHSV.at<Vec3b>(y,x)[2];

        umbralesYIQ[0][0] = imgYIQ.at<Vec3b>(y,x)[0];
        umbralesYIQ[1][0] = imgYIQ.at<Vec3b>(y,x)[1];
        umbralesYIQ[2][0] = imgYIQ.at<Vec3b>(y,x)[2];
        firstClick = false;
    }
    else
    {
        // if(stillImage.at<Vec3b>(y,x)[2] < ubralesRGB[0][1])
        // {
        //     ubralesRGB[0][1] = ubralesRGB[0][0]
        //     ubralesRGB[0][1] = stillImage.at<Vec3b>(y,x)[2];
        // }
        // else
        // {
        //     ubralesRGB[0][1] = stillImage.at<Vec3b>(y,x)[2];
        // }
        setRango(umbralesRGB[0],stillImage.at<Vec3b>(y,x)[2]);
        setRango(umbralesRGB[1],stillImage.at<Vec3b>(y,x)[1]);
        setRango(umbralesRGB[2],stillImage.at<Vec3b>(y,x)[0]);
        // umbralesRGB[1][1] = stillImage.at<Vec3b>(y,x)[1];
        // umbralesRGB[2][1] = stillImage.at<Vec3b>(y,x)[0];

        setRango(umbralesHSV[2],imgHSV.at<Vec3b>(y,x)[2]);
        setRango(umbralesHSV[1],imgHSV.at<Vec3b>(y,x)[1]);
        setRango(umbralesHSV[0],imgHSV.at<Vec3b>(y,x)[0]);

        // umbralesHSV[0][1] = stillImage.at<Vec3b>(y,x)[2];
        // umbralesHSV[1][1] = stillImage.at<Vec3b>(y,x)[1];
        // umbralesHSV[2][1] = stillImage.at<Vec3b>(y,x)[0];

        setRango(umbralesYIQ[0],imgYIQ.at<Vec3b>(y,x)[0]);
        setRango(umbralesYIQ[1],imgYIQ.at<Vec3b>(y,x)[1]);
        setRango(umbralesYIQ[2],imgYIQ.at<Vec3b>(y,x)[2]);

        // umbralesYIQ[0][1] = stillImage.at<Vec3b>(y,x)[2];
        // umbralesYIQ[1][1] = stillImage.at<Vec3b>(y,x)[1];
        // umbralesYIQ[2][1] = stillImage.at<Vec3b>(y,x)[0];
        firstClick = true;
        //resultImage = filtrarImg(stillImage,umbralesRGB);

        minRGB = Scalar(umbralesRGB[2][0], umbralesRGB[1][0], umbralesRGB[0][0]);
        minHSV = Scalar(umbralesHSV[0][0], umbralesHSV[1][0], umbralesHSV[2][0]);
        minYIQ = Scalar(umbralesYIQ[0][0], umbralesYIQ[1][0], umbralesYIQ[2][0]);

        maxRGB = Scalar(umbralesRGB[2][1], umbralesRGB[1][1], umbralesRGB[0][1]);
        maxHSV = Scalar(umbralesHSV[0][1], umbralesHSV[1][1], umbralesHSV[2][1]);
        maxYIQ = Scalar(umbralesYIQ[0][1], umbralesYIQ[1][1], umbralesYIQ[2][1]);
        cout << "RGB Max" << maxRGB << " Min " << minRGB << endl;
        inRange(stillImage,minRGB,maxRGB,resultImage);
        //resultYIQ = filtrarImg(imgYIQ,umbralesYIQ);

        inRange(imgYIQ,minYIQ,maxYIQ,resultYIQ);
        //resultHSV = filtrarImg(imgHSV,umbralesHSV);
        cout << "HSV Max" << maxHSV << " Min " << minHSV << endl;
        inRange(imgHSV,minHSV,maxHSV,resultHSV);
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
                mouseRGB[0] = stillImage.at<Vec3b>(y,x)[2];
                mouseRGB[1] = stillImage.at<Vec3b>(y,x)[1];
                mouseRGB[2] = stillImage.at<Vec3b>(y,x)[0];

                mouseHSV[0] = imgHSV.at<Vec3b>(y,x)[2];
                mouseHSV[1] = imgHSV.at<Vec3b>(y,x)[1];
                mouseHSV[2] = imgHSV.at<Vec3b>(y,x)[0];

                mouseYIQ[0] = imgYIQ.at<Vec3b>(y,x)[2];
                mouseYIQ[1] = imgYIQ.at<Vec3b>(y,x)[1];
                mouseYIQ[2] = imgYIQ.at<Vec3b>(y,x)[0];
            }
            break;
        case CV_EVENT_LBUTTONUP:
            break;
    }
}