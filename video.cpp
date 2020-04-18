//this is the implementation of video.h 
#include "video.h"

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
}

int video::add(int timeStamp_toadd, char videoName_toadd[], char teacher_toadd[], char topic_toadd[], int length_toadd)
{
	if(!videoName_toadd || !teacher_toadd || !topic_toadd) return 0; //RETURNING ZERO FOR FAILURE IN THIS CASE
	videoName = new char[strlen(videoName_toadd) + 1]; 
		strcpy(videoName, videoName_toadd); 
	teacher = new char[strlen(teacher_toadd) + 1]; 
		strcpy(teacher, teacher_toadd);
	topic = new char[strlen(topic_toadd) + 1];
		strcpy(topic, topic_toadd); 
	timeStamp = timeStamp_toadd;
	length = length_toadd; 
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

int video::addDevice(char deviceName_toAdd[])
{
	if(!deviceName_toAdd) return 0;								//guard against bad values
	deviceName = new char[strlen(deviceName_toAdd) + 1];		//put device name into a char array
		strcpy(deviceName, deviceName_toAdd);
	
		
	return 1;
}
