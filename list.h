#include <cstring>
//#include <cctype> //what is this?
#include <iostream> //do we need forreal?
#include <cstdlib>
#include "video.h"

//Chris Lu
//This code exists to manage the list class. This class
//acts as the external interface to the

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
		
		//add a video
		//list(video video); //input datatype?
		
		//remove a device from a video
		//display all devices for a video
		//display all videos 
		int displayAll();	
	private:
		node * head;
};
