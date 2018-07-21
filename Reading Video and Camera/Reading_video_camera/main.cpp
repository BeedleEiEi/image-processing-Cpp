#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//OpenCV Library
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;


//Command line Parser
const char* params =
{
    "{--help h usage ? | | print this message}"
    "{@video || Video file, if not defined try use webcamera}"
};


int main(int argc, const char** argv)
{
    CommandLineParser parser(argc, argv, params);
    parser.about("Read video and camera");

    //  If requires help
    if ( parser.has( "--help" ) ){

        // will print parser about
        parser.printMessage();
        return 0;
    }
    String videoFile = parser.get<String>(0);

    // Check if params are correctly parsed
    if ( !parser.check() ){

        parser.printErrors();
        return 0;

    }

    //  Define video capture
    VideoCapture videoCapture;

    // Check video file is exist
    if( videoFile != "" ){
        videoCapture.open( videoFile );
    }
    // Open Camera if video file doesn't exist
    else {
        videoCapture.open(0);
    }
    // Check camera status if available
    if( !videoCapture.isOpened() ){
        return -1;
    }

    namedWindow( "Video", 1 );
    for(;;){
        Mat frame;
        //Get a new frame from camera
        videoCapture >> frame;
        imshow( "Video", frame );
        //Break key
        if( waitKey(30) >= 0 ){
            break;
        }
    }
    //Release camera or video after finished
    videoCapture.release();
    return 0;

}
