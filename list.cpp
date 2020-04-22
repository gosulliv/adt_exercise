#include "list.h"
//Chris Lu
//cs 163
//project #1
//list.cpp
//This code is the implementation of my user interface class list. This file
//contains the implementation of the functions necessary for create and delete
//for both videos and their respective video device lists

//This constructuro initializes it's only member, a head node to NUll(empty).
list::list()
{
	head = NULL;
}

//This destructor checks if the list exists, then iterates through and deletes every node.
list::~list()
{
	if(this->head != NULL)
	{
		node * curr = head;
		node * next = NULL;
		while(curr != NULL)
		{
			next = curr->next;
			delete curr;
			curr = next;
		}
	}
}

//addDevice searches for a matching video and calls on a wrapper function in device to add a device
int list::addDevice(char * deviceName_toAdd, char * videoName) //This one takes a char array!
{
	node * curr = head;
	while(curr)
	{
		if(curr->a_video.compareVideo(videoName)) //matches via string comparison
		{
			curr->a_video.addDevice(deviceName_toAdd); //a wrapper function for device's addDevice
		}
		curr = curr->next;
	}	
	return 1;
}

//addDevice iterates through its list to find a matching video, then calls calls device's addDevice
int list::addDevice(const device & target_device, char * videoName) //This one takes a device class
{
	node * curr = head;		//See the function above for comments
	while(curr)
	{
		if(curr->a_video.compareVideo(videoName))
		{
				curr->a_video.addDevice(target_device);
		}
		curr = curr->next;
	}
	return 1;
}

//This function iterates through its list until it finds a matching video, then calls device's functions
int list::removeDevice(device & target_device, char * videoName) //this one takes a device class!
{
	node * curr = head;
	while(curr)
	{
		if(curr->a_video.compareVideo(videoName)) //This uses a strcmp between videoNames
		{
			curr->a_video.removeDevice(target_device); //This function actually originates at the devlicelist level
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

//See function above, except this one takes a char array instead of a device class
int list::removeDevice(char * deviceName, char * videoName) //this one takes a char array
{
	node * curr = head;
	while(curr)
	{
		if(curr->a_video.compareVideo(videoName))
		{
			curr->a_video.removeDevice(deviceName);
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

//This function creates a video class with the function's args and puts it in a node, adding it into the list
int list::addVideo(int timeStamp, char videoName[], char teacher[], char topic[], int length)
{
	if(!videoName || !teacher || !topic) return 0;
	node * new_node = new node;
	new_node->a_video.add(timeStamp, videoName, teacher, topic, length); //video's class puts those values into either char strings or ints
	new_node->next = NULL; //readies it for LLL insertion

	//find the right position to add into
	node * curr = head;
	node * prev = NULL;	
	if(!curr) //if the list is empty
	{
		head = new_node;
	}
	else
	{
		while(curr)
		{
			if(curr->a_video.compareTime(new_node->a_video))
			{
				if(prev == NULL)	//If we are at the top of the list
				{
					new_node->next = head;
					head = new_node;
				}
				else				//All other cases
				{
					new_node->next = curr;
					prev->next = new_node;
				}
				return 1;
			}
			prev = curr;	
			curr = curr->next;
		}
	}
	return 1;
}

//This function iterates through the list, calling each video class's display function
int list::displayVideos() 
{
	node * curr = head;
	while(curr)
	{
		curr->a_video.display(); //This function couts a_video's members.
		curr = curr->next;
	}
	return 1;
}

//DisplayDevices iterates through the list until it finds it's matching video and displays it's devlicelist
int list::displayDevices(const video & target_vid)
{
	node * curr = head;
	while(curr)
	{
		if(curr->a_video.compareVideo(target_vid)) //This is done through strcmp of videonames.
		{
			curr->a_video.displayAll_Devices(); //This accesses video's devicelist class and prints each node's contents.
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

//This version of displayDevices takes a char array, but otherwise is identical.
int list::displayDevices(char * videoName)
{
	node * curr = head;
	while(curr)
	{
		if(curr->a_video.compareVideo(videoName)) //CompareVideo is overloaded to char arrays.
		{
			curr->a_video.displayAll_Devices();
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

