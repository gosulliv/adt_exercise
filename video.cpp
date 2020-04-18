//this is the implementation of video.h 
#include "video.h"

video::video()
{
	dateAndTimeAdded = 0; //i should use real ts
	videoName = NULL;
	teacher = NULL;
	topic = NULL;
	length = 0;
}

video::~video()
{
	//set all members to null or zero
	if(dateAndTimeAdded) 
		delete [] dateAndTimeAdded;
	if(videoName)
		delete [] videoName;
	if(teacher)
		delete [] teacher;
	if(topic)
		delete [] topic;
	if(length)
		delete [] length;
	videoName = teacher = topic = NULL;
	dateAndTimeAdded = length = 0;
} 
