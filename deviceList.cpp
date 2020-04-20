#include "deviceList.h"


//This is the implementation of the constructor, destructor, add, and remove functions specific to the linear linked list of video devices that are housed within the video class.

deviceList::deviceList()
{
	head = NULL; 
}

deviceList::~deviceList()
{
	if(this->head != NULL)
	{
		deviceNode * curr = head;
		deviceNode * next = NULL;
		while(curr != NULL)
		{
			next = curr->next;
			delete curr;
			curr = next;
		}
	}
	head = NULL;
}

int deviceList::length()
{
	deviceNode * curr = head;
	int size = 0;
	while(curr)
	{
		size++;
		curr = curr->next;
	}
	return size;
}

int deviceList::add(const device & new_device) //EOL
{
	deviceNode * temp = new deviceNode;
	if(!temp) return 0;
	temp->deviceData.add(new_device);
	temp->next = NULL;

		int pos = this->length();
		int count = 0;
		deviceNode * curr = head;
		deviceNode * prev = NULL;
		while(curr && (count < pos))
		{
			prev = curr;
			curr = curr->next;
			count++;	
		}
		if (prev == NULL) //if the list is empty
		{
			temp->next = head;	
			head = temp;
		}
		else if (curr == NULL)
		{
			prev->next = temp;
		} 
		else				//put it between prev and curr
		{
			temp->next = curr;
			prev->next = temp;
		}
	return 1;
}

int deviceList::displayAll()
{
	if(!head) return 1;	
	deviceNode * curr = head;
	while(curr)
	{
		curr->deviceData.display();
		curr = curr->next;
	}
	return 1;
}

//int deviceList::remove(const device & target_device)
//{
//	deviceNode * temp = new deviceNode;
//	temp->deviceData.add(target_device);
//	temp->next = NULL;
//
//	deviceNode * curr = head;
//	while(curr)
//	{
//		//how do we compare stuff
//	//	if(curr->deviceData.display());
//	}
//}
