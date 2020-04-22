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

int list::addDevice(char * deviceName_toAdd, char * videoName) //add a device to  video in the list
{
	node * curr = head;
	while(curr)
	{
		if(curr->a_video.compareVideo(videoName)) //if matching videonames
		{
			curr->a_video.addDevice(deviceName_toAdd);
		}
		curr = curr->next;
	}	
	return 1;
}

int list::addDevice(const device & target_device, char * videoName)
{
	node * curr = head;
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

int list::removeDevice(device & target_device, char * videoName)
{
	node * curr = head;
	while(curr)
	{
		if(curr->a_video.compareVideo(videoName))
		{
			curr->a_video.removeDevice(target_device);
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

int list::removeDevice(char * deviceName, char * videoName)
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

//int list::posInsert(int pos, node * target)
//{
//	if(pos < 0) pos = 0;
//	//if(pos > this->length()) pos = this->length();
//	node * curr = head;
//	node * prev = NULL;
//	int size = 0;
//	while(curr && (size < pos))
//	{
//		prev = curr;
//		size++;
//		curr = curr->next;
//	}
//	if(prev == NULL)				//if we're at the very top	
//	{
//		target->next = head;
//		head = target;
//	}
//	else if (curr == NULL)			//if we're at the very bottom
//	{
//		prev->next = target;  //i'm not sure if targ
//	}
//	else
//	{
//		target->next = curr; 
//		prev->next = target;
//	}
//	return 1;
//}

int list::addVideo(int timeStamp, char videoName[], char teacher[], char topic[], int length)
{
	if(!videoName || !teacher || !topic) return 0;
	node * new_node = new node;
	new_node->a_video.add(timeStamp, videoName, teacher, topic, length);
	new_node->next = NULL;

	//find the right position to add into
	node * curr = head; //what if list is empty1?
	node * prev = NULL;	
	if(!curr) //if the list is empty
	{
		head = new_node;
	}
	else //if the list is not empty? 
	{
		while(curr) //y u no work
		{
			if(curr->a_video.compareTime(new_node->a_video)) //if curr's time > new_video's jk]]?
			{
				if(prev == NULL)
				{
					new_node->next = head;
					head = new_node;
				}
				else
				{
					new_node->next = curr;
					prev->next = new_node;
				}
				return 1;
			}
			prev = curr;	
			curr = curr->next;
		}
	}//should we have a gurad case for full?	
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

int list::displayDevices(char * videoName)
{
	node * curr = head;
	while(curr)
	{
		if(curr->a_video.compareVideo(videoName))
		{
			curr->a_video.displayAll_Devices();
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

