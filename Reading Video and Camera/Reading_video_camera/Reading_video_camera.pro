TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += C:/OpenCV-3.1.0/opencv/build4qt/install/include

LIBS += -LC:/OpenCV-3.1.0/opencv/build4qt/install/x86/mingw/bin \
        -lopencv_core310 \
        -lopencv_highgui310 \
        -lopencv_imgproc310 \
        -lopencv_imgcodecs310 \
        -lopencv_videoio310 \
        -lopencv_video310 \
        -lopencv_videostab310 \
