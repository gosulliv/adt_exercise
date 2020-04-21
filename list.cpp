#include "list.h"
list::list()
{
	head = NULL; //statement Has no effect?
}

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

int list::addVideo(int timeStamp, char videoName[], char teacher[], char topic[], int length)
{
	if(!videoName || !teacher || !topic) return 0;
	node * new_video = new node;
	new_video->a_video.add(timeStamp, videoName, teacher, topic, length);
	new_video->next = NULL;

	//then insert it into the list ordered insertion style
	return 1;
}


int list::displayVideos()
{
	node * curr = head;
	while(curr)
	{
		curr->a_video.display();	
		curr = curr->next;
	}
	return 1;
}

int list::displayDevices(const video & target_vid)
{
	node * curr = head;
	while(curr)
	{
		if(curr->a_video.compareVideo(target_vid))
		{
			curr->a_video.displayAll_Devices();
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

