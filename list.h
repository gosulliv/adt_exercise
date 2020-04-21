#include <cstring>
//#include <cctype> //what is this?
#include <iostream> //do we need forreal?
#include <cstdlib>
#include "video.h"

//Chris Lu
//This code exists to manage the list class. This class
//acts as the client-facing interface.  This class houses a linear
//linked list of videos.  Each video node contains it's own list of
//members, including a LLL of devices

struct node
{
	node * next;
	video a_video; //use video member methods for access
};

class list //this is where we house and shield the LLL of struct nodes
{
	public:
		list(); //not yet
		~list(); //not yet
		

		int addDevice(const device & target_device); //unwritten
		int removeDevice(const device & target_device);	//unwritten
	
		int createVideo(const video & vid_toAdd); //don't exist
		int insertVideo(const video vid_toAdd); //don't exist
		int addDevice(char * deviceName_toAdd);		//don't exist
		
		int displayDevices(const video & target_vid);
		int displayVideos(); //list all videos in the list	
		int posInsert(int pos, node * target);
		int addVideo(int timeStamp, char videoName[], char teacher[], char topic[], int length);
		//int addVideo(const video & vid_toAdd);	
	
	private:
		node * head;
};
