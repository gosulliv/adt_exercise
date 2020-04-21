//this is the implementation of video.h 
#include "video.h"
//will likely need device.h for methods

video::video()
{
	timeStamp = 0; //i should use real ts
	videoName = NULL;
	teacher = NULL;
	topic = NULL;
	length = 0;
}

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
	//KILL THE LLL
}

int video::compareTime(const video & querent)
{
	if(this->timeStamp < querent.timeStamp)
	{
		return 1;
	}
	return 0;
}

int video::compareVideo(const video & querent)
{
	if(strcmp(this->videoName, querent.videoName) == 0)
	{
		return 1;
	}
	return 0;
}

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

int video::displayAll_Devices() //print videodevices
{
	devList.displayAll();
	return 1;
}

int video::display()
{
	if((!videoName && !topic && !teacher) && (0 == length) && (0  == timeStamp)) return 0; //if empty, error!
	else
	{
		//I asked a TA about whether I should cout or pass by reference for display, and they mentioned cout was perfectly fine.
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

//Needs device member functions!
int video::addDevice(char * deviceName_toAdd)
{
	devList.add(deviceName_toAdd);	
	return 1;
}

int video::addDevice(const device & new_device_toadd)
{
	devList.add(new_device_toadd);
	return 1;
}

int video::removeDevice(const device & target_device)
{
	devList.remove(target_device);
	return 1;	
}
