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
		device * curr = head;
		device * next = NULL;
		while(curr != NULL)
		{
			next = curr->to_next();
			delete curr;
			curr = next;
		}
	}
	head = NULL;
}

int deviceList::length()
{
	device * curr = head;
	int size = 0;
	while(curr)
	{
		size++;
		curr = curr->to_next();
	}
	return size;
}

int deviceList::add(const device & new_device) //EOL
{
	device * temp = new device;
	if(!temp) return 0;
	temp->add(new_device);	
	temp->to_next() = NULL;

		int pos = this->length();
		int count = 0;
		device * curr = head;
		device * prev = NULL;
		while(curr && (count < pos))
		{
			prev = curr;
			curr = curr->to_next();
			count++;	
		}
		if (prev == NULL) //if the list is empty
		{
			temp->to_next() = head;	
			head = temp;
		}
		else if (curr == NULL)
		{
			prev->to_next() = temp;
		} 
		else				//put it between prev and curr
		{
			temp->to_next() = curr;
			prev->to_next() = temp;
		}
	return 1;
}

int deviceList::add(char * devicename) //EOL
{
	device * temp = new device;
	if(!temp) return 0;
	temp->add(devicename);	
	temp->to_next() = NULL;

		int pos = this->length();
		int count = 0;
		device * curr = head;
		device * prev = NULL;
		while(curr && (count < pos))
		{
			prev = curr;
			curr = curr->to_next();
			count++;	
		}
		if (prev == NULL) //if the list is empty
		{
			temp->to_next() = head;	
			head = temp;
		}
		else if (curr == NULL)
		{
			prev->to_next() = temp;
		} 
		else				//put it between prev and curr
		{
			temp->to_next() = curr;
			prev->to_next() = temp;
		}
	return 1;
}
int deviceList::displayAll()
{
	if(!head) return 1;	
	device * curr = head;
	while(curr)
	{
		curr->display();
		curr = curr->to_next();
	}
	return 1;
}

//carefulu with this bb
device * deviceList::find(device * target)
{
	device * curr = head;
	while(curr != NULL)
	{
		if(curr->get_data() == target->get_data())
		{
		return curr;	
		}
		curr = curr->to_next();	
	}
	return  curr;
}

int deviceList::remove(int pos)
{
	if(pos < 0 || pos >= this->length()) return 0; //guard against bad pos inputs
	device * prev = NULL;
	device * curr = head;

	if(pos == 0) 
	{
		curr = head;
		head = head->to_next();
		delete curr;
	}
	else
	{
		int count = 0;
		curr = head;
		while(count < pos)
		{
			prev = curr;
			curr = curr->to_next();
			count++;
		}
		prev->to_next() = curr->to_next();
		delete curr;
	}
	return 0;
}

int deviceList::remove(const device & target_device)
{
	device * curr = head;
	int pos = 0;	
	while(curr)
	{
		if(curr->compare(target_device))
		{
		remove(pos);
		}
		pos++;		
		curr = curr->to_next();
	}
	return 0;
}
