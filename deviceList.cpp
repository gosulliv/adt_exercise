//This is the implementation of the constructor, destructor, add, and remove functions specific to the linear linked list of video devices that are housed within the video class.
#include "deviceList.h"

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
	temp->next = NULL:

	if(!head)
	{
		head = temp;
	}
	else
	{
		//EOL insert hrmm
	}

}

//int deviceList::remove(const device & target_device){}
//int deviceList::displayAll(){}
