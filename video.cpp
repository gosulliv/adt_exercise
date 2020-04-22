#include "video.h"
//Chris Lu,
//CS 163
//Project #1
//Video.h
//The code will manage a video class which allows applications
//to create a video, add a new video, display all video contents,
//and display video name.  The functions written here are intended to be used

//this is the video constructor
video::video() //initializes values blank
{
	timeStamp = 0; 
	videoName = NULL;
	teacher = NULL;
	topic = NULL;
	length = 0;
}

//Video destructor first checks the existence of char array members before deleting, setting other values to 0 
video::~video()
{
	//set all members to null or zero
	if(videoName)
		delete [] videoName;
	if(teacher)
		delete [] teacher;
	if(topic)
		delete [] topic;
	videoName = teacher = topic = NULL;
	timeStamp = length = 0;
}

//compareTime compares the integer values of its timeStamp and the arguements.  Returns 1 if arguement is greater
int video::compareTime(const video & querent)
{
	if(this->timeStamp < querent.timeStamp)
	{
		return 1;
	}
	return 0;
}

//compareVideo uses strcmp to evaluate whether their names are the same. Returns 0 on match.
int video::compareVideo(const video & querent)
{
	if(strcmp(this->videoName, querent.videoName) == 0)
	{
		return 1;
	}
	return 0;
}

//This version is identical to the above, except it takes a char string as an arguement
int video::compareVideo(char * videoName)
{
	if(strcmp(this->videoName, videoName) == 0)
	{ 
		return 1;
	}
	return 0;
}

//add checks if the arguements exist, then copy them into char strings or ints.  Those copies assigned to the class' member values
int video::add(int timeStamp_toadd, char videoName_toadd[], char teacher_toadd[], char topic_toadd[], int length_toadd)
{
	if(!videoName_toadd || !teacher_toadd || !topic_toadd) return 0; //RETURNING ZERO FOR FAILURE IN THIS CASE
	videoName = new char[strlen(videoName_toadd) + 1]; 
		strcpy(videoName, videoName_toadd); 
	teacher = new char[strlen(teacher_toadd) + 1]; strcpy(teacher, teacher_toadd);
	topic = new char[strlen(topic_toadd) + 1];
		strcpy(topic, topic_toadd); 
	timeStamp = timeStamp_toadd;
	length = length_toadd; 
	return 1;
}

//displayAll_Devices couts each of devLists's node values.
int video::displayAll_Devices() //print videodevices
{
	devList.displayAll(); //This iterates through devList's nodes, display each one's data.
	return 1;
}

//checks if the all of video's member values are valid, then couts them.
int video::display()
{
	if((!videoName && !topic && !teacher) && (0 == length) && (0  == timeStamp)) return 0; //if empty, error!
	else
	{
		std::cout<<std::endl;
		std::cout<<"Video name: " << videoName << std::endl;	
		//print timeStamp
		std::cout<<"TimeStamp: " << timeStamp << std::endl;
		//teacher
		std::cout<<"Teacher: " << teacher << std::endl;
		//topic
		std::cout<<"Topic: " << topic << std::endl;
		//length
		std::cout<<"Length: " << length << std::endl;
	}
	return 1;
}

//addDevice is a wrapper function for devList's add.
int video::addDevice(char * deviceName_toAdd) //this version takes char arrays.
{
	devList.add(deviceName_toAdd);//this add as an iterative linear linked list positional insertion.
	return 1;
}

//identical wrapper as above, only takes a device class.
int video::addDevice(const device & new_device_toadd)
{
	devList.add(new_device_toadd);
	return 1;
}

//removeDevice is a wrapper function that calls deviceLists's remove device function.
int video::removeDevice(const device & target_device) //this version takes a device class
{
	devList.remove(target_device); //This is an iterative positional removal in a linked list.
	return 1;	
}

int video::removeDevice(char * deviceName) //This version takes character arrays instead.
{
	devList.remove(deviceName);
	return 1;
}
