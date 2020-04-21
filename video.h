#include <cstring>
//#include <cctype> //what's this for?
#include <iostream>
#include "deviceList.h" //ok think through how you want this to work 
//Chris Lu,
//The code will manage a video class which allows applications
//to create a video, add a new video, display all video contents,
//and display video name.  The functions written here are intended to be used
//within the list class as an interface between the list and core node data

class video
{
	public:
	video(); //default constructor, initializes data members to empty
	~video(); //deallocate any dynamic memory and reset

	int add(int timeStamp, char videoName[], char teacher[], char topic[], int length);
	int display(); //No args
	int displayAll_Devices(); //iterate through the list diplaying stuff
	int addDevice(char * deviceName_toAdd);
	int addDevice(const device & new_device_toadd);
	int removeDevice(const device & target_device);
	int compareVideo(const video & querent);
	private:
		int timeStamp; //we're storing sequentially based on this val
		char * videoName; //dyn arr
		char * teacher; //dynamic arr
		char * topic; //dyn arr
		int length;
		deviceList devList;
};
