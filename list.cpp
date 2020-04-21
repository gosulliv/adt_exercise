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

int list::posInsert(int pos, node * target)
{
	if(pos < 0) pos = 0;
	//if(pos > this->length()) pos = this->length();
	node * curr = head;
	node * prev = NULL;
	int size = 0;
	while(curr && (size < pos))
	{
		prev = curr;
		size++;
		curr = curr->next;
	}
	if(prev == NULL)				//if we're at the very top	
	{
		target->next = head;
		head = target;
	}
	else if (curr == NULL)			//if we're at the very bottom
	{
		prev->next = target;  //i'm not sure if targ
	}
	else
	{
		target->next = curr; 
		prev->next = target;
	}
	return 1;
}
//either the one above or below is borken.
//either we're not adding to the list with addvideo+posInsert successfully or our display is borked
//i'm pretty sure our display is fine, but that still needs tests
int list::addVideo(int timeStamp, char videoName[], char teacher[], char topic[], int length)
{
	if(!videoName || !teacher || !topic) return 0;
	node * new_node = new node;
	new_node->a_video.add(timeStamp, videoName, teacher, topic, length);
	new_node->next = NULL;

	//find the right position to add into
	node * curr = head; //what if list is empty1?
	int pos = 0;
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
			posInsert(pos, new_node);	
			}
			pos++;
			curr = curr->next;
		}
	}//should we have a gurad case for full?	
	return 1;
}

//I doubt the one below is relevant bc users aren't handling video objes directly
//int list::addVideo(const video & vid_toAdd) //this is the node taking version of the one above
//{
//	//if(!vid_toAdd.videoName || !a_video.teacher || !a_video.topic) return 0;
//	node * new_node = new node;
//	new_node->a_video.add(vid_toAdd.timeStamp, vid_toAdd.videoName, vid_toAdd.teacher, vid_toAdd.topic, vid_toAdd.length);
//
//	node * curr = head;
//	int pos = 0;
//	while (curr)
//	{
//		if(curr->a_video.compareTime(new_node->a_video))
//		{
//			posInsert(pos, new_node);
//		}
//		pos++;
//		curr = curr->next;
//	}
//	return 1;
//}

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

