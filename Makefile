OPENCV_MODULE=libopencv_core310.dll libopencv_imgcodecs310.dll libopencv_imgproc310.dll libopencv_highgui310.dll
a.exe: main.cpp
	g++ -m32 main.cpp -I . $(OPENCV_MODULE) -s -O2 -DNDEBUG