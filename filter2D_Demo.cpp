#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat source, destination; //Creating input and output variables 

    Mat kernel;             //Variables                                 
    Point anchor;
    double delta;
    int d_depth;
    int kernel_size;
    char* window_name = "Filter2D";

    source = imread(argv[1]);     //Taking input 

    if(!source.data)    //Check for data
    {
        cout << "Image not found!!" << endl;
        return -1;
    }

    namedWindow(window_name, CV_WINDOW_AUTOSIZE);    //Creating window

    anchor = Point(-1, -1);
    delta = 0;
    d_depth = -1;                        // desired depth of destination image, -1 implies same depth as source image

    kernel_size = 11;                    //Size of kernal, it can take values also like 3, 5, 7

    kernel = Mat::ones(kernel_size, kernel_size, CV_32F)/(float)(kernel_size*kernel_size);  // Creating kernel

    filter2D(source, destination, d_depth, kernel, anchor, delta, BORDER_DEFAULT);  //function for filterig the image

    imshow(window_name, destination);         //Output

    waitKey(0);    //Wait until a key is pressed

    return 0;
}
