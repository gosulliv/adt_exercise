#include <iostream>
#include "deviceList.h" //ok think through how you want this to work 
//Chris Lu,
//CS 163
//Project #1
//Video.h
//The code will manage a video class which allows applications
//to create a video, add a new video, display all video contents,
//and display video name.  The functions written here are intended to be used
//within the list class as an interface between the list and core node data

class video
{
	public:
	video(); //default constructor, initializes data members to empty
	~video(); //deallocate any dynamic memory and reset

	//add copies arguement values into ints or chars arrays and stores them into video's members
	int add(int timeStamp, char videoName[], char teacher[], char topic[], int length);
	
	//display couts this class' member values	
	int display();

	//displayAll-Device iterates through each node in devList, printing each one's data members
	int displayAll_Devices();

	//addDevice passes its arguements to devList's add device
	int addDevice(char * deviceName_toAdd); //this version takes chars
	int addDevice(const device & new_device_toadd); //this version takes the device class

	//removeDevice passes it's arguements to devList's delete device functions
	int removeDevice(const device & target_device); //this version takes the device class
	int removeDevice(char * deviceName); //this version takes char arrays
	
	//compareVideo strcmps the videonames and returns 1 for a match, 0 for no
	int compareVideo(const video & querent); //takes a video class
	int compareVideo(char * videoName); // takes a char string
	
	//comparetime compares time value, and returns 1 if the arguement's time value is greater.
	int compareTime(const video & querent);
	
	private:
		int timeStamp; //we're storing sequentially based on this val
		char * videoName; //dyn arr
		char * teacher; //dynamic arr
		char * topic; //dyn arr
		int length;
		deviceList devList; //remove and add device functions are wrappers for this class' members.
};
