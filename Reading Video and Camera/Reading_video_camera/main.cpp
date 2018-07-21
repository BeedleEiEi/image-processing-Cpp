#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//OpenCV Library
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

class ReadingVideoCamera{

public:
    /* This function will read video from input if video is valid,
     * Otherwise This function will call ReadCamera function instead for open camera
     * Expected input <String videoFilePath>
    */

    void ReadVideoCamera(String videoFile){

        //  Define video capture
        VideoCapture videoCapture;

        // Check video file is exist
        if( videoFile != "" ){
            videoCapture.open( videoFile );
        }
        // Open Camera if video file doesn't exist
        else {
            ReadCamera( videoCapture );
        }

    }

private:
    /*  This function will open camera
     *  Expected input <VideoCapture videoCaptureObj>
    */

    int ReadCamera(VideoCapture videoCapture){

        videoCapture.open(0);

        // Check camera status if available
        if( !videoCapture.isOpened() ){
            return -1;
        }

        CreateWindowForReadVideoOrCamera(videoCapture);

        return 0;
    }

private:
    /*  This function will create Window for show video or camera input
     *  Expected input <VideoCapture videoCaptureObjToShow>
    */

    int CreateWindowForReadVideoOrCamera(VideoCapture videoCapture){

        namedWindow( "Video", 1 );
        for(;;){
            Mat frame;
            //Get a new frame from camera
            videoCapture >> frame;
            imshow( "Video", frame );
            //Exit window if user press 'Exit' button
            if( waitKey(30) >= 0 ){
                break;
            }
        }

        //Release camera or video after finished
        videoCapture.release();
        return 0;

    }

};


//Command line Parsergit branch
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

    //Define instance of class
    ReadingVideoCamera readingVideoOrCamera;

    //Use function to read video
    readingVideoOrCamera.ReadVideoCamera(videoFile);


}
