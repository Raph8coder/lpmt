#include "kinectManager.h"



//---------------------------------------------------------
//This is called in the setup
void kinectManager::setup() {

    // enable depth->rgb image calibration
	kinect.setRegistration(true);

	kinect.init(false,false,true);
	//kinect.init(true); // shows infrared instead of RGB video image
	//kinect.init(false, false); // disable video image (faster fps)
	kinect.open();

	//grayImage.allocate(kinect.width, kinect.height, OF_IMAGE_GRAYSCALE);
	//grayImage.allocate(kinect.width, kinect.height);

}

//---------------------------------------------------------
void kinectManager::update() {

kinect.update();
if(kinect.isFrameNew()) {

		// load grayscale depth image from the kinect source
		//grayImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
		grayImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height, OF_IMAGE_GRAYSCALE, false);

	}

}

//---------------------------------------------------------
void kinectManager::threadedFunction() {

    kinect.update();
    // there is a new frame and we are connected
	if(kinect.isFrameNew()) {

		// load grayscale depth image from the kinect source
		//grayImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
		grayImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height, OF_IMAGE_GRAYSCALE, false);
		grayTexture = kinect.getDepthTextureReference();

	}

	sleep(2000);

}
