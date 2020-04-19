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
		
		//add a video to the list
		//list all videos in the list
			//int displayAll();	//hopefully ln 26
		//remove a video from the list
	
		//remove a device from a video 
		//add a dvice to :
		//display all devices for a video
	private:
		node * head;
};
