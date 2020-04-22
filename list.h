#include <cstring>
#include <iostream> //do we need forreal?
#include <cstdlib>
#include "video.h"

//Chris Lu
//CS 163
//Project #1
//List.h
//This code exists to manage the list class. This class
//acts as the client-facing interface.  This class houses a linear
//linked list of videos.  Each video node contains it's own list of
//members, including a LLL of devices

struct node
{
	node * next;
	video a_video; //the videoclass houses the add/remove functions this layer draws on
};

class list
{
	public:
		list(); //Constructor initlizes the node completely empty.
		~list(); //deletes the node (which invokes the video destructor.
	
		//addVideo creates a video class with the given arguements, then puts video into a node.
		int addVideo(int timeStamp, char videoName[], char teacher[], char topic[], int length);

		//displayVideos iterates through the list of nodes, displaying each's data.
		int displayVideos();

		//addDevice finds the video by name and puts a device into its devicelist.
		int addDevice(char * deviceName_toAdd, char * videoName); //the char array version
		int addDevice(const device & target_device, char * videoName); //the class version
	
		//removeDevice finds the video by name, then finds the device by name and deletes it.
		int removeDevice(device & target_device, char * videoName); //the device class version
		int removeDevice(char * deviceName, char * videoName); //the char array version

		//diplayDevices iterates through the list, calling the display function of each node. 
		int displayDevices(const video & target_vid); //the class version
		int displayDevices(char * videoName); //the char array version	
		
	
	private:
		node * head; //THis linear linked list is ordered by time value!
};
