//This is the implementation of the constructor, destructor, add, and remove functions specific to the linear linked list of video devices that are housed within the video class.
#include "device.h"

videoDevice::videoDevice()
{
	head = NULL; 
}

videoDevice::~videoDevice()
{
	if(this->head != NULL)
	{
		device * curr = head;
		device * next = NULL;
		while(curr != NULL)
		{
			next = curr->next;
			delete curr;
			curr = next;
		}
	}
}
